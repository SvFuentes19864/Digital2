#include "Separar_nibbles.h"

void separar_nibbles(unsigned char byte, unsigned char *nibbleAlto, unsigned char *nibbleBajo){

    *nibbleAlto = byte >> 4;           // Obtener el nibble alto utilizando un puntero (unidades)
    *nibbleBajo = byte & 0x0F;         // Obtener el nibble bajo utilizando un puntero (decenas)

}