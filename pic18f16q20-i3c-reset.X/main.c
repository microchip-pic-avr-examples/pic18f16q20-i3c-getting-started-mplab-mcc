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
void ResetPatternDetectedCallback(void);
void HotJoinRequest(void);

volatile bool resetPatternDetected = false;
enum I3C_RESET_ACTION resetAction = I3C_RESET_ACTION_NO_ACTION_SET;

int main(void)
{  
    enum I3C_TARGET_OPERATING_MODE;
    uint8_t resetCount = 0;
    
    SYSTEM_Initialize();
    
    //Register user callback for Reset action detected interrupt           
    I3C_Target_ResetPatternDetectedCallbackRegister(ResetPatternDetectedCallback); 

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptHighEnable(); 

    // Disable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighDisable(); 

    // Enable the Global Low Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); 

    // Disable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowDisable(); 
    
    // Reset I3C1RSTACT to the default value
    I3C1RSTACT = I3C_RESET_ACTION_NO_ACTION_SET;
    
    // Dynamic address assignment 
    HotJoinRequest();
   
    while(1)
    {
        if(resetPatternDetected)
        {
            resetPatternDetected = false;
 
            if(resetAction == I3C_RESET_ACTION_NO_RESET)
            {
                resetCount = 0;
                printf("Reset Action: I3C_RESET_ACTION_NO_RESET\r\n");
                //No action required to be taken               
            }
            else if(resetAction == I3C_RESET_ACTION_RESET_PERIPHERAL)
            {
                resetCount = 0;
                printf("Reset Action: I3C_RESET_ACTION_RESET_PERIPHERAL\r\n");
                
                printf("Resetting the I3C module\r\n");
                //Perform software peripheral reset
                I3C_Target_PeripheralReset();
                 
                I3C_Target_Initialize();
                // Reset I3C1RSTACT to the default value
                I3C1RSTACT = I3C_RESET_ACTION_NO_ACTION_SET;
                
                // Request for hot join 
                HotJoinRequest();
            }
            else if(resetAction == I3C_RESET_ACTION_RESET_WHOLE_TARGET)
            {
                resetCount = 0;
                printf("Reset Action: I3C_RESET_ACTION_RESET_WHOLE_TARGET\r\n");
                 
                printf("Resetting the microcontroller\r\n");
                while(!UART1.IsTxReady);
                //Soft reset of microcontroller
                RESET();
            }
            else if(resetAction == I3C_RESET_ACTION_NO_ACTION_SET)
            {
                if(resetCount == 0)
                {
                    //Reset Pattern detected w/o RSTACT for the first time
                    //Suggested user action is to reset the I3C module
                    resetCount++; // Increment counter
                    
                    printf("Reset Action: I3C_RESET_ACTION_NO_ACTION_SET\r\n");
                     
                    printf("Resetting the I3C module\r\n");
                    //Perform software peripheral reset
                    I3C_Target_PeripheralReset();
                    
                    I3C_Target_Initialize();
                    // Reset I3C1RSTACT to the default value
                    I3C1RSTACT = I3C_RESET_ACTION_NO_ACTION_SET;
                    
                    // Request for hot join
                    HotJoinRequest();
                    
                    //It is suggested for the user to detect RSTACT or GETSTATUS CCC
                    //and reset the reset-count to 0 after the first reset as mentioned in the  
                    //MIPI spec            
                }
                else if(resetCount > 0)
                {
                    //Reset Pattern detected w/o RSTACT for the second time
                    //Suggested user action is to reset the whole device
                    //Note that the counter can be reset by user software if GETSTATUS CCC is received
                    resetCount = 0; // Reset counter
                    printf("Reset Action: I3C_RESET_ACTION_NO_ACTION_SET\r\n");
    
                    printf("Resetting the microcontroller\r\n");                  
                    while(!UART1.IsTxReady);
                    //Soft reset of microcontroller
                    RESET();
                }
            }  
        }           
    }
}
 
void ResetPatternDetectedCallback(void)
{
    resetPatternDetected = true;
     
    resetAction = I3C_Target_ResetActionGetAndClear();  
}

void HotJoinRequest(void)
{  
    enum I3C_TARGET_HJ_REQUEST_ERROR hJRequestError = I3C_TARGET_HJ_REQUEST_NO_ERROR;
    
    printf("\n\nPress switch to send Hot Join request\r\n");
	//Wait for switch press
	while(SW0_GetValue() == 1);
	printf("Switch is pressed\r\n\n");
     
    printf("Requesting the Hot Join\r\n");
    hJRequestError = I3C_Target_HotJoinRequest();

	if(hJRequestError == I3C_TARGET_HJ_REQUEST_NO_ERROR)
	{
		printf("HotJoinRequest: No error\r\n\n");
	}
	else if(hJRequestError == I3C_TARGET_HJ_REQUEST_NOT_HJ_CAPABLE)
	{
		printf("HotJoinRequest: Target is not HJ capable\r\n\n");
	}
	else if(hJRequestError == I3C_TARGET_HJ_REQUEST_DYNAMIC_ADDRESS_ALREADY_ASSIGNED)
	{
		printf("HotJoinRequest: Dynamic address has already been assigned\r\n\n");
	}
	else if(hJRequestError == I3C_TARGET_HJ_REQUEST_HJ_DISABLED_ON_BUS)
	{
		printf("HotJoinRequest: HJ is disabled on the bus\r\n\n");
	}

	printf("Waiting for dynamic address\r\n");
	//Wait for Hot Join to complete
	while(I3C_Target_HotJoinStatusGet() == I3C_TARGET_HJ_PENDING);
	printf("Hot-Join completed successfully with dynamic address = 0x%02X\r\n\n", I3C1DADR);
}
