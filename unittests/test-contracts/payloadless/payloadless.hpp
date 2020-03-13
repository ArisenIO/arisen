#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] payloadless : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void doit();
};
