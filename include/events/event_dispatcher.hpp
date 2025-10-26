#pragma once
#ifndef ECHO_EVENTS_EVENT_DISPATCHER_HPP
#define ECHO_EVENTS_EVENT_DISPATCHER_HPP

#include "events/macros/export.hpp"

#include "events/interfaces/ievent_dispatcher.hpp"

#include "events/interfaces/ievent.hpp"

namespace echo::events
{

class ECHO_EVENTS_EXPORT EventDispatcher : public interfaces::IEventDispatcher
{
  public:
    EventDispatcher(interfaces::IEvent &event);

    template <typename T, typename F> inline bool dispatch(const F &func);

  protected:
    interfaces::IEvent &m_event;
};

template <typename T, typename F> bool EventDispatcher::dispatch(const F &func)
{
    if (m_event.get_event_type() == T::get_static_type())
    {
        m_event.update_status(func(static_cast<T &>(m_event)));

        return true;
    }

    return false;
}

} // namespace echo::events

#endif // ECHO_EVENTS_EVENT_DISPATCHER_HPP