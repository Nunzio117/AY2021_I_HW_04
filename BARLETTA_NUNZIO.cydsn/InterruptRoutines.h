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
#ifndef __INTERRUPT_ROUTINES_H
    #define __INTERRUPT_ROUTINES_H
    
    // Include required header files
   
    #include "cytypes.h"
    #include "stdio.h"
    
    #define BYTE_TO_SEND 2
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1

    CY_ISR_PROTO (Custom_ISR_ADC);
    CY_ISR_PROTO (Custom_ISR_RX);
    
    uint8_t DataBuffer1[TRANSMIT_BUFFER_SIZE];
    uint8_t DataBuffer2[TRANSMIT_BUFFER_SIZE];
    
    uint8 ch_receveid;
    
    volatile uint8 rec; //sulle flag e
    
    void F_Read();
#endif
/* [] END OF FILE */
