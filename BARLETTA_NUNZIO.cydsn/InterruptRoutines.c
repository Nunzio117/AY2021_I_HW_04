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
// Include header
#include "Functions.h"
#include "InterruptRoutines.h"
// Variables declaration 
uint8 ch_receveid;

CY_ISR (Custom_ISR_ADC)
{
    // Read Timer status register to bring interrupt line low
    Timer_ReadStatusRegister();
    
    AMux_FastSelect(channel);
    F_Sampling();
    // Write bytes in buffer  
    DataBuffer1[1] = value_digit >> 8;
    DataBuffer1[2] = value_digit & 0xFF;
   
    if (!channel){
        // Write bytes in buffer    
        DataBuffer2[1] = Pot_value >> 8;
        DataBuffer2[2] = Pot_value & 0xFF;
    }  
    PacketReadyFlag+=1;  
}

CY_ISR(Custom_ISR_RX){
// Non blocking call to get the latest data recieved
    ch_receveid = UART_GetChar();
// Set flags based on UART command
    switch (ch_receveid){
        case 'B':
        case 'b':
            Pin_Blue_Write(1);
            Timer_Start();
            break;
       case 'S':
       case 's':
            Pin_Blue_Write(0);
            Timer_Stop();
            break;
       default:
            break;
    }
}
/* [] END OF FILE */
