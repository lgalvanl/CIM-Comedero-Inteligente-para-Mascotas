//=====[#include guards - begin]===============================================

#ifndef _BLE_COM_H_
#define _BLE_COM_H_

//=====[Declaration of public defines]=========================================
#define MAX_LETRAS 50
//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void bleComUpdate();
void bleComStringWrite( const char* str );
char* bleComReadString(int largo);


//=====[#include guards - end]=================================================

#endif // _BLE_COM_H_