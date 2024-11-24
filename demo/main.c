#include <stdio.h>
#include "../system_env.h"

int main(void) {
    printf("Compiler name: %s\n", COMPILER_NAME);
    printf("Compiler version: %d.%d.%d\n", COMPILER_VERSION_MAJOR, COMPILER_VERSION_MINOR, COMPILER_VERSION_PATCH);
    printf("Language: %s\n", LANGUAGE_NAME);
    printf("OS: %s\n", OS_NAME);
    printf("Architecture: %s\n", ARCH_NAME);
    printf("Bits: %d\n", ARCH_BITS);
    printf("Endianess: %s\n", IS_BIG_ENDIAN ? "big endian" : "little endian");
    return 0;
}