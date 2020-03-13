#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] snapshot_test : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void increment( uint32_t value );

   struct [[arisen::table("data")]] main_record {
      uint64_t           id         = 0;
      double             index_f64  = 0.0;
      long double        index_f128 = 0.0L;
      uint64_t           index_i64  = 0ULL;
      uint128_t          index_i128 = 0ULL;
      arisen::checksum256 index_i256;

      uint64_t                  primary_key()const    { return id; }
      double                    get_index_f64()const  { return index_f64 ; }
      long double               get_index_f128()const { return index_f128; }
      uint64_t                  get_index_i64()const  { return index_i64 ; }
      uint128_t                 get_index_i128()const { return index_i128; }
      const arisen::checksum256& get_index_i256()const { return index_i256; }

      EOSLIB_SERIALIZE( main_record, (id)(index_f64)(index_f128)(index_i64)(index_i128)(index_i256) )
   };

   using data_table = arisen::multi_index<"data"_n, main_record,
      arisen::indexed_by< "byf"_n,    arisen::const_mem_fun< main_record, double,
                                                           &main_record::get_index_f64 > >,
      arisen::indexed_by< "byff"_n,   arisen::const_mem_fun< main_record, long double,
                                                           &main_record::get_index_f128> >,
      arisen::indexed_by< "byi"_n,    arisen::const_mem_fun< main_record, uint64_t,
                                                           &main_record::get_index_i64 > >,
      arisen::indexed_by< "byii"_n,   arisen::const_mem_fun< main_record, uint128_t,
                                                           &main_record::get_index_i128 > >,
      arisen::indexed_by< "byiiii"_n, arisen::const_mem_fun< main_record, const arisen::checksum256&,
                                                           &main_record::get_index_i256 > >
   >;
};
