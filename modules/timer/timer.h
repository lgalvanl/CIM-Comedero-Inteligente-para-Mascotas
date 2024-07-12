//=====[#include guards - begin]===============================================
#include "ds3231.h"
#include "datos_usuario.h"
#ifndef _TIMER_H_
#define _TIMER_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void InicializarRTC();                  
void InicializarContadorMascota(mascota_t mascota);
void InicializarContadores(mascota_t *mascota);
void InicializarContadorBateria(ds3231_calendar_t UltimaRecarga);

void ResetearContadorMascota(mascota_t mascota); 
void ResetearContadores(mascota_t *mascota, int cantidad_mascotas);
void ResetearContadorBateria(ds3231_calendar_t UltimaRecarga);

void ChequearContadorBateria(ds3231_calendar_t UltimaRecarga);
//void ChequearContadorMascota(mascota_t *mascota, Ds3231 &rtc);
void ChequearContadores(mascota_t* mascotas, int cantidad_mascotas, Ds3231 &rtc);

void ActualizarContadorBateria(ds3231_calendar_t UltimaRecarga, Ds3231 &rtc);
void ActualizarContador(mascota_t *mascota, Ds3231 &rtc);
void ActualizarContadores(mascota_t* mascotas, int cantidad_mascotas, Ds3231 &rtc);


//=====[#include guards - end]=================================================

#endif // _TIMER_