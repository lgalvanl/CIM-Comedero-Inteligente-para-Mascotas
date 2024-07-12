//=====[#include guards - begin]===============================================

#ifndef _SERIAL_COM_H_
#define _SERIAL_COM_H_
//==================[Libraries]=================================================


//=====[Declaration of public data types]======================================






//=====[Declarations (prototypes) of public functions]=========================
void SerialComUpdate();
char SerialComCharRead();
static void SerialComCommandUpdate(char receivedChar);

//=====[#include guards - end]=================================================

#endif // _SERIAL_COM_H_