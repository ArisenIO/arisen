#pragma once

#include <arisen/arisen.hpp>
#include <arisen/singleton.hpp>
#include <arisen/asset.hpp>

// Extacted from arisen.token contract:
namespace arisen {
   class [[arisen::contract("arisen.token")]] token : public arisen::contract {
   public:
      using arisen::contract::contract;

      [[arisen::action]]
      void transfer( arisen::name        from,
                     arisen::name        to,
                     arisen::asset       quantity,
                     const std::string& memo );
      using transfer_action = arisen::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[arisen::contract]] proxy : public arisen::contract {
public:
   proxy( arisen::name self, arisen::name first_receiver, arisen::datastream<const char*> ds );

   [[arisen::action]]
   void setowner( arisen::name owner, uint32_t delay );

   [[arisen::on_notify("arisen.token::transfer")]]
   void on_transfer( arisen::name        from,
                     arisen::name        to,
                     arisen::asset       quantity,
                     const std::string& memo );

   [[arisen::on_notify("arisen::onerror")]]
   void on_error( uint128_t sender_id, arisen::ignore<std::vector<char>> sent_trx );

   struct [[arisen::table]] config {
      arisen::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      RSNLIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = arisen::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};
