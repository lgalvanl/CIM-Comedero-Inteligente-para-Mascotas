//=====[#include guards - begin]===============================================
#include "mbed.h"
#include "arm_book_lib.h"
#ifndef _BLE_COM_H_
#define _BLE_COM_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

char bleComCharRead();
void bleComStringWrite(char* str );
void SerialComStringRead( char* str, int strLength );

//=====[#include guards - end]=================================================

#endif // _BLE_COM_H_