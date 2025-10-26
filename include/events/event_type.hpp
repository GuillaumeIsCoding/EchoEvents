#pragma once
#ifndef ECHO_EVENTS_EVENT_TYPE_HPP
#define ECHO_EVENTS_EVENT_TYPE_HPP

namespace echo::events
{

enum class EventType
{
    Kevent_type_none = 0,
    Kevent_type_window_close,
    Kevent_type_window_resize,
    Kevent_type_window_focus,
    Kevent_type_window_lost_focus,
    Kevent_type_window_moved,
    Kevent_type_app_tick,
    Kevent_type_app_update,
    Kevent_type_app_render,
    Kevent_type_key_pressed,
    Kevent_type_key_released,
    Kevent_type_key_typed,
    Kevent_type_mouse_button_pressed,
    Kevent_type_mouse_button_released,
    Kevent_type_mouse_moved,
    Kevent_type_mouse_scrolled
};

} // namespace echo::events

#endif // ECHO_EVENTS_EVENT_TYPE_HPP