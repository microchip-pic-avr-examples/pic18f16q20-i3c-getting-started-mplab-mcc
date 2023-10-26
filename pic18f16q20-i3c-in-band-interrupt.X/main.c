 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

void IBIDoneCallback(void);

volatile bool isIBIRequestCompleted = false;

int main(void)
{
    enum I3C_TARGET_IBI_REQUEST_ERROR ibiError;
    uint8_t newMandatoryByte = 0xAA;
    uint8_t ibiPaylaod[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //Without Mandatory Data Byte
    
    SYSTEM_Initialize();
    
    //Register user callback for IBI done interrupt. This will be used to
    //know the status of IBI process.
    I3C_Target_IBIDoneCallbackRegister(IBIDoneCallback);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 
    
    printf("Waiting for dynamic address assignment\r\n");
    while(I3C1_OperatingModeGet() != I3C_TARGET_OPERATING_MODE_I3C_SDR);
    printf("Dynamic address is assigned\r\n");
    
    printf("Press switch to send IBI\r\n\n");
	//Wait for switch press
	while(SW0_GetValue() == 1)
    {  
    }
    
    printf("Sending IBI request\r\n");
    ibiError = I3C_Target_IBIRequest(ibiPaylaod, 20);

    if(ibiError == I3C_TARGET_IBI_REQUEST_NOT_IN_I3C_MODE)
    {
        printf("IBIRequest: Target is not in I3C mode\r\n\n");
    }
    else if(ibiError == I3C_TARGET_IBI_REQUEST_IBI_DISABLED_ON_BUS)
    {
        printf("IBIRequest: IBI is not enabled on the bus\r\n\n");
    }
    else if(ibiError == I3C_TARGET_IBI_REQUEST_SEND_BUFFER_SIZE_EXCEEDED)
    {
        printf("IBIRequest: Software buffer size exceeded\r\n\n");    
    }
    else if(ibiError == I3C_TARGET_IBI_REQUEST_NO_ERROR)
    {
        printf("IBIRequest: No error\r\n\n");
    } 
    
    while(isIBIRequestCompleted == false)
    { 
    }
    isIBIRequestCompleted = false;
    printf("IBI request completed\r\n\n");
    
    printf("Press switch to send IBI\r\n\n");
	//Wait for switch press
	while(SW0_GetValue() == 1)
    {       
    }
          
    I3C_Target_IBIMandatoryDataByteSet(newMandatoryByte);
  
    printf("Sending IBI request\r\n");
    ibiError  = I3C_Target_IBIRequest(ibiPaylaod, 0);
    
    if(ibiError == I3C_TARGET_IBI_REQUEST_NOT_IN_I3C_MODE)
    {
        printf("IBIRequest: Target is not in I3C mode\r\n\n");
    }
    else if(ibiError == I3C_TARGET_IBI_REQUEST_IBI_DISABLED_ON_BUS)
    {
        printf("IBIRequest: IBI is not enabled on the bus\r\n\n");
    }
    else if(ibiError == I3C_TARGET_IBI_REQUEST_SEND_BUFFER_SIZE_EXCEEDED)
    {
        printf("IBIRequest: Software buffer size exceeded\r\n\n");    
    }
    else if(ibiError == I3C_TARGET_IBI_REQUEST_NO_ERROR)
    {
        printf("IBIRequest: No error\r\n\n");
    } 
    
    while(isIBIRequestCompleted == false)
    {  
    }
    isIBIRequestCompleted = false;
    printf("IBI request completed\r\n\n");
    
    while(1)
    {
    }    
}

void IBIDoneCallback(void)
{
    isIBIRequestCompleted = true;
}