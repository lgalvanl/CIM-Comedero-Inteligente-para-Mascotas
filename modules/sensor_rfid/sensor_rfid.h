//=====[#include guards - begin]===============================================
#include "timer.h" 

#ifndef _RFID_H_
#define _RFID_H_
//==================[Libraries]=================================================

#define SYSTEM_TIME_INCREMENT_MS 10

//=====[Declaration of public data types]======================================
typedef enum{
      RFID_ESPERO_ID,
      RFID_LLAVERO_DETECTADO,
} rfidEstado_t;

static mascota_t mascotas[MAX_MASCOTAS];
static char *uid=NULL;

static int indicePetActual = 0;
static int cantidad_mascotas = 0;





//=====[Declarations (prototypes) of public functions]=========================
void rfidUpdate();
void rfidInit();
char* rfidGetUid();

void regDatosRFIDUpdate();

//=====[#include guards - end]=================================================

#endif // _RFID_H_