#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] test_api_db : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action("pg")]]
   void primary_i64_general();

   [[arisen::action("pl")]]
   void primary_i64_lowerbound();

   [[arisen::action("pu")]]
   void primary_i64_upperbound();

   [[arisen::action("s1g")]]
   void idx64_general();

   [[arisen::action("s1l")]]
   void idx64_lowerbound();

   [[arisen::action("s1u")]]
   void idx64_upperbound();

   [[arisen::action("tia")]]
   void test_invalid_access( arisen::name code, uint64_t val, uint32_t index, bool store );

   [[arisen::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[arisen::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[arisen::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[arisen::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};
