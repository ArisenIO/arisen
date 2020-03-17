#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] restrict_action_test : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void noop( );

   [[arisen::action]]
   void sendinline( arisen::name authorizer );

   [[arisen::action]]
   void senddefer( arisen::name authorizer, uint32_t senderid );


   [[arisen::action]]
   void notifyinline( arisen::name acctonotify, arisen::name authorizer );

   [[arisen::action]]
   void notifydefer( arisen::name acctonotify, arisen::name authorizer, uint32_t senderid );

   [[arisen::on_notify("testacc::notifyinline")]]
   void on_notify_inline( arisen::name acctonotify, arisen::name authorizer );

   [[arisen::on_notify("testacc::notifydefer")]]
   void on_notify_defer( arisen::name acctonotify, arisen::name authorizer, uint32_t senderid );
};
