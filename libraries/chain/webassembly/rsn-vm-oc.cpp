#include <arisen/chain/webassembly/rsn-vm-oc.hpp>
#include <arisen/chain/wasm_arisen_constraints.hpp>
#include <arisen/chain/wasm_arisen_injection.hpp>
#include <arisen/chain/apply_context.hpp>
#include <arisen/chain/exceptions.hpp>

#include <vector>
#include <iterator>

namespace arisen { namespace chain { namespace webassembly { namespace rsnvmoc {

class rsnvmoc_instantiated_module : public wasm_instantiated_module_interface {
   public:
      rsnvmoc_instantiated_module(const digest_type& code_hash, const uint8_t& vm_version, rsnvmoc_runtime& wr) :
         _code_hash(code_hash),
         _vm_version(vm_version),
         _rsnvmoc_runtime(wr)
      {

      }

      ~rsnvmoc_instantiated_module() {
         _rsnvmoc_runtime.cc.free_code(_code_hash, _vm_version);
      }

      void apply(apply_context& context) override {
         const code_descriptor* const cd = _rsnvmoc_runtime.cc.get_descriptor_for_code_sync(_code_hash, _vm_version);
         RSN_ASSERT(cd, wasm_execution_error, "RSN VM OC instantiation failed");

         _rsnvmoc_runtime.exec.execute(*cd, _rsnvmoc_runtime.mem, context);
      }

      const digest_type              _code_hash;
      const uint8_t                  _vm_version;
      rsnvmoc_runtime&               _rsnvmoc_runtime;
};

rsnvmoc_runtime::rsnvmoc_runtime(const boost::filesystem::path data_dir, const rsnvmoc::config& rsnvmoc_config, const chainbase::database& db)
   : cc(data_dir, rsnvmoc_config, db), exec(cc) {
}

rsnvmoc_runtime::~rsnvmoc_runtime() {
}

std::unique_ptr<wasm_instantiated_module_interface> rsnvmoc_runtime::instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t> initial_memory,
                                                                                     const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) {

   return std::make_unique<rsnvmoc_instantiated_module>(code_hash, vm_type, *this);
}

//never called. RSN VM OC overrides arisen_exit to its own implementation
void rsnvmoc_runtime::immediately_exit_currently_running_module() {}

}}}}
