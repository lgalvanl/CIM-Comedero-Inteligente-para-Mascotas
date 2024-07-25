#include "mbed.h"
#include "non_blocking_delay.h"
#include "sensor_rfid.h"
#include "MFRC522.h"
#include "cadenas.h"
#include "ds3231.h"
#include "timer.h"
#include <stdio.h>  
#include <stdbool.h>  
#include <string.h> 
#include "arm_book_lib.h"
#include "sensor_balance.h"
#include "data_usuario.h"
#include "eventos.h"
#include "ble_com.h"
//=====[Declaration of private defines]========================================
#define RFID_RESET PD_15
#define RFID_SPI_MOSI PA_7
#define RFID_SPI_MISO PA_6
#define RFID_SPI_SCLK PA_5
#define RFID_SPI_CS PD_14 

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut LedBlue(LED2);


//=====[Declaration and initialization of private global variables]============
MFRC522 rfidChip(RFID_SPI_MOSI, RFID_SPI_MISO, RFID_SPI_SCLK, RFID_SPI_CS, RFID_RESET);
nonBlockingDelay_t rfid_delay;
rfidEstado_t rfidEstado = RFID_ESPERO_ID;
bool Masc = false;
bool SeDetectaMascota = false;

char buffer[MAX_LARGO_UID + 1] = {'\0'};
char* uid = NULL;
//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================


void rfidInit() {
    tickInit();
    rfidChip.PCD_Init();
}

void rfidUpdate(){
    switch (rfidEstado) {
        case RFID_ESPERO_ID:
            if (!rfidChip.PICC_IsNewCardPresent()) {
                SeDetectaMascota = false;
                break; 
            }
            rfidEstado = RFID_LLAVERO_DETECTADO;
            break;
        case RFID_LLAVERO_DETECTADO:
            if (!rfidChip.PICC_ReadCardSerial()) {
                break; 
            }
            for (uint8_t i = 0; i < rfidChip.uid.size; i++) {
                sprintf(buffer + i * 2, "%02X", rfidChip.uid.uidByte[i]);
            }
            uid = rfidGetUid();
            SeDetectaMascota = true;
            break;
    }
}

void regDatosUpdate() {  
  HayEvento = false;    
  if (SeDetectaMascota && !Masc) {  
        Masc = true;
        LedBlue = 1;
        primer_valor = gramosPesados();
    } else if (!SeDetectaMascota && Masc) {
        LedBlue = 0;
        Masc = false;
        segundo_valor = gramosPesados();
        IndiceActual = detectarMascota(uid);
    }
    rfidEstado = RFID_ESPERO_ID;
}

char* rfidGetUid(){
    if(rfidEstado!=RFID_LLAVERO_DETECTADO)
        return NULL;
    char* aux=strndup_(buffer,10);
    buffer[0]={'\0'};
    return aux;

}
//=====[Implementations of private functions]==================================

