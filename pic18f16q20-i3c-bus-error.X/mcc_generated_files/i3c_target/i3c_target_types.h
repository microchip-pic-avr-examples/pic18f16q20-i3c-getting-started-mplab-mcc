/**
 * I3C Generated Driver Types Header File
 * 
 * @file i3c_target_types.h
 * 
 * @ingroup i3c_target_driver
 * 
 * @brief This is the generated driver types header file for the I3C Target driver.
 *
 * @version I3C Target Source Code Driver Version 1.0.0
 *
 * @version I3C Melody Peripheral Library (PLIB) Version 1.0.0
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

#ifndef I3C_TARGET_TYPES_H
#define I3C_TARGET_TYPES_H

#include <stdint.h>

/**
 @ingroup i3c_target_driver
 @enum I3C_TARGET_BUS_ERROR_STATUS
 @brief Defines the different error states of I3C bus.
*/
enum I3C_TARGET_BUS_ERROR_STATUS
{
    I3C_TARGET_BUS_TE0_ERROR = 1,   /**< Invalid Broadcast Address or Dynamic Address */
    I3C_TARGET_BUS_TE1_ERROR = 2,   /**< Invalid CCC Code */
    I3C_TARGET_BUS_TE2_ERROR = 4,   /**< Invalid Write Data */
    I3C_TARGET_BUS_TE3_ERROR = 8,   /**< Invalid Assigned Address during the Dynamic Address Assignment */
    I3C_TARGET_BUS_TE4_ERROR = 16,  /**< Illegally formatted data during Dynamic Address Assignment */
    I3C_TARGET_BUS_TE5_ERROR = 32,  /**< Illegally formatted CCC frame */
    I3C_TARGET_BUS_TE6_ERROR = 64   /**< Corrupted R/W during Private Transfer */
};
 
/**
 @ingroup i3c_target_driver
 @enum I3C_CCC
 @brief Defines the different Common Command Codes (CCCs) of I3C. 
*/
enum I3C_CCC
{
   I3C_CCC_ENEC_B       = 0x00,   /**< Enable Events Command */
   I3C_CCC_DISEC_B      = 0x01,   /**< Disable Events Command */
   I3C_CCC_ENTAS0_B     = 0x02,   /**< Enter Activity State 0 */
   I3C_CCC_ENTAS1_B     = 0x03,   /**< Enter Activity State 1 */
   I3C_CCC_ENTAS2_B     = 0x04,   /**< Enter Activity State 2 */
   I3C_CCC_ENTAS3_B     = 0x05,   /**< Enter Activity State 3 */
   I3C_CCC_RSTDAA_B     = 0x06,   /**< Reset Dynamic Address Assignment */
   I3C_CCC_ENTDAA_B     = 0x07,   /**< Enter Dynamic Address Assignment */
   I3C_CCC_DEFTGTS_B    = 0x08,   /**< Define List of Targets */
   I3C_CCC_SETMWL_B     = 0x09,   /**< Set Max Write Length */
   I3C_CCC_SETMRL_B     = 0x0A,   /**< Set Max Read Length */
   I3C_CCC_ENTTM_B      = 0x0B,   /**< Enter Test Mode */
   I3C_CCC_SETBUSCON_B  = 0x0C,   /**< Set Bus Context */
   I3C_CCC_ENDXFER_B    = 0x12,   /**< Data Transfer Ending Procedure Control */
   I3C_CCC_ENTHDR0_B    = 0x20,   /**< Enter HDR Mode 0 */
   I3C_CCC_ENTHDR1_B    = 0x21,   /**< Enter HDR Mode 1 */
   I3C_CCC_ENTHDR2_B    = 0x22,   /**< Enter HDR Mode 2 */
   I3C_CCC_ENTHDR3_B    = 0x23,   /**< Enter HDR Mode 3 */
   I3C_CCC_ENTHDR4_B    = 0x24,   /**< Enter HDR Mode 4 */
   I3C_CCC_ENTHDR5_B    = 0x25,   /**< Enter HDR Mode 5 */
   I3C_CCC_ENTHDR6_B    = 0x26,   /**< Enter HDR Mode 6 */
   I3C_CCC_ENTHDR7_B    = 0x27,   /**< Enter HDR Mode 7 */
   I3C_CCC_SETXTIME_B   = 0x28,   /**< Exchange Timing Information */
   I3C_CCC_SETAASA_B    = 0x29,   /**< Set All Addresses to Static Addresses */
   I3C_CCC_RSTACT_B     = 0x2A,   /**< Target Reset Action */
   I3C_CCC_DEFGRPA_B    = 0x2B,   /**< Define List of Group Address */
   I3C_CCC_RSTGRPA_B    = 0x2C,   /**< Reset Group Address  */
   I3C_CCC_MLANE_B      = 0x2D,   /**< Multi-Lane Data Transfer Control */
   I3C_CCC_DBGACTION_B  = 0x58,   /**< Debug Action (Debug Specific command)*/
   I3C_CCC_SETHID_B     = 0x61,   /**< Hub updates 3-bit HID field (JEDEC Specific command)*/
   I3C_CCC_DEVCTRL_B    = 0x62,   /**< Configure hub and all devices behind hub (JEDEC Specific command)*/
	
