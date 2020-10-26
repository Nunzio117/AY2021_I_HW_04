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
//include header
#include "Main.h" /*include relativo alle variabili ed alle funzioni usate qui nel "main.c" e
                    ingloba anche "interruptRoutines.h"*/

int main(void)
{
    CyGlobalIntEnable; //Enable global interrupts
    
    AMux_Init(); //inizializzazione del multiplexer (Mux). Tale funzione include anche lo start
    ADC_DelSig_Start(); //start del ADC usato, ma non inizio campionamento
    UART_Start(); //start del UART
    
    // start delle isr
    isr_ADC_StartEx(Custom_ISR_ADC);
    isr_RX_StartEx(Custom_ISR_RX);
    
    //inserimento valori di default per array di invio dati. Array definito in "Main.h"
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    
    //inizializzazione variabili definite in "interruptRoutines.h"
    receveid=0;
    channel=1; //inizializzato con valore 1 in modo da partire col campionamento del Potenziometro
    /*NOTA: potenziometro --> channel 1 del Mux;
            fotoresistenza --> channel 0 del.*/
    
    for(;;)
    {
        if(receveid){
            receveid=0;
            
            F_Sampling();//funzione definita qui di seguito ed inizializzata in "Main.h"
            
            F_Sampling();  
            /*NOTA: tale funzione è chiamata 2 volte di fila siccome in una sola chiamata 
            interrupt relativa alla componente timer, devo campionare 2 segnali (potenziometro 
            con channel=1 e fotoresistenza con channel=0). Lo scambio dei canali avviene 
            all'interno della funzione stessa come mostrato di seguito*/
            
            //comunicazione a terminale dell'array "DataBuffer" completato in "F_Sampling"
            UART_PutArray(DataBuffer, TRANSMIT_BUFFER_SIZE);
        }  
    }
    
}


void F_Sampling(){
    
    AMux_FastSelect(channel); //selezione del canale da parte del componente mux
    value_digit= ADC_DelSig_Read16(); //start e campionamento a 16 bit
    /*NOTA: siccome stiamo campionando ad 8 bit ed abbiamo impostato l'ADC in single ended mode
      come modalità di input (al posto della differential), da datasheet è consigliato non usare
      ADC_DelSig_Read8() ma ADC_DelSig_Read16(); tale funzione inoltre ritorna variabili int16
      per questio si è inizializzato value_digit come variabile int16 in "Main.h"*/
    
    /*controlli per evitare valori sotto lo zero e sopra i 255 siccome la variabile "value_digit"
    è una variabile int16 per quanto detto prima*/
    if (value_digit < 0) value_digit= 0;
    if (value_digit > 255) value_digit= 255;
    
    /*controllo del canale per poter preservare il valore del potenziometro in pot_value se siamo
    in channel=1, oppure accendere o spegnere il led a seconda di quanto riportato da value_digit
    se siamo in channel=0; pot_value è inizializzata in "Main.h"*/
    if (!channel){
        PWM_LED_WriteCounter(0);
        if (value_digit <=THRESHOLD){ //THRESHOLD è definita in "Main.h"
            PWM_LED_WriteCompare(pot_value); //funzione per controllo del pwm tramite pot_value
        }else{
            PWM_LED_WriteCompare(0);
        }
        channel=1; 
    }else{
        pot_value= value_digit;
        channel=0;
    }
    
    DataBuffer[channel+1] = value_digit; //completamento del array "DataBuffer"
    /*NOTA: siccome stiamo campionando ad 8 bit, sia il valore della fotoresistenza che del 
      potenziometro a cui siamo interessati, è un valore ricostruibile con un singolo byre
      quindi per questo motivo mandiamo 1 byte per il potenziometro ed 1 per la fotoresistenza.
      potenziometro --> DataBuffer[1]
      fotoresistenza --> Databuffer[2]*/
    
    //DataBuffer[3] = value_digit >> 8;
    //DataBuffer[4] = value_digit & 0xFF;
}


/* [] END OF FILE */
