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
    
    int16 value_digit;
    //int32 value_mv;
    int16 pot_value;
   
    uint8 PacketReadyFlag;
    volatile uint8 stop;
    volatile uint8 channel;
    void F_Sampling();
    
#endif

/* [] END OF FILE */