   I3C_CCC_ENEC_D       = 0x80,   /**< Enable Events Command */
   I3C_CCC_DISEC_D      = 0x81,   /**< Disable Events Command  */
   I3C_CCC_ENTAS0_D     = 0x82,   /**< Enter Activity State 0 */
   I3C_CCC_ENTAS1_D     = 0x83,   /**< Enter Activity State 1 */
   I3C_CCC_ENTAS2_D     = 0x84,   /**< Enter Activity State 2 */
   I3C_CCC_ENTAS3_D     = 0x85,   /**< Enter Activity State 3 */
   I3C_CCC_RSTDAA_D     = 0x86,   /**< Reset Dynamic Address Assignment */
   I3C_CCC_SETDASA_D    = 0x87,   /**< Set Dynamic Address from Static Address */
   I3C_CCC_SETNEWDA_D   = 0x88,   /**< Set New Dynamic Address */
   I3C_CCC_SETMWL_D     = 0x89,   /**< Set Max Write Length */
   I3C_CCC_SETMRL_D     = 0x8A,   /**< Set Max Read Length */
   I3C_CCC_ENTTM_D      = 0x8B,   /**< Enter Test Mode */
   I3C_CCC_GETMRL_D     = 0x8C,   /**< Get Max Read Length */
   I3C_CCC_GETPID_D     = 0x8D,   /**< Get Provisioned ID */
   I3C_CCC_GETBCR_D     = 0x8E,   /**< Get Bus Characteristics Register  */
   I3C_CCC_GETDCR_D     = 0x8F,   /**< Get Device Characteristics Register */
   I3C_CCC_GETSTATUS_D  = 0x90,   /**< Get Device Status */
   I3C_CCC_GETACCCR_D   = 0x91,   /**< Get Accept Controller Role */
   I3C_CCC_ENDXFER_D    = 0x92,   /**< Data Transfer Ending Procedure Control */
   I3C_CCC_SETBRGTGT_D  = 0x93,   /**< Set Bridge Targets */
   I3C_CCC_GETMXDS_D    = 0x94,   /**< Get Max Data Speed */
   I3C_CCC_GETCAPS_D    = 0x95,   /**< Get Optional Feature Capabilities */
   I3C_CCC_SETROUTE_D   = 0x96,   /**< Set Route */
   I3C_CCC_D2DXFER_D    = 0x97,   /**< Device to Device(s) Tunneling Control */
   I3C_CCC_SETXTIME_D   = 0x98,   /**< Set Exchange Timing Information */
   I3C_CCC_GETXTIME_D   = 0x99,   /**< Get Exchange Timing Information */
   I3C_CCC_RSTACT_D     = 0x9A,   /**< Target Reset Action */
   I3C_CCC_SETGRPA_D    = 0x9B,   /**< Set Group Address */
   I3C_CCC_RSTGRPA_D    = 0x9C,   /**< Reset Group Address */
   I3C_CCC_MLANE_D      = 0x9D,   /**< Multi-Lane Data Transfer Control */
   I3C_CCC_DBGOPCODE_D  = 0xD7,   /**< Debug Network Adaptor Operation (Debug Specific command)*/
   I3C_CCC_DBGACTION_D  = 0xD8,   /**< Debug Action (Debug Specific command)*/ 
   I3C_CCC_DEVCAPS_D    = 0xE0    /**< Get device capabilities (JEDEC Specific command) */ 
};

