/*IE2023 ELECTRÓNICA DIGITAL 2
 * Author: SHAGTY VALERIA FUENTES GARCÍA
 * Carnet: 19864
 * Proyecto: Interrupción de botones
 * Hardware: PIC16F887
 * Created on 13 de julio de 2023 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTBOT_H
#define	INTBOT_H

#include <xc.h> // include processor files - each processor file is guarded.  

void ioc_init (char pin);  
void pull_ups (char pin);

#endif	/* INTBOT_H */