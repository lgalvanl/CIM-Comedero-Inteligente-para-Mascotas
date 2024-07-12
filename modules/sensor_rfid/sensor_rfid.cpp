#include "mbed.h"
#include "non_blocking_delay.h"
#include "sensor_rfid.h"
#include "MFRC522.h"
#include "datos_usuario.h"
#include "ds3231.h"
#include "cadenas.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
#define RFID_RESET PD_15
#define RFID_SPI_MOSI PA_7
#define RFID_SPI_MISO PA_6
#define RFID_SPI_SCLK PA_5
#define RFID_SPI_CS PD_14 
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
static nonBlockingDelay_t rfid_delay;
static rfidEstado_t rfidEstado = RFID_ESPERO_ID;
bool Masc = false;
bool SeDetectaMascota = false;
static char buffer[20]= {'\0'};

MFRC522 rfidChip(RFID_SPI_MOSI, RFID_SPI_MISO, RFID_SPI_SCLK, RFID_SPI_CS, RFID_RESET);
//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================
void rfidInit(){
    tickInit();
    rfidChip.PCD_Init();
}

void rfidUpdate(){
    char* uid=NULL;
    //printf("rfidupdate\n");
    switch (rfidEstado) {
        case RFID_ESPERO_ID:
            if (!rfidChip.PICC_IsNewCardPresent()) {
                //printf("entro a espero id\n");
                SeDetectaMascota = false;
                break; 
            }
            rfidEstado = RFID_LLAVERO_DETECTADO;
            break;
        
        case RFID_LLAVERO_DETECTADO:
        //printf("auxilio");
            if (!rfidChip.PICC_ReadCardSerial()) {
                break; 
            }
            for (uint8_t i = 0; i < rfidChip.uid.size; i++) {
                sprintf(buffer + i * 2, "%02X", rfidChip.uid.uidByte[i]);
            }
            uid = rfidGetUid();
            //printf("valor leido: %s\n", uid);
            SeDetectaMascota = true;
            break;
    }
}

void regDatosRFIDUpdate() {
    
    if (SeDetectaMascota && !Masc) {
        printf("Primera deteccion\n");
        Masc = true;
        LedBlue = 1;
    } else if (!SeDetectaMascota && Masc) {
        printf("Ultima deteccion\n");
        LedBlue = 0;
        Masc = false;
    }
    rfidEstado = RFID_ESPERO_ID;
}

//=====[Implementations of private functions]==================================

char* rfidGetUid(){
    if(rfidEstado!=RFID_LLAVERO_DETECTADO)
        return NULL;

    char* aux=strndup_(buffer,10);
    buffer[0]={'\0'};
    //Ya procese el uid ingresado a si que vuelvo a modo de esepra
    return aux;

}