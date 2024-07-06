//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "pet_feeder_system.h"

#include "sensor_balance/sensor_balance.h"
#include "ble_com.h" 

void petfeederSystemInit()
{
balanceSensorInit();

}


void petfeederSystemUpdate()
{
    bleComUpdate();
}