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
    #include "project.h"

    CY_ISR_PROTO (Custom_ISR_ADC);
    CY_ISR_PROTO (Custom_ISR_RX);
    
    volatile uint8 receveid; //variabile di flag per chimata interrupt del Timer
    
#endif
/* [] END OF FILE */
