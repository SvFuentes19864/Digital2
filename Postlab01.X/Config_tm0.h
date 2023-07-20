/*IE2023 ELECTRÓNICA DIGITAL 2
 * Author: SHAGTY VALERIA FUENTES GARCÍA
 * Carnet: 19864
 * Proyecto: Conversión a hex.
 * Hardware: PIC16F887
 * Created on 13 de julio de 2023 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TM0_H
#define	TM0_H

#include <xc.h> // include processor files - each processor file is guarded.  

void t0_init(char prescaler); 
void reinicio_tmr0(int val_tm0);

#endif	/* TM0_H */