#pragma once
#include <fc/variant.hpp>
#include <arisen/trace_api/trace.hpp>
#include <arisen/chain/abi_def.hpp>
#include <arisen/chain/protocol_feature_activation.hpp>

namespace arisen { namespace trace_api {

   using data_log_entry = fc::static_variant<
      block_trace_v0
   >;

}}
