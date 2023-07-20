/*IE2023 ELECTRÓNICA DIGITAL 2
 * Author: SHAGTY VALERIA FUENTES GARCÍA
 * Carnet: 19864
 * Proyecto: LAB 1
 * Hardware: PIC16F887
 * Created on 13 de julio de 2023 */

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT    // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF               // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF              // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF              // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF                 // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF                // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF              // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF               // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF              // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF                // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V           // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF                // Flash Program Memory Self Write Enable bits (Write protection off)

//******************************************************************************
//Librerías
//******************************************************************************

#include <xc.h>
#include <pic16f887.h>
#include <stdint.h>
#include <stdio.h>
#include "Oscilador.h"
#include "Config_botones.h"
#include "Config_ADC.h"
#include "Config_tm0.h"
#include "Separar_nibbles.h"

//******************************************************************************
// Variables
//******************************************************************************

#define _XTAL_FREQ 4000000

int display;
unsigned char nibbleAlto, nibbleBajo;
unsigned char valor_adc;

uint8_t         UNI;                            // UNIDADES DE LOS DISPLAYS
uint8_t         DEC;                            // DECENAS DE LOS DISPLAYS

//******************************************************************************
// Arreglos
//******************************************************************************

char const tabla[16] = {0b10111111,     // TABLA DE CONVERSIÓN DISPLAYS
                        0b10000110, 
                        0b11011011, 
                        0b11001111, 
                        0b11100110, 
                        0b11101101, 
                        0b11111101, 
                        0b10000111, 
                        0b11111111, 
                        0b11101111, 
                        0b11110111, 
                        0b11111100, 
                        0b10111001, 
                        0b11011110, 
                        0b11111001, 
                        0b11110001};   // 0 - 15

//******************************************************************************
// Prototipos de funiones
//******************************************************************************

void setup(void);

//******************************************************************************
// Interrupciones
//******************************************************************************

void __interrupt() isr(void)
{
    if(INTCONbits.RBIF){
    
        INTCONbits.RBIF = 0;        // Limpia la bandera de interrupción
        if (!PORTBbits.RB0){
        
            PORTC++;
            __delay_ms(500);
        
        }
        
        if (!PORTBbits.RB1){
        
            PORTC--;
            __delay_ms(500);
        
        }
    }
    
    if(INTCONbits.T0IF){  
        
        if (display == 0){
            
            PORTEbits.RE0 = 1;
            PORTEbits.RE1 = 0;
            
            PORTD = tabla[UNI];                 // UNIDADES
            
            display = 1;
        
        }
        
        else if (display == 1){
        
           PORTEbits.RE0 = 0;
           PORTEbits.RE1 = 1;
           
           PORTD = tabla[DEC];                 // DECENAS
           
           display = 0; 
        
        }
        
        INTCONbits.T0IF = 0;
        TMR0 = 178;
    }
}

//******************************************************************************
// Código principal
//******************************************************************************

void main(void) {
    
    setup();
    
    while(1){
        
        valor_adc = adc_read();
        
        separar_nibbles (valor_adc, &nibbleAlto, &nibbleBajo);
        
        UNI = nibbleAlto;
        DEC = nibbleBajo;
        
        if(valor_adc == PORTC){
        
            PORTBbits.RB2 = 1;
            __delay_ms(500);
        
        }
        
        else {
        
            PORTBbits.RB2 = 0;
        
        }
    
    }
}

//******************************************************************************
// Subrutines/funciones
//******************************************************************************

void setup(){
    
    configOsc(4);
    
//________________________CONFIGURACIÓN DE PUERTOS______________________________

    ANSELH = 0;
    ANSEL = 0;
    
    TRISC = 0;
    PORTC = 0;
    TRISB = 0b00000011;
    PORTB = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
    
//_______________________CONFIGURACIÓN DE PULLUPS_______________________________    
    
    OPTION_REGbits.nRBPU = 0;           // Habilita las resistencias pull-up internas
    
    ioc_init(0);
    ioc_init(1);
    
//____________________CONFIGURACIÓN DE INTERRUPCIONES___________________________  
    
    
    INTCONbits.GIE = 1;                 // Habilitamos las interrupciones globales
    INTCONbits.RBIE = 1;                // Habilitamos las interrupciones del purto B
    INTCONbits.T0IE = 1;                // Habilitamos las interrupciones del timer 0
    INTCONbits.T0IF = 0;                // Borramos la bandera del timer 0

//_________________________CONFIGURACIÓN DE TMR0________________________________

    t0_init(128);                     // Prescaler para desborde de 6 ms
    reinicio_tmr0(178);                 // Valor a cargar para un desborde de 6 ms
    
//__________________________CONFIGURACIÓN DE ADC________________________________
    
    adc_init(0);

}