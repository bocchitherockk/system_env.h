#pragma once

#if defined(_MSC_VER)
    #define IS_LITTLE_ENDIAN (1 == *(unsigned char *)&(unsigned short){1})
    #define IS_BIG_ENDIAN (!IS_LITTLE_ENDIAN)

#else
    #define IS_LITTLE_ENDIAN (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
    #define IS_BIG_ENDIAN (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)

#endif
