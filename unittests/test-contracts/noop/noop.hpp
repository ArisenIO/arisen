#pragma once

#include <arisen/arisen.hpp>

class [[arisen::contract]] noop : public arisen::contract {
public:
   using arisen::contract::contract;

   [[arisen::action]]
   void anyaction( arisen::name                       from,
                   const arisen::ignore<std::string>& type,
                   const arisen::ignore<std::string>& data );
};
