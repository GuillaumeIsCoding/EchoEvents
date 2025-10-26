#include "events/event_bus.hpp"

#include <algorithm>

namespace echo::events
{

EventBus::EventBus(bool allow_multiple_observer) : m_allow_multiple_observer(allow_multiple_observer)
{
}

void EventBus::attach(
    const std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>> &observer)
{
    auto lock = std::lock_guard<std::mutex>(m_observer_mutex);

    if (m_allow_multiple_observer || m_observers.empty())
    {
        if (std::find(m_observers.begin(), m_observers.end(), observer) == m_observers.end())
        {
            m_observers.push_back(observer);
        }
    }
}

void EventBus::detach(
    const std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>> &observer)
{
    auto lock = std::lock_guard<std::mutex>(m_observer_mutex);

    auto it = std::find(m_observers.begin(), m_observers.end(), observer);

    if (it != m_observers.end())
    {
        m_observers.erase(it);
    }
}

void EventBus::add(const std::shared_ptr<interfaces::IEvent> &event)
{
    auto lock = std::lock_guard<std::mutex>(m_events_mutex);

    m_events.push_back(event);
}

void EventBus::add(const std::vector<std::shared_ptr<interfaces::IEvent>> &events)
{
    auto lock = std::lock_guard<std::mutex>(m_events_mutex);

    m_events.insert(m_events.end(), events.begin(), events.end());
}

void EventBus::notify()
{
    std::deque<std::shared_ptr<interfaces::IEvent>> events;

    {
        auto lock = std::lock_guard<std::mutex>(m_events_mutex);

        events = std::move(m_events);
    }

    while (!events.empty())
    {
        auto event = events.front();
        events.pop_front();

        std::vector<std::weak_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>>> snapshot;

        // makes the notification thread-safe
        {
            auto lock = std::lock_guard<std::mutex>(m_observer_mutex);

            for (auto &observer : m_observers)
            {
                snapshot.push_back(observer);
            }
        }

        for (auto &weak_observer : snapshot)
        {
            if (auto observer = weak_observer.lock())
            {
                observer->update(event);
            }
        }
    }
}

std::vector<std::shared_ptr<core::interfaces::patterns::IObserver<std::shared_ptr<interfaces::IEvent>>>> EventBus::get()
    const
{
    return m_observers;
}

} // namespace echo::events
