#pragma once

#include <arisen/arisen.hpp>

namespace arisen {
   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((arisen_wasm_import))
         uint64_t get_sender();
      }
   }
}

namespace arisen {
   name get_sender() {
      return name( internal_use_do_not_use::get_sender() );
   }
}

class [[arisen::contract]] get_sender_test : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void assertsender( arisen::name expected_sender );
   using assertsender_action = arisen::action_wrapper<"assertsender"_n, &get_sender_test::assertsender>;

   [[arisen::action]]
   void sendinline( arisen::name to, arisen::name expected_sender );

   [[arisen::action]]
   void notify( arisen::name to, arisen::name expected_sender, bool send_inline );

   // arisen.cdt 1.6.1 has a problem with "*::notify" so hardcode to tester1 for now.
   // TODO: Change it back to "*::notify" when the bug is fixed in arisen.cdt.
   [[arisen::on_notify("tester1::notify")]]
   void on_notify( arisen::name to, arisen::name expected_sender, bool send_inline );

};
