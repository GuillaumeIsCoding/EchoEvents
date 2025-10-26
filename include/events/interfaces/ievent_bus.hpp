#pragma once
#ifndef ECHO_EVENTS_IEVENT_BUS_HPP
#define ECHO_EVENTS_IEVENT_BUS_HPP

#include "events/macros/export.hpp"

#include "events/interfaces/ievent.hpp"

#include <core/interfaces/patterns/observer.hpp>

#include <memory>

#include <vector>

namespace echo::events::interfaces
{

class ECHO_EVENTS_EXPORT IEventBus : core::interfaces::patterns::ISubject<std::shared_ptr<IEvent>>
{
  public:
    inline virtual ~IEventBus() override = 0;

    inline virtual void add(const std::shared_ptr<IEvent> &event) = 0;
    inline virtual void add(const std::vector<std::shared_ptr<IEvent>> &events) = 0;

    inline virtual std::vector<
        std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>>>
    get() const = 0;
};

IEventBus::~IEventBus() = default;

} // namespace echo::events::interfaces

#endif // ECHO_EVENTS_IEVENT_BUS_HPP