#include "events/abs_event.hpp"

namespace echo::events
{

std::string AbsEvent::to_string() const
{
    return get_name();
}

bool AbsEvent::is_in_category(EventCategory category) const
{
    return get_category_flags() & category;
}

bool AbsEvent::has_been_handled() const
{
    return m_handled;
}

void AbsEvent::update_status(bool status)
{
    m_handled |= status;
}

} // namespace echo::events
