#pragma once
#ifndef ECHO_EVENTS_MOUSE_EVENT_HPP
#define ECHO_EVENTS_MOUSE_EVENT_HPP

#include "events/macros/export.hpp"

#include "events/abs_event.hpp"

#include <core/mouse_codes.hpp>

#include <types.hpp>

namespace echo::events
{

class ECHO_EVENTS_EXPORT MouseMovedEvent : public AbsEvent
{
  public:
    MouseMovedEvent(const float x, const float y);

    float get_x() const;
    float get_y() const;

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_mouse_moved)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_mouse | Kevent_category_input)

  private:
    float m_x, m_y;
};

class ECHO_EVENTS_EXPORT MouseScrolledEvent : public AbsEvent
{
  public:
    MouseScrolledEvent(const float x_offset, const float y_offset);

    float get_x_offset() const;
    float get_y_offset() const;

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_mouse_scrolled)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_mouse | Kevent_category_input)

  private:
    float m_x_offset, m_y_offset;
};

class ECHO_EVENTS_EXPORT MouseButtonEvent : public AbsEvent
{
  public:
    core::MouseCode get_mouse_code() const;

    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_mouse | Kevent_category_input | Kevent_category_mouse_button)

  protected:
    MouseButtonEvent(const core::MouseCode mouse_code);

    core::MouseCode m_mouse_code;
};

class ECHO_EVENTS_EXPORT MouseButtonPressedEvent : public MouseButtonEvent
{
  public:
    MouseButtonPressedEvent(const core::MouseCode mouse_code);

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_mouse_button_pressed)
};

class ECHO_EVENTS_EXPORT MouseButtonReleasedEvent : public MouseButtonEvent
{
  public:
    MouseButtonReleasedEvent(const core::MouseCode mouse_code);

    std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_mouse_button_released)
};

} // namespace echo::events

#endif // ECHO_EVENTS_MOUSE_EVENT_HPP