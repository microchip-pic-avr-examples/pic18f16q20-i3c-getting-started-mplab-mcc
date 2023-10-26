/**
 * MVIO Generated Driver API Header File
 * 
 * @file mvio.h
 * 
 * @defgroup  mvio
 * 
 * @brief This file contains the API prototypes for the Multi-Voltage Input/Output (MVIO) driver.
 *
 * @version MVIO Source Code Driver Version 1.0.0
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

#ifndef MVIO_H
#define MVIO_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

/**
 * @ingroup mvio
 * @enum mvio_flag_t
 * @brief Contains the return codes for the VDDIO Voltage Monitor Ready Status API.
 */
 typedef enum
{
  VDDIO2, 
  VDDIO3
}mvio_flag_t; 

/**
 * @ingroup mvio
 * @brief Initializes the MVIO module. 
 * @param None.
 * @return None.
 */
void MVIO_Initialize(void);

/**
 * @ingroup mvio
 * @brief Checks if the VDDIOx monitor voltage is within the specified range.
 * @param [in] flag - Supply voltage source
 * @retval True - The VDDIOx supply voltage is within the acceptable range for operation
 * @retval False - The VDDIOx supply voltage is below the acceptable range for operation
 */
bool MVIO_IsVDDIOReady(mvio_flag_t flag);

/**
 * @ingroup mvio
 * @brief Setter function for the MVIO VDDIO2 callback handler.
 * @param [in] CallbackHandler - Pointer to a function called when VDDIO2 supply voltage loss/gain occurs
 * @return None.
 */
void MVIO_VDDIO2CallbackRegister(void (*handler)(void));

/**
 * @ingroup mvio
 * @brief Setter function for the MVIO VDDIO3 callback handler.
 * @param [in] CallbackHandler - Pointer to a function called when VDDIO3 supply voltage loss/gain occurs
 * @return None.
 */
void MVIO_VDDIO3CallbackRegister(void (*handler)(void));

/**
 * @ingroup mvio
 * @brief Implements the tasks for polled implementations of VDDIO2.
 * @param None.
 * @return None.
 */
void MVIO_VDDIO2Tasks(void);

/**
 * @ingroup mvio
 * @brief Implements the tasks for polled implementations of VDDIO3.
 * @param None.
 * @return None.
 */
void MVIO_VDDIO3Tasks(void);

#endif // MVIO_H
/**
 End of File
*/
