#pragma once
#ifndef ECHO_EVENTS_IEVENT_DISPATCHER_HPP
#define ECHO_EVENTS_IEVENT_DISPATCHER_HPP

#include "events/macros/export.hpp"

namespace echo::events::interfaces
{

class ECHO_EVENTS_EXPORT IEventDispatcher
{
  public:
    inline virtual ~IEventDispatcher() = 0;
};

IEventDispatcher::~IEventDispatcher() = default;

} // namespace echo::events::interfaces

#endif // ECHO_EVENTS_IEVENT_DISPATCHER_HPP