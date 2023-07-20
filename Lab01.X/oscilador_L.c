#include "Oscilador.h"

void configOsc (unsigned int frec){

    if(frec == 8){
    
        OSCCONbits.IRCF = 0b111;  // Primera frecuencia de oscilación 8 Mhz
        
    }
    
    if(frec == 4){
    
        OSCCONbits.IRCF = 0b110;  // Primera frecuencia de oscilación 4 Mhz
    
    }
    
    if(frec == 1){
    
        OSCCONbits.IRCF = 0b100;  // Primera frecuencia de oscilación 1 Mhz
    
    }
    
    if(frec == 500){
    
        OSCCONbits.IRCF = 0b011;  // Primera frecuencia de oscilación 500 Khz
    
    }
    
    if(frec == 250){
    
        OSCCONbits.IRCF = 0b010;  // Primera frecuencia de oscilación 250 Khz
    
    }
    
    if(frec == 125){
    
        OSCCONbits.IRCF = 0b001;  // Primera frecuencia de oscilación 500 Khz
    
    }
    
    OSCCONbits.SCS = 1;             // Habilitar el oscilador interno

}