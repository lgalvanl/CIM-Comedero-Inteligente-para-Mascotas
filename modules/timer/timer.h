//=====[#include guards - begin]===============================================
#include "ds3231.h"
#include "data_usuario.h"
#ifndef _TIMER_H_
#define _TIMER_H_

//=====[Declaration of public defines]=========================================
#define SEGS_DIA 86400
#define SEGS_DEMO 40
#define DIAS_BAT 5
//=====[Declaration of public data types]======================================

static ds3231_calendar_t UltimaRecargaBat;

//=====[Declarations (prototypes) of public functions]=========================

void configurar_fecha_hora();
void fecha_hora(ds3231_time_t *tiempo,ds3231_calendar_t *fecha);         

void InicializarContadorMascota(mascota_t mascota);
void InicializarContadores(mascota_t *mascota);
void InicializarContadorBateria();

void ChequearContadorBateria();
void ChequearContadores();

void ActualizarContador(mascota_t *mascota);
void ActualizarContadores();



//=====[#include guards - end]=================================================

#endif // _TIMER_