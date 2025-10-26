#pragma once
#ifndef ECHO_EVENTS_EXPORT_HPP
#define ECHO_EVENTS_EXPORT_HPP

#include "events/macros/export_common.hpp"

#ifdef ECHO_EVENTS_BUILDING_SHARED
#define ECHO_EVENTS_EXPORT ECHO_EVENTS_DECL_EXPORT
#elif defined(ECHO_EVENTS_LINKING_SHARED)
#define ECHO_EVENTS_EXPORT ECHO_EVENTS_DECL_IMPORT
#endif

// Building library archive (static)
#ifndef ECHO_EVENTS_EXPORT
#define ECHO_EVENTS_EXPORT
#endif

#endif // ECHO_EVENTS_EXPORT_HPP