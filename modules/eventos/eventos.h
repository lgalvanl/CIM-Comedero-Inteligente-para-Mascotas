//=====[#include guards - begin]===============================================
#include "timer.h" 

#ifndef _EVENTOS_H_
#define _EVENTOS_H_

//==================[Libraries]=================================================

//=====[Declaration of public data types]======================================
#define MAX_EVENTOS 30
#define MAX_LARGO_CSV 18
extern char eventos[MAX_EVENTOS][MAX_LARGO_CSV+1];
static  int eventos_registrados = 0; 
extern bool HayEvento;
extern bool HayAlerta;

extern bool DataEnviar;
static char *cadena_evento1;
extern char nombre_alerta[10];
static int indice_eventos = 0;
//=====[Declarations (prototypes) of public functions]=========================

void ocurreEventoUpdate();
void mandar_data();
void mandarAlerta(mascota_t *mascota);

//=====[#include guards - end]=================================================

#endif // _EVENTOS_H_