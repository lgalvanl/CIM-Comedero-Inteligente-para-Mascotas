//=====[#include guards - begin]===============================================
#include "ds3231.h"

#ifndef _DATOS_USUARIO_H_
#define _DATOS_USUARIO_H_

//=====[Declaration of public defines]=========================================

#define MAX_LARGO_NOMBRE 9
#define MAX_MASCOTAS 10
#define MAX_LARGO_UID 8

//=====[Declaration of public data types]======================================
static char DataRecibida1[19]= "";
static char DataRecibida2[19]= "";
static char cadena[19] = "";
static int CantidadPets = 0;

typedef struct mascota_t {
    char id_mascota[MAX_LARGO_UID + 1];
    char nombre[MAX_LARGO_NOMBRE + 1];
    ds3231_time_t UltimaDeteccion;
    ds3231_calendar_t FechaDeteccion;
    bool AlertaNotificada;
} mascota_t;

extern mascota_t arreglo_mascotas[MAX_MASCOTAS];
extern int indicePetActual;
extern int Indice;

//=====[Declarations (prototypes) of public functions]=========================

void csv_a_cadena(char *csv);
void MostrarArreglo(mascota_t *mascotas);
void detectarMascota(char *uidLeido, int *posicion);
void inicializarArregloMascotas(mascota_t *mascotas,char *cadenaLeida);
void time_a_char(ds3231_time_t tiempo, char *tiempo_str);
//=====[#include guards - end]=================================================

#endif // _DATOS_USUARIO_H_