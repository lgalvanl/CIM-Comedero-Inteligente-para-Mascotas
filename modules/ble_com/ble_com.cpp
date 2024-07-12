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

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static char buffer[MAX_LETRAS] = {0};
static int bufferIndex = 0;

//=====[Declarations (prototypes) of private functions]========================

char bleComCharRead();

//=====[Implementations of public functions]===================================

void bleComStringWrite(const char* str) {
    uartBle.write(str, strlen_(str));
}

char* bleComReadString() {
    char receivedChar = '\0';
    while (uartBle.readable()) {
        uartBle.read(&receivedChar, 1);
        if (receivedChar == '\n') { 
            buffer[bufferIndex] = '\0';
            
            bufferIndex = 0;
            return buffer;
        } else {
            if (bufferIndex < MAX_LETRAS - 1) {
                buffer[bufferIndex++] = receivedChar;
            }
        }
    }
    printf("error al recibir cadena :( \n");
    return NULL; 
}

//=====[Implementations of private functions]==================================

char bleComCharRead(){
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar, 1);
        //printf("Caracter BLE recibido: %c\n", receivedChar);
    }
    return receivedChar;
}


