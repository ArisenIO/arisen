#pragma once

#include <arisen/arisen.hpp>
#include <vector>

class [[arisen::contract]] deferred_test : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void defercall( arisen::name payer, uint64_t sender_id, arisen::name contract, uint64_t payload );

   [[arisen::action]]
   void delayedcall( arisen::name payer, uint64_t sender_id, arisen::name contract,
                     uint64_t payload, uint32_t delay_sec, bool replace_existing );

   [[arisen::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = arisen::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[arisen::action]]
   void inlinecall( arisen::name contract, arisen::name authorizer, uint64_t payload );

   [[arisen::action]]
   void fail();

   [[arisen::on_notify("arisen::onerror")]]
   void on_error( uint128_t sender_id, arisen::ignore<std::vector<char>> sent_trx );
};
