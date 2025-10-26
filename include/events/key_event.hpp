#pragma once
#ifndef ECHO_EVENTS_KEY_EVENT_HPP
#define ECHO_EVENTS_KEY_EVENT_HPP

#include "events/macros/export.hpp"

#include "events/abs_event.hpp"

#include <core/key_codes.hpp>

#include <types.hpp>

namespace echo::events
{

class ECHO_EVENTS_EXPORT KeyEvent : public AbsEvent
{
  public:
    core::KeyCode get_key_code() const;

    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_keyboard | Kevent_category_input)

  protected:
    KeyEvent(const core::KeyCode key_code);

    core::KeyCode m_key_code;
};

class ECHO_EVENTS_EXPORT KeyPressedEvent : public KeyEvent
{
  public:
    KeyPressedEvent(const core::KeyCode key_code, bool is_repeated = false);

    bool is_repeated() const;

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_key_pressed)

  private:
    bool m_is_repeated;
};

class ECHO_EVENTS_EXPORT KeyReleasedEvent : public KeyEvent
{
  public:
    KeyReleasedEvent(const core::KeyCode key_code);

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_key_released)
};

class ECHO_EVENTS_EXPORT KeyTypedEvent : public KeyEvent
{
  public:
    KeyTypedEvent(const core::KeyCode key_code);

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_key_typed)
};

} // namespace echo::events

#endif // ECHO_EVENTS_KEY_EVENT_HPP