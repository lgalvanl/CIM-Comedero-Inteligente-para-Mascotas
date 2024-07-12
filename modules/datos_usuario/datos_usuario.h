//=====[#include guards - begin]===============================================
#include "ds3231.h"

#ifndef _DATOS_USUARIO_H_
#define _DATOS_USUARIO_H_

//=====[Declaration of public defines]=========================================

#define MAX_LARGO_NOMBRE 50
#define MAX_MASCOTAS 10
#define MAX_LARGO_UID 10

//=====[Declaration of public data types]======================================

typedef struct mascota_t {
    char id_mascota[MAX_LARGO_UID + 1];
    unsigned char nombre[MAX_LARGO_NOMBRE + 1];
    ds3231_time_t UltimaDeteccion;
    ds3231_calendar_t FechaDeteccion;
} mascota_t;

//=====[Declarations (prototypes) of public functions]=========================


//=====[#include guards - end]=================================================

#endif // _DATOS_USUARIO_H_