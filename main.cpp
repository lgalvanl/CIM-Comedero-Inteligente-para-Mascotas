#include "system.h"
//#include "arm_book_lib.h"
//#include "mbed.h"

int main(){
    SystemInit();
    while (true) {
        SystemUpdate();
    }
}

