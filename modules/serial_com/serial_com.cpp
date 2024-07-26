//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "serial_com.h"
#include "ble_com.h"
#include "sensor_rfid.h"
#include <cstdio>
#include "data_usuario.h"
#include "eventos.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============



//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

bool DataRecibida = false;

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void SerialComUpdate(){
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ) {
        switch (receivedChar) {
        case 'D': 
            csv_a_cadena(cadena);
            inicializarArregloMascotas(arreglo_mascotas,cadena);
            break;
        case 'm': 
            mandar_data();
            break;
        case 'r': 
            bleComStringWrite(uid);
            break;    
        case 'l': 
            DataRecibida = true;
            break;
        case 'a': 
            if(HayAlerta){
                bleComStringWrite(nombre_alerta);
                HayAlerta = false;
            }
            break;
        default: 
            break;
    } 
    }
}


//=====[Implementations of private functions]==================================
