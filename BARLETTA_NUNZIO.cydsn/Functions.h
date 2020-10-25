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
   
    #include "project.h"
    
    #define BYTE_TO_SEND 2
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1
    
    uint8_t DataBuffer[TRANSMIT_BUFFER_SIZE];
    
    int16 value_digit;
    //int32 value_mv;
    int16 pot_value;
  
    volatile uint8 channel;
    
    void F_Sampling();
    void F_SendBuffer();
    
#endif

/* [] END OF FILE */
