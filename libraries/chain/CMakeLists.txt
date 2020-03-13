configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/arisen/chain/core_symbol.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/arisen/chain/core_symbol.hpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/genesis_state_root_key.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp)

file(GLOB HEADERS "include/arisen/chain/*.hpp"
                  "include/arisen/chain/webassembly/*.hpp"
                  "${CMAKE_CURRENT_BINARY_DIR}/include/arisen/chain/core_symbol.hpp" )

if(APPLE AND UNIX)
   set(PLATFORM_TIMER_IMPL platform_timer_macos.cpp)
else()
   try_run(POSIX_TIMER_TEST_RUN_RESULT POSIX_TIMER_TEST_COMPILE_RESULT ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/platform_timer_posix_test.c)
   if(POSIX_TIMER_TEST_RUN_RESULT EQUAL 0)
      set(PLATFORM_TIMER_IMPL platform_timer_posix.cpp)
   else()
      set(PLATFORM_TIMER_IMPL platform_timer_asio_fallback.cpp)
   endif()
endif()

if("rsn-vm-oc" IN_LIST ARISEN_WASM_RUNTIMES)
   set(CHAIN_RSNVMOC_SOURCES webassembly/rsn-vm-oc/code_cache.cpp
                             webassembly/rsn-vm-oc/executor.cpp
                             webassembly/rsn-vm-oc/memory.cpp
                             webassembly/rsn-vm-oc/intrinsic.cpp
                             webassembly/rsn-vm-oc/LLVMJIT.cpp
                             webassembly/rsn-vm-oc/LLVMEmitIR.cpp
                             webassembly/rsn-vm-oc/compile_monitor.cpp
                             webassembly/rsn-vm-oc/compile_trampoline.cpp
                             webassembly/rsn-vm-oc/ipc_helpers.cpp
                             webassembly/rsn-vm-oc/gs_seg_helpers.c
                             webassembly/rsn-vm-oc.cpp)

   if(LLVM_VERSION VERSION_LESS 7.1 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
      enable_language(ASM-LLVMWAR)
      list(APPEND CHAIN_RSNVMOC_SOURCES webassembly/rsn-vm-oc/llvmWARshim.llvmwar)
   else()
      list(APPEND CHAIN_RSNVMOC_SOURCES webassembly/rsn-vm-oc/llvmWARshim.cpp)
   endif()

   llvm_map_components_to_libnames(LLVM_LIBS support core passes mcjit native orcjit)
   include_directories(${LLVM_INCLUDE_DIRS})
   add_definitions(${LLVM_DEFINITIONS})

   option(RSNVMOC_ENABLE_DEVELOPER_OPTIONS "enable developer options for RSN VM OC" OFF)
endif()

if("rsn-vm" IN_LIST ARISEN_WASM_RUNTIMES OR "rsn-vm-jit" IN_LIST ARISEN_WASM_RUNTIMES)
   set(CHAIN_RSNVM_SOURCES "webassembly/rsn-vm.cpp")
   set(CHAIN_RSNVM_LIBRARIES rsn-vm)
endif()

## SORT .cpp by most likely to change / break compile
add_library( arisen_chain
             merkle.cpp
             name.cpp
             transaction.cpp
             block.cpp
             block_header.cpp
             block_header_state.cpp
             block_state.cpp
             fork_database.cpp
             controller.cpp
             authorization_manager.cpp
             resource_limits.cpp
             block_log.cpp
             transaction_context.cpp
             arisen_contract.cpp
             arisen_contract_abi.cpp
             arisen_contract_abi_bin.cpp
             chain_config.cpp
             chain_id_type.cpp
             genesis_state.cpp
             ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp

#             chain_config.cpp
#             block_trace.cpp
              wast_to_wasm.cpp
              wasm_interface.cpp
              wasm_arisen_validation.cpp
              wasm_arisen_injection.cpp
              apply_context.cpp
              abi_serializer.cpp
              asset.cpp
              snapshot.cpp

             webassembly/wabt.cpp
             ${CHAIN_RSNVMOC_SOURCES}
             ${CHAIN_RSNVM_SOURCES}

#             get_config.cpp
#
#             contracts/chain_initializer.cpp

             trace.cpp
             transaction_metadata.cpp
             protocol_state_object.cpp
             protocol_feature_activation.cpp
             protocol_feature_manager.cpp
             producer_schedule.cpp
             genesis_intrinsics.cpp
             whitelisted_intrinsics.cpp
             thread_utils.cpp
             platform_timer_accuracy.cpp
             ${PLATFORM_TIMER_IMPL}
             ${HEADERS}
             )

target_link_libraries( arisen_chain fc chainbase Logging IR WAST WASM Runtime
                       softfloat builtins wabt ${CHAIN_RSNVM_LIBRARIES} ${LLVM_LIBS}
                     )
target_include_directories( arisen_chain
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include"
                                   "${CMAKE_CURRENT_SOURCE_DIR}/../wasm-jit/Include"
                                   "${CMAKE_CURRENT_SOURCE_DIR}/libraries/rsn-vm/include"
                                   "${CMAKE_SOURCE_DIR}/libraries/wabt"
                                   "${CMAKE_BINARY_DIR}/libraries/wabt"
                            )

if("rsn-vm-oc" IN_LIST ARISEN_WASM_RUNTIMES)
   target_link_libraries(arisen_chain "-Wl,-wrap=main")
endif()

foreach(RUNTIME ${ARISEN_WASM_RUNTIMES})
   string(TOUPPER "${RUNTIME}" RUNTIMEUC)
   string(REPLACE "-" "_" RUNTIMEUC ${RUNTIMEUC})
   target_compile_definitions(arisen_chain PUBLIC "ARISEN_${RUNTIMEUC}_RUNTIME_ENABLED")
endforeach()

if(RSNVMOC_ENABLE_DEVELOPER_OPTIONS)
   message(WARNING "RSN VM OC Developer Options are enabled; these are NOT supported")
   target_compile_definitions(arisen_chain PUBLIC ARISEN_RSN_VM_OC_DEVELOPER)
endif()

install( TARGETS arisen_chain
   RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
   LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/arisen/chain/
      DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/arisen/chain
      FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h" EXCLUDE
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/arisen/chain/core_symbol.hpp DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/arisen/chain)
#if(MSVC)
#  set_source_files_properties( db_init.cpp db_block.cpp database.cpp block_log.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
#endif(MSVC)
