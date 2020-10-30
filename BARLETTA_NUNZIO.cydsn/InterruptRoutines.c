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
#include "InterruptRoutines.h"

CY_ISR (Custom_ISR_ADC)
{
    //Read Timer status register to bring interrupt line low
    Timer_ReadStatusRegister();
    
    receveid=1; 
}

CY_ISR(Custom_ISR_RX){

    switch (UART_GetChar()){ //"UART_GetChar()" Non blocking call to get the latest data recieved
        case 'B':
        case 'b':
            Pin_Blue_Write(1);
            Timer_Start(); //start del Timer 
            PWM_LED_Start(); //start del PWM
            break;
       case 'S':
       case 's':
            Pin_Blue_Write(0);
            PWM_LED_Stop(); //stop del PWM
            Timer_Stop(); //stop del Timer
            break;
       default:
            break;
    }
}

/* [] END OF FILE */
