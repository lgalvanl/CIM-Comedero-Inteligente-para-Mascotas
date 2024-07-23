//=====[Libraries]=============================================================
#include <string.h>
#include "mbed.h"
#include "arm_book_lib.h"
#include "ble_com.h"
#include "data_usuario.h"
#include <stdio.h>  
#include <stdbool.h>  
#include <string.h> 
#include "cadenas.h"
#include "ds3231.h"
#include "timer.h"
#include "cadenas.h"
#include "eventos.h"
#include "serial_com.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

mascota_t arreglo_mascotas[MAX_MASCOTAS];
int indicePetActual = 0;
int Indice = 0;

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
void time_a_char(ds3231_time_t tiempo, char *tiempo_str);
void calendar_a_char(ds3231_calendar_t calendario, char *fecha);
void struct_a_csv(mascota_t mascota, char *csv);
void csv_a_struct(mascota_t *mascota, char *csv);

//=====[Implementations of public functions]===================================

void csv_a_cadena(char *cadena){ //Lee el texto (nombre;uid) desde la app y guarda en *cadena
    SerialComStringRead(cadena,18);
} 
void inicializarArregloMascotas(mascota_t *mascotas, char *cadenaLeida){ //A partir de la cadena con (nombre;uid) crea un mascota_t
    if(indicePetActual < MAX_MASCOTAS){
       csv_a_struct(&mascotas[indicePetActual],cadenaLeida); 
       fecha_hora(&mascotas[indicePetActual].UltimaDeteccion,&mascotas[indicePetActual].FechaDeteccion);
       mascotas[indicePetActual].AlertaNotificada = false;
       indicePetActual++;
    }
}
void MostrarArreglo(mascota_t *mascotas){ //Imprime por puerto serial el arreglo de estructuras mascota_t
    if(indicePetActual == 0){
        printf("el arreglo esta vacio!");
    } else {
     for(int i = 0; i < indicePetActual; i++){
         //imprimir_struct(&mascotas[i]); 
    } }
}
void detectarMascota(char *uidLeido, int *posicion) { //Compara el valor uid leido y devuelve la posicion del arreglo que corresponde con dicho valor
    if(DataRecibida){
        for (int i = 0; i < indicePetActual; i++){
            if (strcmp_(arreglo_mascotas[i].id_mascota, uidLeido) == 0){
                *posicion = i;
                HayEvento = true;
                return;
            }
        } 
    } else {
        printf("Aun no se cargo la data desde la app\n ");
    }
}

void time_a_char(ds3231_time_t tiempo, char *tiempo_str) { 
    sprintf(tiempo_str, "%02d:%02d:%02d", tiempo.hours, tiempo.minutes, tiempo.seconds);
}
//=====[Implementations of private functions]==================================

void struct_a_csv(mascota_t mascota, char *csv) { //Guarda en una cadena toda la data de la estructura
    char tiempo_str[9] = "";  
    char fecha_str[9] = "";
    
    time_a_char(mascota.UltimaDeteccion, tiempo_str);
    calendar_a_char(mascota.FechaDeteccion, fecha_str);
    
    sprintf(csv, "%s;%s;%s;%s", mascota.id_mascota, mascota.nombre, tiempo_str, fecha_str);
}



void calendar_a_char(ds3231_calendar_t calendario, char *fecha) {
    sprintf(fecha, "%02d/%02d/%02d", calendario.date, calendario.month, calendario.year);
}

void csv_a_struct(mascota_t *mascotas, char *csv) {
    char *token = strtok_(csv, ";");
    strcpy_(mascotas->id_mascota, token);

    token = strtok_(NULL, ";");
    strcpy_(mascotas->nombre, token);
}

