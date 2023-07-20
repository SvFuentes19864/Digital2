#include "Config_tm0.h"

void t0_init(char prescaler){

    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 0;
    
    switch(prescaler){
    
        case 2:
            
            OPTION_REGbits.PS = 0b000;
            
            break;
            
        case 4:
            
            OPTION_REGbits.PS = 0b001;
            
            break;
            
        case 8:
            
            OPTION_REGbits.PS = 0b010;
            
            break;
            
        case 16:
            
            OPTION_REGbits.PS = 0b011;
            
            break;
            
        case 32:
            
            OPTION_REGbits.PS = 0b100;
            
            break;
            
        case 64:
            
            OPTION_REGbits.PS = 0b101;
            
            break;
            
        case 128:
            
            OPTION_REGbits.PS = 0b110;
            
            break;
            
        case 256:
            
            OPTION_REGbits.PS = 0b111;
            
            break;
    
    }

}

void reinicio_tmr0(int val_tm0){

    TMR0 = val_tm0;

}