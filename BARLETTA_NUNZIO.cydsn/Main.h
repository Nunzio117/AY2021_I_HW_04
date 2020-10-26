/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef __FUNCTIONS_H
    #define __FUNCTIONS_H
   
    #include "InterruptRoutines.h" /*include relativo alle interrupt e variabili annesse. Include
                                     anche "cytypes.h", "stdio.h" e "project.h"*/
    
    #define BYTE_TO_SEND 2 // settato per campionamento ad 8 bit 
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1
    
    #define THRESHOLD 100 /*Threshold per decisione su accensione o meno del LED. Settato per
                            campionamento ad 8 bit*/

    int16 value_digit; //valore di lettura del campionamento
    int16 pot_value; //valore del potenziometro
    
    uint8_t DataBuffer[TRANSMIT_BUFFER_SIZE]; //array di trasmissione dati al terminale
    
    void F_Sampling(); //funzione usata ed esplicitata in "main.c"
    
#endif

/* [] END OF FILE */
