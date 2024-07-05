#include "pet_feeder_system.h"
#include "arm_book_lib.h"
#include "mbed.h"
int main()
{
    UnbufferedSerial uartBle(PD_5, PD_6, 9600);
    petfeederSystemInit();
    while (true) {
        petfeederSystemUpdate();
    }
}

