//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "serial_com.h"
#include "ble_com.h"
#include "sensor_rfid.h"
#include <cstdio>
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void prenderLedVerde();
void prenderLedRojo();
void ApagarLeds();
void prenderLeds();

//=====[Implementations of public functions]===================================
void SerialComUpdate(){
    char DataRecibida[50] = "";
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ) {
        switch (receivedChar) {
        case 'd': case 'D': 
            printf("App manda una cadena: \n");
            SerialComStringRead(DataRecibida,49);
            if(DataRecibida[0] != NULL) {
                printf("Leo desde la app: %s\n", DataRecibida);
            } else {
                printf("error al leer\n");
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