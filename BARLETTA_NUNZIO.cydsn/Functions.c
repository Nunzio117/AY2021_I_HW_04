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

#include "Functions.h"
#include "InterruptRoutines.h"

void F_Sampling(){
    // Start the ADC conversion
    //ADC_DelSig_StartConvert();
        
    value_digit= ADC_DelSig_Read16(); 
    // Stop the ADC conversion
    //ADC_DelSig_StopConvert();
    
    if (value_digit < 0) value_digit= 0;
    if (value_digit > 1023) value_digit= 1023;
    
    if (!channel){
        if (value_digit <=300){
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
    PacketReadyFlag+=1;
}

void F_Read(){
    switch (ch_receveid){
        case 'B':
        case 'b':
            Pin_Blue_Write(1);
            Timer_Start();
            stop=0;
            break;
       case 'S':
       case 's':
            Pin_Blue_Write(0);
            Timer_Stop();
            stop=1;
            PacketReadyFlag=0;
            channel=1;
            //PWM_LED_WriteCompare(0); vedi se metterlo o meno
            break;
       default:
            break;
    }
}
/* [] END OF FILE */
