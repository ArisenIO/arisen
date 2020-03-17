#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] test_api_multi_index : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action("s1g")]]
   void idx64_general();

   [[arisen::action("s1store")]]
   void idx64_store_only();

   [[arisen::action("s1check")]]
   void idx64_check_without_storing();

   [[arisen::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[arisen::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[arisen::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[arisen::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[arisen::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[arisen::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[arisen::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[arisen::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[arisen::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[arisen::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[arisen::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[arisen::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[arisen::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[arisen::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[arisen::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[arisen::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[arisen::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[arisen::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[arisen::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[arisen::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[arisen::action("s2g")]]
   void idx128_general();

   [[arisen::action("s2store")]]
   void idx128_store_only();

   [[arisen::action("s2check")]]
   void idx128_check_without_storing();

   [[arisen::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[arisen::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[arisen::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[arisen::action("s3g")]]
   void idx256_general();

   [[arisen::action("sdg")]]
   void idx_double_general();

   [[arisen::action("sldg")]]
   void idx_long_double_general();

};
