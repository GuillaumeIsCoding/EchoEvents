#pragma once
#ifndef ECHO_EVENTS_EVENT_CATEGORY_HPP
#define ECHO_EVENTS_EVENT_CATEGORY_HPP

#include <core/macros/utils.hpp>

#include <types.hpp>

namespace echo::events
{

using CategoryCode = uint32;

enum EventCategory : CategoryCode
{
    Kevent_category_none = 0,
    Kevent_category_application = ECHO_BIT(1),
    Kevent_category_input = ECHO_BIT(2),
    Kevent_category_keyboard = ECHO_BIT(3),
    Kevent_category_mouse = ECHO_BIT(4),
    Kevent_category_mouse_button = ECHO_BIT(5)
};

} // namespace echo::events

#endif // ECHO_EVENTS_EVENT_CATEGORY_HPP