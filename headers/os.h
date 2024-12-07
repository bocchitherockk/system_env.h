#pragma once

#define OS_LINUX 0
#define OS_WINDOWS 0
#define OS_MACOS 0
#define OS_UNIX 0
#define OS_ANDROID 0
#define OS_IOS 0
#define OS_UNKNOWN 0


#if defined(_WIN32) || defined(_WIN64)
    #define OS_NAME "windows"
    #undef OS_WINDOWS
    #define OS_WINDOWS 1

#elif defined(__linux__)
    // __linux is for obsolete linux systems (non posix compliant)
    #define OS_NAME "linux"
    #undef OS_LINUX
    #undef OS_UNIX
    #define OS_LINUX 1
    #define OS_UNIX 1

#elif defined(__APPLE__) && defined(__MACH__)
    #define OS_NAME "macos"
    #undef OS_MACOS
    #undef OS_UNIX
    #define OS_MACOS 1
    #define OS_UNIX 1
    #pragma message("this operating system is not tested yet.")

#elif defined(__ANDROID__)
    #define OS_NAME "android"
    #undef OS_ANDROID
    #define OS_ANDROID 1
    #pragma message("this operating system is not tested yet.")

#elif defined(__APPLE__) && defined(__IPHONE_OS_VERSION_MIN_REQUIRED)
    #define OS_NAME "ios"
    #undef OS_IOS
    #define OS_IOS 1
    #pragma message("this operating system is not tested yet.")

#else
    #define OS_NAME "unknown"
    #undef OS_UNKNOWN
    #define OS_UNKNOWN 1
    #pragma message("warning: Unknown operating system detected, please add its configuration.")
#endif

#define OS_POSIX_COMPLIANT (OS_LINUX || OS_MACOS || OS_UNIX || OS_ANDROID)
