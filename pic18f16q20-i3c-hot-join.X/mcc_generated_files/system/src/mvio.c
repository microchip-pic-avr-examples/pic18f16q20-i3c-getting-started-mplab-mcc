/**
 * MVIO Generated Driver File
 * 
 * @file mvio.c
 * 
 * @ingroup mvio
 * 
 * @brief This file contains the API implementations for the Multi-Voltage Input/Output (MVIO) driver.
 *
 * @version MVIO Source Code Driver Version 1.0.0
 * @version MVIO Melody Peripheral Library (PLIB) version 1.0.0
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../mvio.h"

static void (*MVIO_VDDIO2Handler)(void) = NULL;
static void (*MVIO_VDDIO3Handler)(void) = NULL;

void MVIO_Initialize(void)
{
    //No initialization needed
}

bool MVIO_IsVDDIOReady(mvio_flag_t flag)
{
	bool mvioStatusFlag;
    if(flag == VDDIO2)
    {
        mvioStatusFlag = (bool)(MVIOSTATbits.VDDIO2RDY);
    }
    else if(flag == VDDIO3)
    {
        mvioStatusFlag = (bool)(MVIOSTATbits.VDDIO3RDY);
    }
    else
    {
        mvioStatusFlag = false;
    }
    return mvioStatusFlag;
}

void MVIO_VDDIO2CallbackRegister(void (*handler)(void))
{
    MVIO_VDDIO2Handler = handler;
}

void MVIO_VDDIO3CallbackRegister(void (*handler)(void))
{
    MVIO_VDDIO3Handler = handler;
}

void MVIO_VDDIO2Tasks(void)
{
    if(1 == PIR3bits.VDDIO2IF)
    {
        if(MVIO_VDDIO2Handler != NULL)
        {
            MVIO_VDDIO2Handler();
        }

        //Clear the VDDIO2 interrupt flag
        PIR3bits.VDDIO2IF = 0;
    }
}
void MVIO_VDDIO3Tasks(void)
{
    if(1 == PIR3bits.VDDIO3IF)
    {
        if(MVIO_VDDIO3Handler != NULL)
        {
            MVIO_VDDIO3Handler();
        }

        //Clear the VDDIO3 interrupt flag
        PIR3bits.VDDIO3IF = 0;
    }
}

/**
 End of File
*/