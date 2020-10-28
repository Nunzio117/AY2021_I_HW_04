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
#ifndef __MAIN_H
    #define __MAIN_H
   
    #include "InterruptRoutines.h" /*include relativo alle interrupt e variabili annesse. Include
                                     anche "cytypes.h", "stdio.h" e "project.h"*/
    
    #define BYTE_TO_SEND 2 //settato per campionamento ad 8 bit di 2 segnali
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1
    
    #define THRESHOLD 130 /*Threshold per decisione su accensione o meno del LED. Settato per
                            campionamento ad 8 bit*/
    #define N_CHANNEL 2 //numero dei canali dei segnali usati per l'applicazione 
    
    int16 value_digit; //variabile per valore di lettura del campionamento
    int16 value_mv; //variabile per valore campionato convertito in mv
    int16 mean_value; //variabile per valore medio assunto dai canali che campionano segnali di fotoresistenze
    uint8 channel; //variabile per indicare canale di campionamento
    /*NOTA: potenziometro --> channel 0 del Mux;
            fotoresistenza --> channel 1 del Mux.*/
    
    uint8_t DataBuffer[TRANSMIT_BUFFER_SIZE]; //array di trasmissione dati al terminale
    
    void F_Sampling(); //funzione adibita al campionamento, usata ed esplicitata in "main.c"
    
#endif

/* [] END OF FILE */
