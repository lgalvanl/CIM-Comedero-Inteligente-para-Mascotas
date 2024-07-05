//=====[#include guards - begin]===============================================

#ifndef _BALANCE_SENSOR_H_
#define _BALANCE_SENSOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void balanceSensorInit();
long gramosPesados(long valor);
long gramosConsumidos(long valorInicial, long valorFinal);
//aca no van las funciones privadas
//=====[#include guards - end]=================================================

#endif // _BALANCE_SENSOR_H_