#include "events/mouse_event.hpp"

namespace echo::events
{

MouseMovedEvent::MouseMovedEvent(const float x, const float y) : m_x(x), m_y(y)
{
}

float MouseMovedEvent::get_x() const
{
    return m_x;
}

float MouseMovedEvent::get_y() const
{
    return m_y;
}

std::string MouseMovedEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_x << ", " << m_y;
    return ss.str();
}

MouseScrolledEvent::MouseScrolledEvent(const float x_offset, const float y_offset)
    : m_x_offset(x_offset), m_y_offset(y_offset)
{
}

float MouseScrolledEvent::get_x_offset() const
{
    return m_x_offset;
}

float MouseScrolledEvent::get_y_offset() const
{
    return m_y_offset;
}

std::string MouseScrolledEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_x_offset << ", " << m_y_offset;
    return ss.str();
}

MouseButtonEvent::MouseButtonEvent(const core::MouseCode mouse_code) : m_mouse_code(mouse_code)
{
}

core::MouseCode MouseButtonEvent::get_mouse_code() const
{
    return m_mouse_code;
}

MouseButtonPressedEvent::MouseButtonPressedEvent(const core::MouseCode mouse_code) : MouseButtonEvent(mouse_code)
{
}

std::string MouseButtonPressedEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_mouse_code;
    return ss.str();
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(const core::MouseCode mouse_code) : MouseButtonEvent(mouse_code)
{
}

std::string MouseButtonReleasedEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_mouse_code;
    return ss.str();
}

} // namespace echo::events
