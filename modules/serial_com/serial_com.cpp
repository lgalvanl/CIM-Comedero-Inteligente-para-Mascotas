//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "serial_com.h"
#include "ble_com.h"
#include "sensor_rfid.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static void SerialComCommandUpdate(char receivedChar);
void prenderLedVerde();
void prenderLedRojo();
void ApagarLeds();
void prenderLeds();

//=====[Implementations of public functions]===================================
void SerialComUpdate()
{
    char receivedChar = SerialComCharRead();
    if( receivedChar != '\0' ) {
        printf("Caracter recibido: %c\n", receivedChar);
        SerialComCommandUpdate(receivedChar);
    }
}

char *DataRecibida;
static void SerialComCommandUpdate(char receivedChar){
    switch (receivedChar) {
        case 'd': case 'D': 
            printf("Hay data que llega de la app\n");
            DataRecibida = bleComReadString(); 
            if (DataRecibida != NULL) {
                printf("Recibimos: %s\n", DataRecibida);
            } else {
                printf("Error al recibir cadena :(\n");
            }
            break;
        case 'm': case 'M': 
            printf("App pide la info recolectada\n");
            ApagarLeds(); 
            break;
        case 'R': case 'r': 
            printf("App esta pidiendo el valor del uid\n");
            uid = rfidGetUid();
            printf("valor leido: %s\n", uid);
            bleComStringWrite(uid);
            //printf("valor de uid %s \n",uid);
            
            break;
        default: 
            printf("Error al leer\n"); 
            break;
    } 
}
char SerialComCharRead(){
    char receivedChar = '\0';
    if( uartUsb.readable() ) {
        uartUsb.read( &receivedChar, 1 );
    }
    if( receivedChar == '\0' ) {
        receivedChar = bleComCharRead();
    }
    return receivedChar;
}

//=====[Implementations of private functions]==================================
void prenderLedVerde(){
    
}
void prenderLedRojo(){
    
}
void ApagarLeds(){
   
}
void prenderLeds(){
}