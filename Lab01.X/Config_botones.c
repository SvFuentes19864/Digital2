#include "Config_botones.h"

void ioc_init (char pin){

    switch(pin){
    
        case 0:     // Si se desea utilizar la interrupción del botón 0
            
            IOCBbits.IOCB0 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB0 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 1:     // Si se desea utilizar la interrupción del botón 1
            
            IOCBbits.IOCB1 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB1 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 2:     // Si se desea utilizar la interrupción del botón 2
            
            IOCBbits.IOCB2 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB2 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 3:     // Si se desea utilizar la interrupción del botón 3
            
            IOCBbits.IOCB3 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB3 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 4:     // Si se desea utilizar la interrupción del botón 4
            
            IOCBbits.IOCB0 = 4;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB0 = 4;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 5:     // Si se desea utilizar la interrupción del botón 5
            
            IOCBbits.IOCB5 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB5 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 6:     // Si se desea utilizar la interrupción del botón 6
            
            IOCBbits.IOCB6 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB6 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 7:     // Si se desea utilizar la interrupción del botón 7
            
            IOCBbits.IOCB7 = 1;                 // Habilitamos puerto B para las ISR
            WPUBbits.WPUB7 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
    
    }

}

void pull_ups (char pin){

    switch(pin){
    
        case 0:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB0 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 1:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB1 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 2:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB2 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 3:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB3 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 4:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB0 = 4;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 5:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB5 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 6:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB6 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
            
        case 7:     // Si se desea utilizar la interrupción del botón 0
            
            WPUBbits.WPUB7 = 1;                 // Habilita la resistencia pull-up en puerto B
            
            break;
    
    }

}