/* 
 * File:   Libreria para setup del TMR0
 * Author: Gabriel Carrera 21216
 * Comments: a
 * Revision history: a
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SETUP_TMR0_H
#define	SETUP_TMR0_H

#include <xc.h> // include processor files - each processor file is guarded.   
#include <stdint.h>

// --------------- Setup del TMR0 --------------- 
void TMR0_init(void);

#endif	/* XC_HEADER_TEMPLATE_H */

