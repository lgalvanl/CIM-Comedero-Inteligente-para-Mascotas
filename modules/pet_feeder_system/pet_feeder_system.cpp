//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "pet_feeder_system.h"

#include "sensor_balance.h"
#include "sensor_rfid.h"
#include "ble_com.h" 
#include "timer.h"

void petfeederSystemInit(){
  balanceSensorInit();
  
}


void petfeederSystemUpdate(){
    bleComUpdate();
}