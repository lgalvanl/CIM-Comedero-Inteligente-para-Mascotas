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
    //DataRecibida = false;
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ) {
        switch (receivedChar) {
        case 'D': 
            csv_a_cadena(cadena);
            printf("se leyo: %s \n",cadena);
            inicializarArregloMascotas(arreglo_mascotas,cadena);
            break;
        case 'm': 
            printf("App pide la info recolectada\n");
            mandar_data();
            break;
        case 'r': 
            printf("App pide valor de uid\n");
            bleComStringWrite(uid);
            printf("se leyo: %s \n",uid);
            break;    
        case 'l': 
            printf("Ya se envio toda la info!\n");
            DataRecibida = true;
            break;
        case 'a': 
            printf("La app pregunta si hay alguna alerta a recibir\n");
            if(HayAlerta){
                bleComStringWrite(nombre_alerta);
                HayAlerta = false;
            }
            break;
        default: 
            printf("Error al leer\n"); 
            break;
    } 
    }
}


//=====[Implementations of private functions]==================================
