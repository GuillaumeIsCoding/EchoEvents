#pragma once
#ifndef ECHO_EVENTS_IEVENT_OBSERVER_HPP
#define ECHO_EVENTS_IEVENT_OBSERVER_HPP

#include "events/macros/export.hpp"

#include "events/interfaces/ievent.hpp"

#include "events/event_type.hpp"

#include "events/event_category.hpp"

#include <core/interfaces/patterns/observer.hpp>

#include <types.hpp>

#include <memory>

namespace echo::events::interfaces
{

class ECHO_EVENTS_EXPORT IEventObserver : core::interfaces::patterns::IObserver<std::shared_ptr<IEvent>>
{
  public:
    inline virtual ~IEventObserver() = 0;

    inline virtual EventType get_event_type() const = 0;

    inline virtual uint32 get_category_flags() const = 0;
};

IEventObserver::~IEventObserver() = default;

} // namespace echo::events::interfaces

#endif // ECHO_EVENTS_IEVENT_OBSERVER_HPP