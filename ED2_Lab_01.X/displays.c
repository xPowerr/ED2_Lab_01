/*
 * File:   displays.c
 * Author: Gabriel
 *
 * Created on July 19, 2023, 6:23 PM
 */

#include <xc.h>
#include <stdint.h>
#include "displays.h"

// --------------- Frecuencia ---------------
#define _XTAL_FREQ 4000000



void mux(int selector){
    if (selector == 0){ // si el selector está en el primer display
        PORTC = displaylist[HEX1]; // enviar valor de display a PORTC
        PORTEbits.RE0 = 1; // alternar pines del muxeo
        PORTEbits.RE1 = 0;
    }
    if (selector == 1){ // si el selector está en el segundo display
        PORTC = displaylist[HEX2]; // enviar valor de display a PORTC
        PORTEbits.RE0 = 0; // alternar pines del muxeo
        PORTEbits.RE1 = 1;
    }
}

void display_hex(int value){
    if (value >= PORTD){ // si el valor del ADRESH es mayor que el contador
        PORTEbits.RE2 = 1; // encender alarma
    }
    else {
        PORTEbits.RE2 = 0; // si es menor que el contador, apagar alarma
    }
    
    //asignar el valor de ADRESH en hexadecimal en dos variables usando %16 y /16
    HEX1 = (value%16);
    HEX2 = (value/16);
}
