/*
 * File:   main.c
 * Author: Gabriel Carrera 21216
 *
 * Created on July 18, 2023, 12:20 AM
 */

// --------------- Palabra de Configuracion ---------------
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// --------------- Librerias ---------------
#include <xc.h>
#include <stdint.h>

// --------------- Frecuencia ---------------
#define _XTAL_FREQ 4000000

// --------------- Variables ---------------
char bandera = 0; // variable para el antirrebotes

// --------------- Prototipos ---------------
void setup(void);
void counter(void); // función del contador

// --------------- Loop principal ---------------
void main(void){
    setup();
    while(1){
    }
}

// --------------- Rutina de  interrupciones ---------------
void __interrupt() isr(void){ // interrupciones
    if (INTCONbits.RBIF == 1){ // revisar bandera de interrupcion del puerto B
        counter(); // llamar al contador
        INTCONbits.RBIF = 0; // limpiar bandera  
    }
    }

// --------------- Setup General ---------------
void setup(void){
    
// --------------- Definir analogicas ---------------
    ANSEL   =   0;
    ANSELH  =   0;
    
// --------------- Configurar puertos --------------- 
    TRISBbits.TRISB6 = 1; // RB6 como entrada
    TRISBbits.TRISB7 = 1; // RB7 como entrada
    
    TRISD = 0;
    
// --------------- Limpiar puertos ---------------    
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;    
    
// --------------- Habilitar pullups --------------- 
    OPTION_REGbits.nRBPU = 0; 
    WPUBbits.WPUB6 = 1;
    WPUBbits.WPUB7 = 1; 

// --------------- Banderas e interrupciones --------------- 
    INTCONbits.GIE = 1;   // Habilitar interrupciones globales
    INTCONbits.PEIE = 1;  // Habilitar interrupciones de perifericas
    INTCONbits.RBIE = 1;  // Habilitar interrupciones en PORTB
    
    IOCBbits.IOCB6 = 1;   // Habilitar interrupciones en RB6
    IOCBbits.IOCB7 = 1;   // Habilitar interrupciones en RB7
    
    INTCONbits.RBIF = 0;  // Limpiar bandera de interrupcion de PORTB
    
// --------------- Oscilador --------------- 
    OSCCONbits.IRCF = 0b110 ; // establecerlo en 4 MHz
    OSCCONbits.SCS = 1; // utilizar oscilador interno
}
    
// --------------- Funciones ---------------    
void counter(void){ 
    if (PORTBbits.RB6 == 0){ // revisar si se presiono el botón de incrementar
        bandera = 1;} // activar bandera
    if (PORTBbits.RB6 == 1 && bandera == 1){ // revisar si se dejo de presionar el botón y la bandera está en 1
        PORTD--; // incrementar
        bandera = 0; // limpiar bandera
    }
    if (PORTBbits.RB7 == 0){ // revisar si se presiono el botón de decrementar
        bandera = 2;} // activar bandera
    if (PORTBbits.RB7 == 1 && bandera == 2){ // revisar si se dejo de presionar el botón y la bandera está en 1
        PORTD++; // decrementar el puerto
        bandera = 0; // limpiar bandera
    }
}    
    

