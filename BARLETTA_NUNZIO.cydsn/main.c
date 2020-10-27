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
    DataBuffer[0] = 0xA0; //header del array
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0; //tail del array
    
    receveid=0;//inizializzazione di receveid, definita in "interruptRoutines.h"
    
    for(;;)
    {
        if(receveid){
            receveid=0;
            mean_value=0;
            
            for(channel=0; channel<N_CHANNEL; channel++){//channel è definita in "Main.h"
                F_Sampling();//funzione definita qui di seguito ed inizializzata in "Main.h"
            }
            /*NOTA: in tale applicazioe, tale funzione è chiamata 2 volte di fila (N_CHANNEL
            definita in "Main.h" ha come valore 2)siccome in una sola chiamata interrupt, relativa
            alla componente timer, devo campionare 2 segnali (potenziometro con channel=0 e 
            fotoresistenza con channel=1). Lo scambio dei canali avviene per mezzo del ciclo for*/
            
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
    
    if(channel>0){ 
        mean_value+=value_digit;/*variabile usata per possibili implementazioni future in cui ci 
                                sono più fotoresistenze da campionare; definita in "Main.h"*/
    }
    
    /*controllo del canale per poter accendere o spegnere il led a seconda di quanto riportato 
    da mean_value , solo se siamo arrivati all'ultimo channel; è importante settare il 
    potenziometro al channel==0 in modo da poter permettere tale applicazione*/
    if (channel==N_CHANNEL-1){
        
        mean_value=mean_value/(N_CHANNEL-1);/*non avrò un valore con la virgola ma una approssimazione
                                             siccome mean_value è intero e le variabili usate nella
                                             operazione non sono float*/
        
        if (mean_value<=THRESHOLD){ //THRESHOLD è definita in "Main.h"
            PWM_LED_WriteCompare(DataBuffer[1]); /*funzione per controllo del pwm tramite corretta
                                                   cella del DataBuffer in cui vi è il dato del
                                                   potenziometro*/
        }else{
            PWM_LED_WriteCompare(0);
        }  
    }
    
    DataBuffer[channel+1] = value_digit; //completamento del array "DataBuffer"
    /*NOTA: siccome stiamo campionando ad 8 bit, sia il valore della fotoresistenza che del 
      potenziometro a cui siamo interessati, è un valore ricostruibile con un singolo byre
      quindi per questo motivo mandiamo 1 byte per il potenziometro ed 1 per la fotoresistenza.
      potenziometro --> DataBuffer[1]
      fotoresistenza --> Databuffer[2]*/
}


/* [] END OF FILE */
