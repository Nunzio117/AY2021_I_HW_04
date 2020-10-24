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
#include "InterruptRoutines.h"
#include "Functions.h"

static char message1[20] = {'\0'};
static char message2[20] = {'\0'};

int main(void)
{
    CyGlobalIntEnable; // Enable global interrupts.
    // Start the components
    AMux_Init();
    ADC_DelSig_Start();
    UART_Start();
    PWM_LED_Start();
    isr_ADC_StartEx(Custom_ISR_ADC);
    isr_RX_StartEx(Custom_ISR_RX);
    
    DataBuffer1[0] = 0xA0;
    DataBuffer1[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    DataBuffer2[0] = 0xA0;
    DataBuffer2[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    // Initialize send flag
    PacketReadyFlag= 0;

    channel=1;// selezione il canale del potenziometro per avere valore di inzio per il pwm
    stop=0;
    
    // Start the ADC conversion (messo dentroal F_Sampling, vedi se funziona)
    // ADC_DelSig_StartConvert();
    
    for(;;)
    {
        if(rec){
            rec=0;
            AMux_FastSelect(channel);
            F_Sampling();
            sprintf(message1, "\nP:%d",pot_value);
            UART_PutString(message1);
            AMux_FastSelect(channel);
            F_Sampling();    
            sprintf(message2, "Va: %d\r\n",value_digit );
            UART_PutString(message2);
        }
//        if (PacketReadyFlag == 1 && !stop){
//           UART_PutString("1");
//        }
//        if (PacketReadyFlag == 2 && !stop){
//            //sprintf(message, "\n%d",PacketReadyFlag);
//            UART_PutString("2");
//            PacketReadyFlag= 0;
//            //sprintf(message, "Va: %d\r\n",value_digit );
//            //UART_PutString("\nP");
//            // Send out the data
//            //UART_PutArray(DataBuffer1, TRANSMIT_BUFFER_SIZE);
//            //UART_PutArray(DataBuffer2, TRANSMIT_BUFFER_SIZE);
//        }
        
    }
}

/* [] END OF FILE */
