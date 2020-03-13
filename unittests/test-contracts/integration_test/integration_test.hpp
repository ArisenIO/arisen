#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] integration_test : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void store( arisen::name from, arisen::name to, uint64_t num );

   struct [[arisen::table("payloads")]] payload {
      uint64_t              key;
      std::vector<uint64_t> data;

      uint64_t primary_key()const { return key; }

      RSNLIB_SERIALIZE( payload, (key)(data) )
   };

   using payloads_table = arisen::multi_index< "payloads"_n,  payload >;

};
