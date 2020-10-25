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

    CY_ISR_PROTO (Custom_ISR_ADC);
    CY_ISR_PROTO (Custom_ISR_RX);
    
    uint8 ch_receveid;
    
    volatile uint8 rec; //sulle flag e
    
    void F_Read();
#endif
/* [] END OF FILE */
