#pragma once

#include <arisen/chain/webassembly/rsn-vm-oc/config.hpp>

#include <boost/asio/local/datagram_protocol.hpp>
#include <arisen/chain/webassembly/rsn-vm-oc/ipc_helpers.hpp>

namespace arisen { namespace chain { namespace rsnvmoc {

wrapped_fd get_connection_to_compile_monitor(int cache_fd);

}}}