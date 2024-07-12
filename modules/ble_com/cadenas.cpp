//=====[Libraries]=============================================================
#include <string.h>
#include "mbed.h"
#include "arm_book_lib.h"
#include "cadenas.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============


//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Implementations of public functions]===================================
bool strcmp_(const char* cad1, const char* cad2) {
    while (*cad1 && *cad2 && (*cad1 == *cad2)) {
        cad1++;
        cad2++;
    }
    return (*cad1 == '\0' && *cad2 == '\0');
}

uint32_t strlen_(const char* str) {
    uint32_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* strncpy_(char* dst, const char* src, uint32_t len) {
    if (dst == NULL || src == NULL || len == 0) {
        return NULL;
    }
    char* ret = dst;
    while (len > 1 && *src != '\0') {
        *dst++ = *src++;
        len--;
    }
    *dst = '\0'; 
    return ret;
}

char* strndup_(const char* src, size_t n) {
    size_t len = 0;
    while (len < n && src[len] != '\0') {
        len++;
    }
    char* dst = (char*)malloc(len + 1);
    if (!dst) {
        return NULL; 
    }
    for (size_t i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    dst[len] = '\0';

    return dst;
}