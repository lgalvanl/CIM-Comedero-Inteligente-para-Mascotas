//=====[#include guards - begin]===============================================

#ifndef _BALANCE_SENSOR_H_
#define _BALANCE_SENSOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

extern int primer_valor;
extern int segundo_valor;
extern int gramos_consumidos;

//=====[Declarations (prototypes) of public functions]=========================

void balanceSensorInit();
int gramosPesados();
int gramosConsumidos(int valorInicial, int valorFinal);

//=====[#include guards - end]=================================================

#endif // _BALANCE_SENSOR_H_