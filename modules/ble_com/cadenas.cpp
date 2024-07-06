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