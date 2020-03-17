#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] ram_restrictions_test : public arisen::contract {
public:
   struct [[arisen::table]] data {
      uint64_t           key;
      std::vector<char>  value;

      uint64_t primary_key() const { return key; }
   };

   typedef arisen::multi_index<"tablea"_n, data> tablea;
   typedef arisen::multi_index<"tableb"_n, data> tableb;

public:
   using arisen::contract::contract;

   [[arisen::action]]
   void noop();

   [[arisen::action]]
   void setdata( uint32_t len1, uint32_t len2, arisen::name payer );

   [[arisen::action]]
   void notifysetdat( arisen::name acctonotify, uint32_t len1, uint32_t len2, arisen::name payer );

   [[arisen::on_notify("tester2::notifysetdat")]]
   void on_notify_setdata( arisen::name acctonotify, uint32_t len1, uint32_t len2, arisen::name payer );

   [[arisen::action]]
   void senddefer( uint64_t senderid, arisen::name payer );

   [[arisen::action]]
   void notifydefer( arisen::name acctonotify, uint64_t senderid, arisen::name payer );

   [[arisen::on_notify("tester2::notifydefer")]]
   void on_notifydefer( arisen::name acctonotify, uint64_t senderid, arisen::name payer );

};
