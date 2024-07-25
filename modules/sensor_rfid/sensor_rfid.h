//=====[#include guards - begin]===============================================
#ifndef _RFID_H_
#define _RFID_H_
//==================[Libraries]=================================================
#include "timer.h" 

#define SYSTEM_TIME_INCREMENT_MS 10
//=====[Declaration of public data types]======================================

typedef enum{
      RFID_ESPERO_ID,
      RFID_LLAVERO_DETECTADO,
} rfidEstado_t;

static int cantidad_mascotas = 0;
extern char* uid;

void evento();

//=====[Declarations (prototypes) of public functions]=========================

void rfidUpdate();
void rfidInit();
char* rfidGetUid();
void regDatosUpdate();

//=====[#include guards - end]=================================================
#endif // _RFID_H_