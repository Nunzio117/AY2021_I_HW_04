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
    int32 value_digit;
    //int32 value_mv;
    int32 pot_value;
    int channel;
    int led_on;
    
    static void F_Sampling();
    
    static void F_Sampling(){
        // Start the ADC conversion
        ADC_DelSig_StartConvert();
        
        value_digit= ADC_DelSig_Read32(); 
        /* non ha usato la get resalt 16 siccome siamo in single 
        ended ad 16 bit (vedi datasheet). Sempre per questo motivo ha dichirato variabili int32*/
        
        // Stop the ADC conversion
        ADC_DelSig_StopConvert();
        
        if (value_digit < 0) value_digit= 0;
        if (value_digit > 65535) value_digit= 65535;
        
        if (!channel){
            
            if (value_digit <=15000){
                PWM_LED_WriteCounter(0);
                PWM_LED_WriteCompare(pot_value); 
                //channel=1; se vuoi che dia il valore solo se led acceso, togli commento e cancelli quello sotto
            }else{
                PWM_LED_WriteCompare(0); 
            }
            
            channel=1;
            
        }else{
        
            pot_value= value_digit;
            channel=0;
        }
    }
        
    
#endif

/* [] END OF FILE */
