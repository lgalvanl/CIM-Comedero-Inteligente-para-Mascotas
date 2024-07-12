//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "datos_usuario.h"
#include "ds3231.h"
#include "timer.h"
#include "ble_com.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void inicializar_ds3231_tiempo_t(ds3231_time_t *tiempo);
void ChequearContadorMascota(mascota_t *mascota, Ds3231 &rtc);
void inicializar_ds3231_calendario_t(ds3231_calendar_t *calendario);

//=====[Implementations of public functions]===================================

void inicializarRTC() {
    Ds3231 rtc(PB_9, PB_8);
}

void ActualizarContador(mascota_t *mascota, Ds3231 &rtc) {
    ds3231_time_t TiempoActual;
    ds3231_calendar_t fecha_actual;
    uint16_t resultado = rtc.get_time(&TiempoActual);
    uint16_t resultado_f = rtc.get_calendar(&fecha_actual);
    if (resultado == 0) {
        mascota->UltimaDeteccion = TiempoActual;
        mascota->FechaDeteccion = fecha_actual;
    }
}

void ActualizarContadorBateria(ds3231_calendar_t *UltimaRecarga, Ds3231 &rtc){
    uint16_t resultado = rtc.get_calendar(UltimaRecarga);
}

void ActualizarContadores(mascota_t* mascotas, int cantidad_mascotas, Ds3231 &rtc) {
    for (int i = 0; i < cantidad_mascotas; ++i) {
        ActualizarContador(&mascotas[i], rtc);
    }
}

void ChequearContadores(mascota_t* mascotas, int cantidad_mascotas, Ds3231 &rtc) {
    for (int i = 0; i < cantidad_mascotas; ++i) {
        ChequearContadorMascota(&mascotas[i], rtc);
    }
}

void resetear_ds3231_time_t(ds3231_time_t *tiempo) {
    tiempo->seconds = 0;
    tiempo->minutes = 0;
    tiempo->hours = 0;
    tiempo->am_pm = false; 
    tiempo->mode = false;  //24 horas
}

void ResetearContadorMascota(mascota_t* mascota) {
    resetear_ds3231_time_t(&(mascota->UltimaDeteccion));
    inicializar_ds3231_calendario_t(&(mascota->FechaDeteccion));
}

void ResetearContadores(mascota_t* arreglo_mascotas, int cantidad_mascotas) {
    for (int i = 0; i < cantidad_mascotas; ++i) {
        ResetearContadorMascota(&arreglo_mascotas[i]);
    }
}

void InicializarContadorBateria(ds3231_calendar_t *UltimaRecarga, Ds3231 &rtc){
    uint16_t resultado = rtc.get_calendar(UltimaRecarga);
}

void ChequearContadorBateria(ds3231_calendar_t *UltimaRecarga, Ds3231 &rtc){
    ds3231_calendar_t fecha_actual;
    uint16_t resultado_f = rtc.get_calendar(&fecha_actual);
    if (resultado_f == 0) {
        int dias_pasados = fecha_actual.date - UltimaRecarga->date;
        if (dias_pasados >= 5) {
            //AvisarRecargaBateria()  usar push en mit app inventor;
        }
    }
}    

//=====[Implementations of private functions]==================================

void ChequearContadorMascota(mascota_t *mascota, Ds3231 &rtc){
    ds3231_time_t TiempoActual;
    ds3231_calendar_t fecha_actual;
    uint16_t resultado = rtc.get_time(&TiempoActual);
    uint16_t resultado_f = rtc.get_calendar(&fecha_actual);
    if (fecha_actual.year == mascota->FechaDeteccion.year &&
            fecha_actual.month == mascota->FechaDeteccion.month &&
            fecha_actual.date == mascota->FechaDeteccion.date) {
            // Misma fecha, comprobar las horas
            int segundos_pasados = (TiempoActual.hours * 3600 + TiempoActual.minutes * 60 + TiempoActual.seconds) -
                                   (mascota->UltimaDeteccion.hours * 3600 + mascota->UltimaDeteccion.minutes * 60 + mascota->UltimaDeteccion.seconds);
            if (segundos_pasados >= 86400) { // 86400 segundos en 24 horas
                printf("¡Han pasado 24 horas desde la última detección de la mascota ID: %s!\n", mascota->id_mascota);
                //AvisarPasaron24horas()  usar push en mit app inventor;
            }
        } else {
            // Comparar fechas diferentes
            int dias_pasados = fecha_actual.date - mascota->FechaDeteccion.date;
            if (dias_pasados > 0 || fecha_actual.month != mascota->FechaDeteccion.month || fecha_actual.year != mascota->FechaDeteccion.year) {
                printf("¡Han pasado 24 horas desde la última detección de la mascota ID: %s!\n", mascota->id_mascota);
            }
        
        }           
}

void inicializar_ds3231_tiempo_t(ds3231_time_t *tiempo) {
    tiempo->seconds = 0;
    tiempo->minutes = 0;
    tiempo->hours = 0;
    tiempo->am_pm = false; 
    tiempo->mode = false; 
}

void inicializar_ds3231_calendario_t(ds3231_calendar_t *calendario) {
    calendario->day = 1;
    calendario->date = 1;
    calendario->month = 1;
    calendario->year = 2024;
}