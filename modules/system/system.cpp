//=====[Libraries]=============================================================
#include "arm_book_lib.h"

#include "system.h"

#include "sensor_balance.h"
#include "sensor_rfid.h"
#include "data_usuario.h"
#include "serial_com.h"
#include "ble_com.h" 
#include "timer.h"
#include "eventos.h"
#include "non_blocking_delay.h"

static nonBlockingDelay_t mainDelay;

void SystemInit_(){
    InicializarContadorBateria();
    balanceSensorInit();
    rfidInit();
}


void SystemUpdate(){
    rfidUpdate();
    if(nonBlockingDelayRead(&mainDelay)==true){  
       SerialComUpdate();
       regDatosUpdate();
       ocurreEventoUpdate();
       ChequearContadorBateria();
       ChequearContadores();
       nonBlockingDelayInit(&mainDelay,SYSTEM_TIME_INCREMENT_MS);
    }
    
}