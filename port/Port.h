#pragma once

// Determining the platform based on predefined macros.
#if defined(_WIN32)
#   define PORT_WINDOWS
#   define PORT_PLATFORM_STRING "Windows"
#elif defined(__linux__)
#   define PORT_LINUX
#   define PORT_PLATFORM_STRING "Linux"
#else
#   error "Unsupported platform. This library supports only Windows and Linux."
#endif

#pragma message("Platform: " PORT_PLATFORM_STRING)

#if defined(PORT_WINDOWS)
#   include <port/win/Windows.h>
#elif defined(PORT_LINUX)
#   include <port/linux/Linux.h>
#endif

