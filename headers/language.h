#pragma once

#define LANGUAGE_C 0
#define LANGUAGE_CPP 0

#ifdef __cplusplus
    #define LANGUAGE_NAME "C++"
    #undef LANGUAGE_CPP
    #define LANGUAGE_CPP 1
#else
    #define LANGUAGE_NAME "C"
    #undef LANGUAGE_C
    #define LANGUAGE_C 1
#endif


#define C94 (__STDC_VERSION__ == 199409L)
#define C99 (__STDC_VERSION__ == 199901L)
#define C11 (__STDC_VERSION__ == 201112L)
#define C18 (__STDC_VERSION__ == 201710L)

#define CPP98 (__cplusplus == 199711L)
#define CPP11 (__cplusplus == 201103L)
#define CPP14 (__cplusplus == 201402L)
#define CPP17 (__cplusplus == 201703L)
#define CPP20 (__cplusplus == 202002L)