/**
 @ingroup i3c_target_driver
 @enum I3C_TARGET_OPERATING_MODE
 @brief Defines the operating modes of the I3C Target and bus.
*/
enum I3C_TARGET_OPERATING_MODE
{
    I3C_TARGET_OPERATING_MODE_I2C_SDR                     = 0,   /**< The Target is operating in Legacy I2C mode; The bus is operating in Single Data Rate (SDR) mode */
    I3C_TARGET_OPERATING_MODE_I3C_SDR = 1,   /**< The Target is operating in I3C mode; The bus is operating in Single Data Rate (SDR) mode */
    I3C_TARGET_OPERATING_MODE_I2C_HDR                     = 2,   /**< The Target is operating in Legacy I2C mode; The bus is operating in High Data Rate (HDR) mode */
    I3C_TARGET_OPERATING_MODE_I3C_HDR = 3    /**< The Target is operating in I3C mode; The bus is operating in High Data Rate (HDR) mode*/
};

/**
 @ingroup i3c_target_driver
 @enum I3C_RESET_ACTION
 @brief Defines the different reset actions based on the defining byte value of RSTACT CCC.
*/
enum I3C_RESET_ACTION
{
    I3C_RESET_ACTION_NO_RESET                                   = 0x00, 
    I3C_RESET_ACTION_RESET_PERIPHERAL                           = 0x01, 
    I3C_RESET_ACTION_RESET_WHOLE_TARGET                         = 0x02,  
    I3C_RESET_ACTION_DEBUG_NETWORK_ADAPTER_RESET                = 0x03,  
    I3C_RESET_ACTION_VIRTUAL_TARGET_DETECT                      = 0x04,   
    I3C_RESET_ACTION_RETURN_TIME_TO_RESET_PERIPHERAL            = 0x81,   
    I3C_RESET_ACTION_RETURN_TIME_TO_RESET_WHOLE_TARGET          = 0x82,   
    I3C_RESET_ACTION_RETURN_TIME_TO_DEBUG_NETWORK_ADAPTER_RESET = 0x83,  
    I3C_RESET_ACTION_RETURN_VIRTUAL_TARGET_INDICATION           = 0x84, 
    I3C_RESET_ACTION_NO_ACTION_SET                              = 0xFF
};

/**
 @ingroup i3c_target_driver
 @enum I3C_TARGET_IBI_REQUEST_ERROR
 @brief Defines the error states of the In-Band Interrupt request operation.
*/
enum I3C_TARGET_IBI_REQUEST_ERROR
{
    I3C_TARGET_IBI_REQUEST_NO_ERROR,
    I3C_TARGET_IBI_REQUEST_SEND_BUFFER_SIZE_EXCEEDED,
    I3C_TARGET_IBI_REQUEST_NOT_IN_I3C_MODE,
    I3C_TARGET_IBI_REQUEST_IBI_DISABLED_ON_BUS
}; 

/**
 @ingroup i3c_target_driver
 @enum I3C_TARGET_BUFFER_RECEIVE_ERROR
 @brief Defines the error status of the buffer receive operation.
*/
enum I3C_TARGET_BUFFER_RECEIVE_ERROR
{
    I3C_TARGET_BUFFER_RECEIVE_NO_ERROR,
    I3C_TARGET_BUFFER_RECEIVE_BUFFER_SIZE_EXCEEDED
};

/**
 @ingroup i3c_target_driver
 @enum I3C_TARGET_BUFFER_TRANSMIT_ERROR
 @brief Defines the error status of the buffer transmit operation.
*/
enum I3C_TARGET_BUFFER_TRANSMIT_ERROR
{
    I3C_TARGET_BUFFER_TRANSMIT_NO_ERROR,
    I3C_TARGET_BUFFER_TRANSMIT_BUFFER_SIZE_EXCEEDED
}; 

/**
 @ingroup i3c_target_driver
 @enum I3C_TARGET_DATA_FLOW_DIRECTION
 @brief Defines the data flow direction of an I3C transaction.
*/
enum I3C_TARGET_DATA_FLOW_DIRECTION
{
    I3C_TARGET_DATA_TRANSMITTED, /**< Data transmitted via Private Read or In-Band Interrupt transaction */
    I3C_TARGET_DATA_RECEIVED /**< Data received via Private Write transaction */
};

/**
 @ingroup i3c_target_driver
 @struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS
 @brief Contains the status of the transaction complete operation.
*/
struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS
{
    enum I3C_TARGET_DATA_FLOW_DIRECTION dataFlowDirection;
    uint16_t numOfBytesReceived; 
}; 

#endif  // I3C_TARGET_TYPES_H
/**
 End of File
*/