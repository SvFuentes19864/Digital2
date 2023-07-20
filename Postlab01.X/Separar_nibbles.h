/*IE2023 ELECTRÓNICA DIGITAL 2
 * Author: SHAGTY VALERIA FUENTES GARCÍA
 * Carnet: 19864
 * Proyecto: Conversión a hex.
 * Hardware: PIC16F887
 * Created on 13 de julio de 2023 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef S_NIBBLES
#define	S_NIBBLES

#include <xc.h> // include processor files - each processor file is guarded. 

void separar_nibbles(unsigned char byte, unsigned char *nibbleAlto, unsigned char *nibbleBajo);  

#endif	/* S_NIBBLES */