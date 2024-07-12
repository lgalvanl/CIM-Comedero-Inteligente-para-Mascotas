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

char* bleComReadString(int largo) {
    static char receivedString[51]; 
    int i = 0;

    while (i < largo) {
        if (uartBle.readable()) {
            char receivedChar = '\0';
            uartBle.read(&receivedChar, 1);
            if (receivedChar == '\n') {
                break;
            }
            receivedString[i] = receivedChar;
            i++;
        }
    }

    receivedString[i] = '\0'; // Asegurar que la cadena está terminada con un carácter nulo
    return receivedString;
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


