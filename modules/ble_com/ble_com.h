//=====[#include guards - begin]===============================================

#ifndef _BLE_COM_H_
#define _BLE_COM_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

char bleComCharRead();
void bleComStringWrite( const char* str );
void SerialComStringRead( char* str, int strLength );

//=====[#include guards - end]=================================================

#endif // _BLE_COM_H_