#pragma once
#ifndef ECHO_EVENTS_ABS_EVENT_HPP
#define ECHO_EVENTS_ABS_EVENT_HPP

#include "events/macros/export.hpp"

#include "events/interfaces/ievent.hpp"
namespace echo::events
{

class ECHO_EVENTS_EXPORT AbsEvent : public interfaces::IEvent
{
  public:
    inline virtual ~AbsEvent() override = 0;

    virtual std::string to_string() const override;

    virtual bool is_in_category(EventCategory category) const override;
    virtual bool has_been_handled() const override;

    virtual void update_status(bool status) override;

  private:
    bool m_handled = false;
};

AbsEvent::~AbsEvent() = default;

} // namespace echo::events

#endif // ECHO_EVENTS_ABS_EVENT_HPP