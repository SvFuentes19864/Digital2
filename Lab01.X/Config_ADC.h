/*IE2023 ELECTRÓNICA DIGITAL 2
 * Author: SHAGTY VALERIA FUENTES GARCÍA
 * Carnet: 19864
 * Proyecto: Configuración del ADC
 * Hardware: PIC16F887
 * Created on 13 de julio de 2023 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded. 

#define _XTAL_FREQ 4000000

void adc_init(int channel);
int adc_read();
void adc_change_channel(int channel);
int adc_get_channel();

#endif	/* ADC_H */