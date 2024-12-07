#pragma once

#define ARCH_X86 0
#define ARCH_ARM 0
#define ARCH_MIPS 0
#define ARCH_POWERPC 0
#define ARCH_UNKNOWN 0

// x86
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64) || defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
    #define ARCH_NAME "x86"
    #undef ARCH_X86
    #define ARCH_X86 1

// ARM
#elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm) || defined(__aarch64__)
    #define ARCH_NAME "arm"
    #undef ARCH_ARM
    #define ARCH_ARM 1
    #pragma message("Warning: this architecture is not tested yet.")

// MIPS
#elif defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
    #define ARCH_NAME "mips"
    #undef ARCH_MIPS
    #define ARCH_MIPS 1
    #pragma message("Warning: this architecture is not tested yet.")

// PowerPC
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__PPC64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_M_PPC) || defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || defined(__ppc)
    #define ARCH_NAME "powerpc"
    #undef ARCH_POWERPC
    #define ARCH_POWERPC 1
    #pragma message("Warning: this architecture is not tested yet.")

// Unknown
#else
    #define ARCH_NAME "unknown"
    #undef ARCH_UNKNOWN
    #define ARCH_UNKNOWN 1
    #pragma message("Warning: Unknown architecture detected, please add its configuration.")
#endif

#define ARCH_BITS_16 0
#define ARCH_BITS_32 0
#define ARCH_BITS_64 0

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64) || defined(__aarch64__) || defined(_MIPS_ISA_MIPS3) || defined(_MIPS_ISA_MIPS4) || defined(_MIPS_ISA_MIPS5) || defined(_MIPS_ISA_MIPS32) || defined(_MIPS_ISA_MIPS64) || defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC64)
    #define ARCH_BITS 64
    #undef ARCH_BITS_64
    #define ARCH_BITS_64 1
#elif defined(_M_I86) || defined(__thumb__) || defined(__TARGET_ARCH_THUMB) || defined(_M_ARMT)
    #define ARCH_BITS 16
    #undef ARCH_BITS_16
    #define ARCH_BITS_16 1
#else
    #define ARCH_BITS 32
    #undef ARCH_BITS_32
    #define ARCH_BITS_32 1
#endif
