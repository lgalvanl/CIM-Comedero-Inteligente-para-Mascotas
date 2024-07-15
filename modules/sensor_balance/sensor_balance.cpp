//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "sensor_balance.h"
#include "HX711.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

HX711 balanza(A0,A1);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void balanceSensorInit(){
    balanza.setScale(63079621.20/150);
}

int gramosPesados(int valor){
   valor = balanza.getGram();
   return valor;
}

int gramosConsumidos(int valorInicial, int valorFinal){
    return (valorFinal - valorInicial);
}

//=====[Implementations of private functions]==================================

