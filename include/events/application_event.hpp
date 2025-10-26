#pragma once
#ifndef ECHO_EVENTS_APPLICATION_EVENT_HPP
#define ECHO_EVENTS_APPLICATION_EVENT_HPP

#include "events/macros/export.hpp"

#include "events/abs_event.hpp"

#include <types.hpp>

namespace echo::events
{

class ECHO_EVENTS_EXPORT WindowResizeEvent : public AbsEvent
{
  public:
    ~WindowResizeEvent() override = default;

    WindowResizeEvent(const uint32 &width, const uint32 &height);

    uint32 get_width() const;
    uint32 get_height() const;

    virtual std::string to_string() const override;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_window_resize)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_application)

  protected:
    uint32 m_width;
    uint32 m_height;
};

class ECHO_EVENTS_EXPORT WindowCloseEvent : public AbsEvent
{
  public:
    ~WindowCloseEvent() override = default;

    WindowCloseEvent() = default;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_window_close)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_application)
};

class ECHO_EVENTS_EXPORT AppTickEvent : public AbsEvent
{
  public:
    ~AppTickEvent() override = default;

    AppTickEvent() = default;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_app_tick)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_application)
};

class ECHO_EVENTS_EXPORT AppUpdateEvent : public AbsEvent
{
  public:
    ~AppUpdateEvent() override = default;

    AppUpdateEvent() = default;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_app_update)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_application)
};

class ECHO_EVENTS_EXPORT AppRenderEvent : public AbsEvent
{
  public:
    ~AppRenderEvent() override = default;

    AppRenderEvent() = default;

    ECHO_EVENTS_CLASS_TYPE(Kevent_type_app_render)
    ECHO_EVENTS_CLASS_CATEGORY(Kevent_category_application)
};

} // namespace echo::events

#endif // ECHO_EVENTS_APPLICATION_EVENT_HPP