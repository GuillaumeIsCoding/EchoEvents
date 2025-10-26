#pragma once
#ifndef ECHO_EVENTS_IEVENT_HPP
#define ECHO_EVENTS_IEVENT_HPP

#include "events/macros/export.hpp"

#include "events/event_type.hpp"

#include "events/event_category.hpp"

#include <types.hpp>

#include <string>
namespace echo::events::interfaces
{
class ECHO_EVENTS_EXPORT IEvent
{
  public:
    inline virtual ~IEvent() = 0;

    inline virtual EventType get_event_type() const = 0;

    inline virtual std::string get_name() const = 0;
    inline virtual std::string to_string() const = 0;

    inline virtual uint32 get_category_flags() const = 0;

    inline virtual bool is_in_category(EventCategory category) const = 0;
    inline virtual bool has_been_handled() const = 0;

    inline virtual void update_status(bool status) = 0;
};

IEvent::~IEvent() = default;

} // namespace echo::events::interfaces

#define ECHO_EVENTS_CLASS_TYPE(type)                                                                                   \
    static echo::events::EventType get_static_type()                                                                   \
    {                                                                                                                  \
        return echo::events::EventType::type;                                                                          \
    }                                                                                                                  \
    inline virtual echo::events::EventType get_event_type() const override                                             \
    {                                                                                                                  \
        return get_static_type();                                                                                      \
    }                                                                                                                  \
    inline virtual std::string get_name() const override                                                               \
    {                                                                                                                  \
        return std::string(#type);                                                                                     \
    }

#define ECHO_EVENTS_CLASS_CATEGORY(category)                                                                           \
    inline virtual uint32 get_category_flags() const override                                                          \
    {                                                                                                                  \
        return category;                                                                                               \
    }

inline std::ostream &operator<<(std::ostream &os, const echo::events::interfaces::IEvent &event)
{
    return os << event.to_string();
}

#endif // ECHO_EVENTS_IEVENT_HPP