//=====[Libraries]=============================================================

#include "mbed.h"
#include "ble_com.h"
#include <string.h>
#include "arm_book_lib.h"
#include "cadenas.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
UnbufferedSerial uartBle(PD_5, PD_6, 9600);
UnbufferedSerial uartpc(USBTX, USBRX,115200);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================




//=====[Implementations of public functions]===================================



void bleComStringWrite(const char* str) {
    uartBle.write(str, strlen_(str));
}

void SerialComStringRead( char* str, int strLength ){
    int strIndex;
    for ( strIndex = 0; strIndex < strLength; strIndex++) {
        uartBle.read( &str[strIndex] , 1 );
        uartBle.write( &str[strIndex] ,1 );
    }
    str[strLength]='\0';
}

char bleComCharRead(){
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar, 1);
    }
    return receivedChar;
}

//=====[Implementations of private functions]==================================




