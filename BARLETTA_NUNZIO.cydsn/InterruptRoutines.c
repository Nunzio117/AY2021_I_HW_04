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
//#include "Functions.h"
#include "InterruptRoutines.h"
#include "project.h"

CY_ISR (Custom_ISR_ADC)
{
    // Read Timer status register to bring interrupt line low
    Timer_ReadStatusRegister();
    
    rec=1; 
}

CY_ISR(Custom_ISR_RX){
// Non blocking call to get the latest data recieved
    ch_receveid = UART_GetChar();
// Set flags based on UART command
    F_Read();
}

/* [] END OF FILE */
