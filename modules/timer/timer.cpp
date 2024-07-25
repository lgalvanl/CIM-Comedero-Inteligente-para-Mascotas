//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "sensor_rfid.h"
#include "data_usuario.h"
#include "ds3231.h"
#include "timer.h"
#include "serial_com.h"
#include "ble_com.h"
#include "eventos.h"
#include "cadenas.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void ChequearContadorMascota(mascota_t *mascota);

//=====[Implementations of public functions]===================================
Ds3231 rtc(D14,D15);

void configurar_fecha_hora(){
    //                      {seg,mts,horas,24hs,0}
    ds3231_time_t horario = {0,26,19,0,0};
    uint16_t _horario = rtc.set_time(horario);
             //                  {dia,fecha,mes,año}
    ds3231_calendar_t calendar = {5  , 24  , 7 ,24};
    uint16_t _calendario = rtc.set_calendar(calendar);
}

void fecha_hora(ds3231_time_t *tiempo,ds3231_calendar_t *fecha){
    uint16_t resultado = rtc.get_time(tiempo);
    uint16_t resultado_f = rtc.get_calendar(fecha);
}

void ActualizarContador(mascota_t *mascota) {
    ds3231_time_t TiempoActual;
    ds3231_calendar_t fecha_actual;
    uint16_t resultado = rtc.get_time(&TiempoActual);
    uint16_t resultado_f = rtc.get_calendar(&fecha_actual);
    if (resultado == 0) {
        mascota->UltimaDeteccion = TiempoActual;
        mascota->FechaDeteccion = fecha_actual;
    }
}

void InicializarContadorBateria(){
    uint16_t resultado = rtc.get_calendar(&UltimaRecargaBat);
}

void ChequearContadores(){
    if(DataRecibida){
        for (int i = 0; i < indicePetActual; ++i) {
            ChequearContadorMascota(&arreglo_mascotas[i]);
        }
    }    
}

void ChequearContadorBateria(){
    char cadena_bat[10]= "Bateria  ";
    ds3231_calendar_t fecha_actual;
    uint16_t resultado_f = rtc.get_calendar(&fecha_actual);
        int dias_pasados = fecha_actual.date - UltimaRecargaBat.date;
        if (dias_pasados >= DIAS_BAT) {
            HayAlerta = true;
            strcpy_(nombre_alerta,cadena_bat);
        }
}    

//=====[Implementations of private functions]==================================

void ChequearContadorMascota(mascota_t *mascota){
    if(!mascota->AlertaNotificada){
        ds3231_time_t TiempoActual;
        ds3231_calendar_t fecha_actual;
        uint16_t resultado = rtc.get_time(&TiempoActual);
        uint16_t resultado_f = rtc.get_calendar(&fecha_actual);
        int segundos_pasados = (TiempoActual.hours * 3600 + TiempoActual.minutes * 60 + TiempoActual.seconds) -
                                (mascota->UltimaDeteccion.hours * 3600 + mascota->UltimaDeteccion.minutes * 60 + mascota->UltimaDeteccion.seconds);
            if (segundos_pasados >= SEGS_DEMO) { // 86400 seg = 24 horas
                mandarAlerta(mascota);
                strcpy_(nombre_alerta,mascota->nombre);
            }
    }               
}

