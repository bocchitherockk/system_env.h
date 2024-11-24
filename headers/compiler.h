#pragma once

#define COMPILER_EMSCRIPTEN 0
#define COMPILER_CLANG 0
#define COMPILER_INTEL 0
#define COMPILER_TCC 0
#define COMPILER_MSVC 0
#define COMPILER_ARM 0
#define COMPILER_MINGW 0
#define COMPILER_GCC 0
#define COMPILER_UNKNOWN 0

#if defined(__EMSCRIPTEN__)
    #define COMPILER_NAME "emscripten"
    #undef COMPILER_EMSCRIPTEN
    #define COMPILER_EMSCRIPTEN 1
    #define COMPILER_VERSION_MAJOR __EMSCRIPTEN_major__
    #define COMPILER_VERSION_MINOR __EMSCRIPTEN_minor__
    #define COMPILER_VERSION_PATCH __EMSCRIPTEN_tiny__
    #pragma message("this compiler is not tested yet")
#elif defined(__clang__)
    #define COMPILER_NAME "clang"
    #undef COMPILER_CLANG
    #define COMPILER_CLANG 1
    #define COMPILER_VERSION_MAJOR __clang_major__
    #define COMPILER_VERSION_MINOR __clang_minor__
    #define COMPILER_VERSION_PATCH __clang_patchlevel__

#elif defined(__INTEL_COMPILER) || defined(__ICL)
    // __ICC and __ECC are obsolete
    // __INTEL_COMPILER = VRP; V = Version; R = Revision; P = Patch
    #define COMPILER_NAME "intel"
    #undef COMPILER_INTEL
    #define COMPILER_INTEL 1
    #define COMPILER_VERSION_MAJOR (__INTEL_COMPILER / 100)
    #define COMPILER_VERSION_MINOR ((__INTEL_COMPILER / 10) % 10)
    #define COMPILER_VERSION_PATCH (__INTEL_COMPILER % 10)
    #pragma message("this compiler is not tested yet")

#elif defined(__TINYC__)
    #define COMPILER_NAME "tcc"
    #undef COMPILER_TCC
    #define COMPILER_TCC 1
    #define COMPILER_VERSION_MAJOR 0 // TCC does not define version macros
    #define COMPILER_VERSION_MINOR 0
    #define COMPILER_VERSION_PATCH 0

#elif defined(_MSC_VER)
    #define COMPILER_NAME "msvc"
    #undef COMPILER_MSVC
    #define COMPILER_MSVC 1
    #define COMPILER_VERSION_MAJOR (_MSC_VER / 100)
    #define COMPILER_VERSION_MINOR (_MSC_VER % 100)
    // the patch starting from Visual C++ 8.0 is represented on 5 digits so it should be changed to % 100000
    // #define COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
    #pragma message("this compiler is not tested yet")

#elif defined(__CC_ARM) && defined(__ARMCC_VERSION)
    // __ARMCC_VERSION = VRPBBB; V = Version; R = Revision; P = Patch; BBB = Build
    #define COMPILER_NAME "arm"
    #undef COMPILER_ARM
    #define COMPILER_ARM 1
    #define COMPILER_VERSION_MAJOR (__ARMCC_VERSION / 100000)
    #define COMPILER_VERSION_MINOR ((__ARMCC_VERSION / 10000) % 10)
    #define COMPILER_VERSION_PATCH ((__ARMCC_VERSION / 1000) % 10)
    #pragma message("this compiler is not tested yet")

#elif defined(__MINGW32__)
    #define COMPILER_NAME "mingw32"
    #undef COMPILER_MINGW
    #define COMPILER_MINGW 1
    #define COMPILER_VERSION_MAJOR __MINGW32_MAJOR_VERSION
    #define COMPILER_VERSION_MINOR __MINGW32_MINOR_VERSION
    #define COMPILER_VERSION_PATCH 0 // MinGW does not define patch level
    #pragma message("this compiler is not tested yet")

#elif defined(__MINGW64__)
    #define COMPILER_NAME "mingw64"
    #undef COMPILER_MINGW
    #define COMPILER_MINGW 1
    #define COMPILER_VERSION_MAJOR __MINGW64_VERSION_MAJOR
    #define COMPILER_VERSION_MINOR __MINGW64_VERSION_MINOR
    #define COMPILER_VERSION_PATCH 0 // MinGW does not define patch level
    #pragma message("this compiler is not tested yet")

#elif defined(__GNUC__)
    // i put this at the end because i think even clang and intel define this macro
    #define COMPILER_NAME "gcc"
    #undef COMPILER_GCC
    #define COMPILER_GCC 1
    #define COMPILER_VERSION_MAJOR __GNUC__
    #define COMPILER_VERSION_MINOR __GNUC_MINOR__
    #define COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__

#else
    #define COMPILER_NAME "unknown"
    #undef COMPILER_UNKNOWN
    #define COMPILER_UNKNOWN 1
    #pragma message("Warning: Unknown compiler detected, please add its configuration.")
#endif


// Feature Detection Based on Previously Detected Compiler
// note: as i said others that have not been tested yet are not included
// note: i'll be adding more features as i need them
#define COMPILER_SUPPORTS_TYPEOF               (COMPILER_GCC || COMPILER_CLANG || COMPILER_TCC)
#define COMPILER_SUPPORTS_STATEMENT_EXPRESSION (COMPILER_GCC || COMPILER_CLANG || COMPILER_TCC)
#define COMPILER_SUPPORTS_NESTED_FUNC          (COMPILER_GCC)
#define COMPILER_SUPPORTS_BUILTIN_CLZ          (COMPILER_GCC || COMPILER_CLANG)
