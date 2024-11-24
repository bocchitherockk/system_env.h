#pragma once


#define ARCH_X86 0
#define ARCH_ARM 0
#define ARCH_MIPS 0
#define ARCH_POWERPC 0
#define ARCH_UNKNOWN 0

#if defined(__i386__) || defined(__i386) || defined(i386) || defined(__x86_64__)
    #define ARCH_NAME "x86"
    #undef ARCH_X86
    #define ARCH_X86 1
#elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm) || defined(__aarch64__)
    #define ARCH_NAME "arm"
    #undef ARCH_ARM
    #define ARCH_ARM 1
#elif defined(__mips__) || defined(mips) || defined(__mips)
    #define ARCH_NAME "mips"
    #undef ARCH_MIPS
    #define ARCH_MIPS 1
#elif defined(__powerpc__) || defined(__powerpc) || defined(__powerpc64__)
    #define ARCH_NAME "powerpc"
    #undef ARCH_POWERPC
    #define ARCH_POWERPC 1
#else
    #define ARCH_NAME "unknown"
    #undef ARCH_UNKNOWN
    #define ARCH_UNKNOWN 1
    #pragma message("Warning: Unknown architecture detected, please add its configuration.")
#endif


#define ARCH_RISC (ARCH_ARM || ARCH_MIPS || ARCH_POWERPC)
#define ARCH_CISC (ARCH_X86)


#define ARCH_32_BIT 0
#define ARCH_64_BIT 0

#if defined(__x86_64__) || defined(__powerpc64__)
    #define ARCH_BITS 64
    #undef ARCH_64_BIT
    #define ARCH_64_BIT 1
#else
    #define ARCH_BITS 32
    #undef ARCH_32_BIT
    #define ARCH_32_BIT 1
#endif
