//=====[Libraries]=============================================================

#include "mbed.h"

#include "ble_com.h"
#include "sensor_balance.h" 
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

static char bleComCharRead();

//=====[Implementations of public functions]===================================

void bleComUpdate() 
{
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ) {
        switch (receivedChar) {
            case 'D': printf("apretaste D"); break; //modificar
            case 'A': printf("apretaste A"); break; //modificar
        }
    }
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
    return NULL; 
}

//=====[Implementations of private functions]==================================

static char bleComCharRead()
{
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar,1);
    }
    return receivedChar;
}