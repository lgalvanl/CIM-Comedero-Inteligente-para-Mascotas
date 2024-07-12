//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "system.h"

#include "sensor_balance.h"
#include "sensor_rfid.h"
#include "ble_com.h" 
#include "timer.h"

void SystemInit(){
  balanceSensorInit();
  
}


void SystemUpdate(){
    bleComUpdate();
}