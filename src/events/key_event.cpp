#include "events/key_event.hpp"

namespace echo::events
{

KeyEvent::KeyEvent(const core::KeyCode key_code) : m_key_code(key_code)
{
}

core::KeyCode KeyEvent::get_key_code() const
{
    return m_key_code;
}

KeyPressedEvent::KeyPressedEvent(const core::KeyCode key_code, bool is_repeated)
    : KeyEvent(key_code), m_is_repeated(is_repeated)
{
}

bool KeyPressedEvent::is_repeated() const
{
    return m_is_repeated;
}

std::string KeyPressedEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_key_code << " (repeat = " << m_is_repeated << ")";
    return ss.str();
}

KeyReleasedEvent::KeyReleasedEvent(const core::KeyCode key_code) : KeyEvent(key_code)
{
}

std::string KeyReleasedEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_key_code;
    return ss.str();
}

KeyTypedEvent::KeyTypedEvent(const core::KeyCode key_code) : KeyEvent(key_code)
{
}

std::string KeyTypedEvent::to_string() const
{
    std::stringstream ss;
    ss << get_name() << ": " << m_key_code;
    return ss.str();
}

} // namespace echo::events
