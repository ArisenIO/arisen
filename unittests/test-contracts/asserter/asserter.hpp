#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] asserter : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void procassert( int8_t condition, std::string message );

   [[arisen::action]]
   void provereset();
};
