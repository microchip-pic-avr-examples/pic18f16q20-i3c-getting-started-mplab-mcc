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
void PrintOperatingMode(void);

int main(void)
{
	enum I3C_TARGET_HJ_REQUEST_ERROR hJRequestError = I3C_TARGET_HJ_REQUEST_NO_ERROR;

	SYSTEM_Initialize();

	// If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
	// If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
	// Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

	PrintOperatingMode();

	printf("Press switch to send Hot Join request\r\n");
	//Wait for switch press
	while(SW0_GetValue() == 1);
	printf("Switch is pressed\r\n\n");

	printf("Hot Join Request\r\n");
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

	PrintOperatingMode();

	while(1)
	{
	}

}

void PrintOperatingMode(void)
{
    enum I3C_TARGET_OPERATING_MODE opMode;

    const char *operatingMode;

    opMode = I3C_Target_OperatingModeGet();

    if(opMode == I3C_TARGET_OPERATING_MODE_I2C_SDR)
    {
        operatingMode = "The Target is in Legacy I2C mode the bus is in Single Data Rate (SDR) mode";
    }
    else if(opMode == I3C_TARGET_OPERATING_MODE_I3C_SDR)
    {
        operatingMode = "The Target is in I3C mode and the bus is in Single Data Rate (SDR) mode";
    }
    else if(opMode == I3C_TARGET_OPERATING_MODE_I2C_HDR)
    {
        operatingMode = "The Target is in Legacy I2C mode and the bus is in High Data Rate (HDR) mode";
    }
    else if(opMode == I3C_TARGET_OPERATING_MODE_I3C_HDR)
    {
        operatingMode = "The Target is in I3C mode and the bus is in High Data Rate (HDR) mode";
    }
    printf("Current Operating mode : %s\r\n\n", operatingMode);
}

