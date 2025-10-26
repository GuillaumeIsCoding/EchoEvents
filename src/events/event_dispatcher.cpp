#include "events/event_dispatcher.hpp"

namespace echo::events
{

EventDispatcher::EventDispatcher(interfaces::IEvent &event) : m_event(event)
{
}

} // namespace echo::events
