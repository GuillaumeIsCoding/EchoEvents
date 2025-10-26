#pragma once
#ifndef ECHO_EVENTS_VERSION_HPP
#define ECHO_EVENTS_VERSION_HPP

#define ECHO_EVENTS_VERSION_MAJOR 0

#define ECHO_EVENTS_VERSION_MINOR 0

#define ECHO_EVENTS_VERSION_PATCH 1

#define ECHO_EVENTS_TO_VERSION(major, minor, patch) (major * 10000 + minor * 100 + patch)
#define ECHO_EVENTS_VERSION                                                                                            \
    ECHO_EVENTS_TO_VERSION(ECHO_EVENTS_VERSION_MAJOR, ECHO_EVENTS_VERSION_MINOR, ECHO_EVENTS_VERSION_PATCH)

#endif // ECHO_EVENTS_VERSION_HPP