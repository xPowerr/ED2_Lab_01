/* 
 * File:   Libreria para setup de displays
 * Author: Gabriel Carrera 21216
 * Comments: a
 * Revision history:  a
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DISPLAYS_H
#define	DISPLAYS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

//variables para el valor de ADC en hexadecimal
unsigned int HEX1 = 0;
unsigned int HEX2 = 0;

// incluir array de la tabla para el display
unsigned char displaylist [16] = {
    // TABLA PARA CATODO COMUN
    // BITS DP G F E D C B A
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01100111, //9
    0b01110111, //A
    0b01111100, //B
    0b00111001, //C
    0b01011110, //D
    0b01111001, //E
    0b01110001, //F 
};

// --------------- Setup de displays y del muxeo --------------- 
void mux(int selector); // funcion para muxear el display
void display_hex(int value); // funcion para preparar valor a enviar

#endif	/* DISPLAYS_H */

