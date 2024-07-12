//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "sensor_balance.h"
#include "HX711.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

HX711 balanza(PC_0,PA_3);
          //    (A1,A0)
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void balanceSensorInit()
{
    long pesoInicial = 0;
    long pesoFinal = 0;

}

//void balanceSensorUpdate()


long gramosPesados(long valor){
   valor = balanza.getValue();
   return valor;
}

long gramosConsumidos(long valorInicial, long valorFinal){
    return (valorFinal - valorInicial);
}

//=====[Implementations of private functions]==================================

