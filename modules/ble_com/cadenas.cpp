//=====[Libraries]=============================================================
#include <string.h>
#include "mbed.h"
#include "arm_book_lib.h"
#include "cadenas.h"
#include <stddef.h>

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
char* strcpy_(char* dst, char* src) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char* ret = dst;
    while ((*dst++ = *src++) != '\0') {
        // Copia los caracteres uno por uno
    }
    return ret;
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

char* strtok_(char* str, const char* delimiters) {
    static char* last = NULL;

    if (str == NULL) {
        str = last;
    }

    if (str == NULL) {
        return NULL;
    }

    // Saltar los delimitadores iniciales
    while (*str && strchr_(delimiters, *str)) {
        str++;
    }

    if (*str == '\0') {
        last = NULL;
        return NULL;
    }

    char* token_start = str;
    while (*str && !strchr_(delimiters, *str)) {
        str++;
    }
    if (*str) {
        *str = '\0';
        last = str + 1;
    } else {
        last = NULL;
    }
    return token_start;
}

char* strchr_(const char* str, int character) {
    while (*str != '\0') {
        if (*str == (char)character) {
            return (char*)str;
        }
        str++;
    }
    if (character == '\0') {
        return (char*)str;
    }
    return NULL;
}
