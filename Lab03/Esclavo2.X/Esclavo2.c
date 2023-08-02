/* IE2023 ELECTRÓNICA DIGITAL 2
 * Author: SHAGTY VALERIA FUENTES GARCÍA
 * Carnet: 19864
 * Proyecto: LAB 3
 * Hardware: PIC16F887
 * Created on 27 de julio de 2023 */

//*****************************************************************************
// Palabra de configuración
//*****************************************************************************
// CONFIG1
#pragma config FOSC = EXTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

//*****************************************************************************
// Definición e importación de librerías
//*****************************************************************************

#include <xc.h>
#include <stdint.h>
#include "SPI.h"
#include "Oscilador.h"
#include "Config_ADC.h"

//*****************************************************************************
// Definición de variables
//*****************************************************************************
#define _XTAL_FREQ 4000000

uint8_t temporal = 0;

int valor_adc;

//*****************************************************************************
// Prototipos de funciones
//*****************************************************************************

void setup(void);

//*****************************************************************************
// Código de Interrupción 
//*****************************************************************************

void __interrupt() isr(void){
    
   if(SSPIF == 1){
       
       spiWrite(valor_adc);
       SSPIF = 0;
        
    }
}

//*****************************************************************************
// Código Principal
//*****************************************************************************

void main(void) {
    setup();
    
    while(1){
        valor_adc = adc_read();
        
        PORTB = adc_read();
       __delay_ms(250);
    }
    return;
}

//*****************************************************************************
// Función de Inicialización
//*****************************************************************************
void setup(void){
    
//_______________________CONFIGURACIÓN DE OSCILADOR_____________________________
    
    configOsc(4);           // Configura el oscilador interno a 4MHz
    
//________________________CONFIGURACIÓN DE PUERTOS______________________________
    
    ANSEL = 0;
    ANSELH = 0;
    
    TRISB = 0;
    TRISD = 0;
    
    PORTB = 0;
    PORTD = 0;
    
//__________________________CONFIGURACIÓN DE ADC________________________________
    
    adc_init(0);            // Configura el módulo ADC con referencia VDD y el canal 0  
    
//__________________________CONFIGURACIÓN DE INT________________________________
    
    INTCONbits.GIE = 1;         // Habilitamos interrupciones
    INTCONbits.PEIE = 1;        // Habilitamos interrupciones PEIE
    PIR1bits.SSPIF = 0;         // Borramos bandera interrupción MSSP
    PIE1bits.SSPIE = 1;         // Habilitamos interrupción MSSP
    TRISAbits.TRISA5 = 1;       // Slave Select
    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
   
}