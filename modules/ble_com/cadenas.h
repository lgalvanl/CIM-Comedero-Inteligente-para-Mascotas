//=====[#include guards - begin]===============================================
#include "ds3231.h"

#ifndef _CADENAS_H_
#define _CADENAS_H_

//=====[Declaration of public defines]=========================================

#define MAX_LETRAS 50

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================
uint32_t strlen_(const char* str);
bool strcmp_(const char* cad1, const char* cad2);
char* strcpy_(char* dst, char* src);
char* strncpy_(char* dst, const char* src, uint32_t len);
char* strndup_(const char* src, size_t n);
char* strtok_(char* str, const char* delimiters);
char* strchr_(const char* str, int character);
//=====[#include guards - end]=================================================

#endif // _CADENAS_H_