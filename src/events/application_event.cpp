#include "events/application_event.hpp"

namespace echo::events
{

WindowResizeEvent::WindowResizeEvent(const uint32 &width, const uint32 &height) : m_width(width), m_height(height)
{
}

uint32 WindowResizeEvent::get_width() const
{
    return m_width;
}

uint32 WindowResizeEvent::get_height() const
{
    return m_height;
}

std::string WindowResizeEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_width << ", " << m_height;
    return ss.str();
}

} // namespace echo::events
