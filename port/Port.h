#pragma once
#if !defined(_PORT_)
#define _PORT_

// Determining the platform based on predefined macros.
#if defined(_WIN32)
#   define PORT_WINDOWS
#   define PORT_PLATFORM_STRING "Windows"
#   if defined(_WIN64)
#       define PORT_WIN64
#       define PORT_ARCH64
#       define PORT_X64
#       define PORT_ARCH_STRING "x64"
#    else
#       define PORT_WIN32
#       define PORT_ARCH32
#       define PORT_ARCH_STRING "x86"
#   endif
#elif defined(__linux__)
#   define PORT_LINUX
#   define PORT_PLATFORM_STRING "Linux"
#else
#   error "Unsupported platform. This library supports only Windows and Linux."
#endif

#if defined(PORT_WINDOWS)
#   include <port/win/Windows.h>
#elif defined(PORT_LINUX)
#   include <port/linux/Linux.h>
#endif

#endif // _PORT_