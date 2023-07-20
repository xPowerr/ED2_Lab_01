/*
 * File:   Setup_TMR0.c
 * Author: Gabriel
 *
 * Created on July 19, 2023, 5:59 PM
 */

#include "Setup_TMR0.h"

// --------------- Frecuencia ---------------
#define _XTAL_FREQ 4000000

void TMR0_init(void) {
    INTCONbits.T0IF = 0; // establece la bandera de la interrupcion del TMR0 apagada
    INTCONbits.T0IE = 1; // habilitar interrupcion del TMR0
    
    OPTION_REGbits.T0CS = 0; // establece el TMR0 como interno
    OPTION_REGbits.PSA = 0; // asignar el prescaler al TMR0
    
    OPTION_REGbits.PS = 111; // Prescaler de 256
    
    
}
