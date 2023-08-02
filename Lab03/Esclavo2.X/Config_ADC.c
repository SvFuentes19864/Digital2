#include "Config_ADC.h"

void adc_init(int channel){

    // Paso 1 Seleccionar puerto de entrada

    TRISAbits.TRISA0 = 1;
    ANSELbits.ANS0 = 1;
    
    // Paso 2 Configurar módulo ADC canal 0
    
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS0 = 1;       // Fosc/ 8
    
    ADCON1bits.VCFG1 = 0;       // Ref VSS
    ADCON1bits.VCFG0 = 0;       // Ref VDD
    
    ADCON1bits.ADFM = 0;        // Justificado hacia izquierda
    
    ADCON0bits.CHS = channel;   // Elegir el canal
    
    ADCON0bits.ADON = 1;        // Habilitamos el ADC
    __delay_us(100);

}

int adc_read(){

    // Iniciamos conversión del ADC
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO == 1);
        __delay_ms(10);
        return ADRESH;

}

void adc_change_channel(int channel){

    switch(channel){
    
        case 0:
            
            ADCON0bits.CHS = 0b0000;   // Elegir el canal
            
            break;
            
        case 1:
            
            ADCON0bits.CHS = 0b0001;   // Elegir el canal
            
            break;
          
        case 2:
            
            ADCON0bits.CHS = 0b0010;   // Elegir el canal
            
            break;
            
        case 3:
            
            ADCON0bits.CHS = 0b0011;   // Elegir el canal
            
            break;
            
        case 4:
            
            ADCON0bits.CHS = 0b0100;   // Elegir el canal
            
            break;
            
        case 5:
            
            ADCON0bits.CHS = 0b0101;   // Elegir el canal
            
            break;
            
        case 6:
            
            ADCON0bits.CHS = 0b0110;   // Elegir el canal
            
            break;
            
        case 7:
            
            ADCON0bits.CHS = 0b0111;   // Elegir el canal
            
            break;
            
        case 8:
            
            ADCON0bits.CHS = 0b1000;   // Elegir el canal
            
            break;
            
        case 9:
            
            ADCON0bits.CHS = 0b1001;   // Elegir el canal
            
            break;
    
    }

}

int adc_get_channel(){

    return ADCON0bits.CHS;

}