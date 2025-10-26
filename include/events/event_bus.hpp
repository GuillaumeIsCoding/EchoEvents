#pragma once
#ifndef ECHO_EVENTS_EVENT_BUS_HPP
#define ECHO_EVENTS_EVENT_BUS_HPP

#include "events/macros/export.hpp"

#include "events/interfaces/ievent_bus.hpp"

#include <mutex>

#include <deque>

#include <memory>

#include <vector>

namespace echo::events
{

class ECHO_EVENTS_EXPORT EventBus : interfaces::IEventBus
{
  public:
    ~EventBus() override = default;

    EventBus(bool allow_multiple_observer = true);

    virtual void attach(
        const std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>> &observer)
        override;

    virtual void detach(
        const std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>> &observer)
        override;

    virtual void add(const std::shared_ptr<interfaces::IEvent> &event) override;
    virtual void add(const std::vector<std::shared_ptr<interfaces::IEvent>> &events) override;

    virtual void notify() override;

    virtual std::vector<std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>>>
    get() const override;

  private:
    bool m_allow_multiple_observer;

    std::vector<std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>>>
        m_observers;

    std::deque<std::shared_ptr<interfaces::IEvent>> m_events;

    std::mutex m_observer_mutex;
    std::mutex m_events_mutex;
};

} // namespace echo::events

#endif // ECHO_EVENTS_EVENT_BUS_HPP