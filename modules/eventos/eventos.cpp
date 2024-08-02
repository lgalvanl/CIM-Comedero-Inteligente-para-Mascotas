//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "eventos.h"

#include "sensor_rfid.h"
#include "sensor_balance.h"
#include "timer.h"
#include "data_usuario.h"
#include "serial_com.h"
#include "cadenas.h"
#include "ble_com.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
//char* cadena_evento = NULL;
//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================
char eventos[MAX_EVENTOS][MAX_LARGO_CSV+1];
char nombre_alerta[10] = "";
bool HayEvento = false;
bool DataEnviar = false;
bool HayAlerta = false;

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void cadena_recortada(char *cadena_recortada,char *cadena);
void gramos_a_mandar(char *gramos_consumidos, int gramos_a_evento);
void registrarEvento(mascota_t *mascotas, int indice);

//=====[Implementations of public functions]===================================
void ocurreEventoUpdate(){
    if(HayEvento && DataRecibida){
        registrarEvento(arreglo_mascotas,IndiceActual);
    }
}



void mandar_data(){
    char final[19] = "final de eventos  ";
    if(indice_eventos < eventos_registrados){
        bleComStringWrite(eventos[indice_eventos]);
        indice_eventos++;
    } else {
        bleComStringWrite(final);
    }
}



void mandarAlerta(mascota_t *mascota){
        mascota->AlertaNotificada = true;
        HayAlerta = true;
}

//=====[Implementations of private functions]==================================

void cadena_recortada(char *cadena_recortada,char *cadena){
   strncpy_(cadena_recortada, cadena, 6); 
   cadena_recortada[6] = '\0'; 
}

void gramos_a_mandar(char *gramos_consumidos, int gramos_a_evento){
    char grs_no_consumidos[7] = "000grs";
    if(gramos_a_evento < 10){
        sprintf(gramos_consumidos, "00%dgrs",gramos_a_evento);
    } 
    if(gramos_a_evento < 100 && gramos_a_evento > 9){
        sprintf(gramos_consumidos, "0%dgrs",gramos_a_evento);
    }
    if(gramos_a_evento < 1000 && gramos_a_evento > 99){
        sprintf(gramos_consumidos, "%dgrs",gramos_a_evento);
    }
}

void registrarEvento(mascota_t *mascotas, int indice){
    if (eventos_registrados >= MAX_EVENTOS) {
        return;
    }
    int gramos_leidos = gramosConsumidos(primer_valor, segundo_valor);
    char horario[9] = "";

    char nombre_mod[6] = "";
    char hora_mod [6] = "";
    char gramos_mod[7] = "";

    char cadena_aux[MAX_LARGO_CSV+1] = "";
    time_a_char(mascotas[indice].UltimaDeteccion, horario);
    cadena_recortada(nombre_mod,mascotas[indice].nombre);
    cadena_recortada(hora_mod,horario);
    gramos_a_mandar(gramos_mod, gramos_leidos);
    sprintf(cadena_aux, "%s;%s;%s", gramos_mod,hora_mod,nombre_mod);
    strncpy_(eventos[eventos_registrados], cadena_aux,MAX_LARGO_CSV+1);
    eventos_registrados++;

    ActualizarContador(&mascotas[indice]);
    mascotas[indice].AlertaNotificada = false;
}
