/**
 * I3C1 Generated Driver Header File
 *
 * @file i3c1.h
 *
 * @defgroup i3c_target_driver I3C TARGET DRIVER
 *
 * @brief This file contains API prototypes and other data types for the I3C1 Target DMA driver.
 *
 * @version I3C Target DMA Source Code Driver Version 1.0.0
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

#ifndef I3C1_H
#define I3C1_H

#include <stdbool.h>
#include <stdint.h>
#include "i3c_target_types.h"

/**
 * @ingroup i3c_target_driver
 * @brief Initializes the I3C1 module. 
 * @param None.
 * @return None.
 */
void I3C1_Initialize(void);

/**
 * @ingroup i3c_target_driver
 * @brief Enables the I3C1 Target module. 
 * @param None.  
 * @return None. 
 */
void I3C1_Enable(void);

/**
 * @ingroup i3c_target_driver
 * @brief Disables I3C1 Target module. 
 * @param None.
 * @return None.  
 */
void I3C1_Disable(void);

/**
 * @ingroup i3c_target_driver
 * @brief Sets the target to always ACK a Private Read and Private Write transaction request.
 * @note This API is limited only to Private Write transactions for PIC18F06/16Q20 B2 silicon revision. 
 * @return None.  
 */
void I3C1_AllPrivateTransactionACK(void);

/**
 * @ingroup i3c_target_driver
 * @brief Sets the target to always NACK a Private Read and Private Write transaction request.
 * @note This API is limited only to Private Write transactions for PIC18F06/16Q20 B2 silicon revision. 
 * @param None. 
 * @return None.   
 */
void I3C1_AllPrivateTransactionNACK(void);

/**
 * @ingroup i3c_target_driver
 * @brief Enables the one-shot ACK of a Private Read and Private Write transaction request.
 * @note This API is limited only to Private Write transactions for PIC18F06/16Q20 B2 silicon revision. 
 * @param None. 
 * @return None.  
 */
void I3C1_NextPrivateTransactionACK(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the maximum write length configured for a Private Write transaction. 
 * @param None. 
 * @return Maximum write length for a Private Write transaction.
 */
uint16_t I3C1_MaxWriteLengthGet(void);

/**
 * @ingroup i3c_target_driver
 * @brief Sets the maximum write length configured for a Private Write transaction. 
 * @param [in] maxWriteLen - Maximum write length for a Private Write transaction. 
 * @return None.
 */
void I3C1_MaxWriteLengthSet(uint16_t maxWriteLen);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the maximum read length configured for a Private Read transaction. 
 * @param None. 
 * @return Maximum read length for a Private Read transaction. 
 */
uint16_t I3C1_MaxReadLengthGet(void);

/**
 * @ingroup i3c_target_driver
 * @brief Sets the maximum read length for a Private Read transaction. 
 * @param [in] maxReadLen - Maximum read length for a Private Read transaction. 
 * @return None.
 */
void I3C1_MaxReadLengthSet(uint16_t maxReadLen);

/**
 * @ingroup i3c_target_driver
 * @brief Configures the buffer for next Private Write transaction to receive data. The status of the Private Write transaction can be checked using the transaction complete callback. 
 * @param [in] rxBuf - Pointer to the buffer in which data needs to be received.
 * @note Lifetime of the buffer must be maintained till data is received.
 * @param [in] len - Size of the buffer. 
 * @note Buffer size must be greater than or equal to expected size of data received in the next Private Write transaction.
 * @return Status of the I3C1 buffer receive operation as described in I3C_TARGET_BUFFER_RECEIVE_ERROR. 
 */
enum I3C_TARGET_BUFFER_RECEIVE_ERROR I3C1_BufferReceive(uint8_t *rxBuf, uint16_t len);

/**
 * @ingroup i3c_target_driver
 * @brief Configures the buffer for next Private Read transaction to transmit data. The status of the Private Read transaction can be checked using the transaction complete callback.
 * @param [in] txBuf - Pointer to the buffer from which data needs to be transmitted. 
 * @note Lifetime of the buffer must be maintained till data is transmitted.
 * @param [in] len - Number of data bytes to be transmitted. 
 * @return Status of the I3C1 buffer transmit operation as described in I3C_TARGET_BUFFER_TRANSMIT_ERROR. 
 */
enum I3C_TARGET_BUFFER_TRANSMIT_ERROR I3C1_BufferTransmit(uint8_t *txBuf, uint16_t len);

/**
 * @ingroup i3c_target_driver
 * @brief Reads one byte from the Receive Buffer. 
 * @note This API must be called to read only the residue bytes available in the hardware buffer.
 * @pre I3C1_BufferReceive() function is already called.
 * @param None. 
 * @return Byte read from the Receive Buffer.
 */
uint8_t I3C1_ByteReceive(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the status of the Transmit File In, File Out (FIFO) buffer.
 * @param None.
 * @retval True - Transmit FIFO is empty.
 * @retval False - Transmit FIFO is not empty. 
 */
bool I3C1_IsTxFIFOEmpty(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the status of the Transmit buffer. 
 * @param None.
 * @retval True - Transmit Buffer is empty.
 * @retval False - Transmit Buffer is not empty.  
 */
bool I3C1_IsTxBufferEmpty(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the status of the Receive buffer. 
 * @param  None.
 * @retval True - Receive Buffer is full.
 * @retval False - Receive Buffer is not full.
 */
bool I3C1_IsRxBufferFull(void); 

/**
 * @ingroup i3c_target_driver
 * @brief Clears the Transmit buffer and FIFO. 
 * @param None.
 * @return None. 
 */
void I3C1_TxBufferFIFOClear(void);

/**
 * @ingroup i3c_target_driver
 * @brief Clears the Receive buffer and FIFO.  
 * @param None.
 * @return None.  
 */
void I3C1_RxBufferFIFOClear(void);

/**
 * @ingroup i3c_target_driver
 * @brief Configures buffer for the next In-Band Interrupt (IBI) transaction and initiates a IBI request.
 * @param [in] payloadBuf - Pointer to the payload buffer of In-Band Interrupt.
 * @note Lifetime of the buffer must be maintained till data is transmitted.
 * @param [in] payload_len - Length the payload in bytes.
 * @note Payload Buffer and its length does not include Mandatory Data Byte.
 * @return Error status of the In-Band Interrupt request as described in I3C_TARGET_IBI_REQUEST_ERROR.    
 */
enum I3C_TARGET_IBI_REQUEST_ERROR I3C1_IBIRequest(uint8_t *payloadBuf, uint16_t payload_len);

/**
 * @ingroup i3c_target_driver
 * @brief Sets the payload size of an In-Band Interrupt.
 * @param [in] payload_len - Number of bytes of the payload. 
 * @return None. 
 */
void I3C1_IBIPayloadSizeSet(uint8_t payload_len);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the payload size of an In-Band Interrupt. 
 * @param None.
 * @return Payload size of In-Band Interrupt. 
 */
uint8_t I3C1_IBIPayloadSizeGet(void);

/**
 * @ingroup i3c_target_driver
 * @brief Sets the value of mandatory data byte in an In-Band Interrupt.  
 * @param [in] mdb - Mandatory data byte.  
 * @return None. 
 */
void I3C1_IBIMandatoryDataByteSet(uint8_t mdb);

/**
 * @ingroup i3c_target_driver
 * @brief Checks if an In-Band Interrupt is enabled on the I3C bus.
 * @param None. 
 * @retval True - In-Band Interrupt is enabled.
 * @retval False - In-Band Interrupt is not enabled. 
 */
bool I3C1_IsIBIEnabledOnBus(void);

/**
 * @ingroup i3c_target_driver
 * @brief Enables the bus time-out counter.  
 * @param None. 
 * @return None.  
 */
void I3C1_BusTimeoutEnable(void);

/**
 * @ingroup i3c_target_driver
 * @brief Disables the bus time-out counter. 
 * @param None. 
 * @return None.  
 */
void  I3C1_BusTimeoutDisable(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the most recently received Common Code Command (CCC) from the controller. 
 * @param None. 
 * @return Common Code Command received from the controller. 
 */
enum I3C_CCC I3C1_LastCCCReceivedGet(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the context used on the bus. 
 * @param None. 
 * @return Bus context as described by MIPI specification.  
 */
uint8_t I3C1_BusContextGet(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the Operating mode of the I3C1 module.  
 * @param None.  
 * @return Operating mode as described in I3C_TARGET_OPERATING_MODE.  
 */
enum I3C_TARGET_OPERATING_MODE I3C1_OperatingModeGet(void);

/**
 * @ingroup i3c_target_driver
 * @brief Checks if the I3C1 bus is free.  
 * @param None.   
 * @retval True - I3C1 bus is free.
 * @retval False - I3C1 bus is not free.  
 */
bool I3C1_IsBusFree(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the Bus Error status and clears the status.  
 * @param None.
 * @return Status of Bus Error.
 */
uint8_t I3C1_BusErrorStatusGetAndClear(void);

/**
 * @ingroup i3c_target_driver
 * @brief Resets I3C1 Target module to default state.  
 * @param None.  
 * @return None. 
 */
void I3C1_PeripheralReset(void);

/**
 * @ingroup i3c_target_driver
 * @brief Returns the target reset action and clears the action to the default value. 
 * @param None.  
 * @return The value of target reset action as described in I3C_RESET_ACTION.
 */
enum I3C_RESET_ACTION I3C1_ResetActionGetAndClear(void);

/**
 * @ingroup i3c_target_driver
 * @brief Setter function for the I3C1_TransactionComplete callback.
 * @param [in] handler - Pointer to the function to be called when Stop or Restart condition is detected after a Private I3C or an IBI transaction.   
 * @return None.  
 */
void I3C1_TransactionCompleteCallbackRegister(void (*handler)(struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS *transactionCompleteStatus));

/**
 * @ingroup i3c_target_driver
 * @brief Setter function for the I3C1_BusError callback.
 * @param [in] handler - Pointer to the function to be called when an TE0-TE6 type error on the bus is detected. 
 * @return None.  
 */
void I3C1_BusErrorCallbackRegister(void (*handler)(void));

/**
 * @ingroup i3c_target_driver
 * @brief Setter function for the I3C1_ResetPatternDetected callback.
 * @param [in] handler - Pointer to the function to be called when a Reset Pattern is detected. 
 * @return None. 
 */
void I3C1_ResetPatternDetectedCallbackRegister(void (*handler)(void));

/**
 * @ingroup i3c_target_driver
 * @brief Setter function for the I3C1_RxSoftwareBufferFull callback.
 * @param [in] handler - Pointer to the function to be called when the Driver Receive Buffer is full.
 * @return None. 
 */
void I3C1_RxSoftwareBufferFullCallbackRegister(void (*handler)(void));

/**
 * @ingroup i3c_target_driver
 * @brief I3C1 General Interrupt Service Routine (ISR) function. 
 * @param None.  
 * @return None.  
 */
void I3C1_General_ISR(void);

/**
 * @ingroup i3c_target_driver
 * @brief I3C1 Error Interrupt Service Routine (ISR) function. 
 * @param None.  
 * @return None.  
 */
void I3C1_Error_ISR(void);

/**
 * @ingroup i3c_target_driver
 * @brief I3C1 Reset Interrupt Service Routine (ISR) function.  
 * @param None. 
 * @return None. 
 */
void I3C1_Reset_ISR(void);

/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_Initialize() API.
 */
#define I3C_Target_Initialize I3C1_Initialize
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_Enable() API.
 */
#define I3C_Target_Enable I3C1_Enable
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_Disable() API.
 */
#define I3C_Target_Disable I3C1_Disable
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_AllPrivateTransactionACK() API.
 */
#define I3C_Target_AllPrivateTransactionACK I3C1_AllPrivateTransactionACK
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_AllPrivateTransactionNACK() API.
 */
#define I3C_Target_AllPrivateTransactionNACK I3C1_AllPrivateTransactionNACK
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_NextPrivateTransactionACK() API.
 */
#define I3C_Target_NextPrivateTransactionACK I3C1_NextPrivateTransactionACK
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_MaxWriteLengthGet() API.
 */
#define I3C_Target_MaxWriteLengthGet I3C1_MaxWriteLengthGet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_MaxWriteLengthSet() API.
 */
#define I3C_Target_MaxWriteLengthSet I3C1_MaxWriteLengthSet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_MaxReadLengthGet() API.
 */
#define I3C_Target_MaxReadLengthGet I3C1_MaxReadLengthGet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_MaxReadLengthSet() API.
 */
#define I3C_Target_MaxReadLengthSet I3C1_MaxReadLengthSet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BufferReceive() API.
 */
#define I3C_Target_BufferReceive I3C1_BufferReceive
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BufferTransmit() API.
 */
#define I3C_Target_BufferTransmit I3C1_BufferTransmit
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_ByteReceive() API.
 */
#define I3C_Target_ByteReceive I3C1_ByteReceive
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IsTxFIFOEmpty() API.
 */
#define I3C_Target_IsTxFIFOEmpty I3C1_IsTxFIFOEmpty
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IsTxBufferEmpty() API.
 */
#define I3C_Target_IsTxBufferEmpty I3C1_IsTxBufferEmpty
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IsRxBufferFull() API.
 */
#define I3C_Target_IsRxBufferFull I3C1_IsRxBufferFull
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_TxBufferFIFOClear() API.
 */
#define I3C_Target_TxBufferFIFOClear I3C1_TxBufferFIFOClear
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_RxBufferFIFOClear() API.
 */
#define I3C_Target_RxBufferFIFOClear I3C1_RxBufferFIFOClear
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IBIRequest() API.
 */
#define I3C_Target_IBIRequest I3C1_IBIRequest
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IBIPayloadSizeSet() API.
 */
#define I3C_Target_IBIPayloadSizeSet I3C1_IBIPayloadSizeSet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IBIPayloadSizeGet() API.
 */
#define I3C_Target_IBIPayloadSizeGet I3C1_IBIPayloadSizeGet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IBIMandatoryDataByteSet() API.
 */
#define I3C_Target_IBIMandatoryDataByteSet I3C1_IBIMandatoryDataByteSet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IsIBIEnabledOnBus() API.
 */
#define I3C_Target_IsIBIEnabledOnBus I3C1_IsIBIEnabledOnBus
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BusTimeoutEnable() API.
 */
#define I3C_Target_BusTimeoutEnable I3C1_BusTimeoutEnable
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BusTimeoutDisable() API.
 */
#define I3C_Target_BusTimeoutDisable I3C1_BusTimeoutDisable
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_LastCCCReceivedGet() API.
 */
#define I3C_Target_LastCCCReceivedGet I3C1_LastCCCReceivedGet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BusContextGet() API.
 */
#define I3C_Target_BusContextGet I3C1_BusContextGet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_OperatingModeGet() API.
 */
#define I3C_Target_OperatingModeGet I3C1_OperatingModeGet
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_IsBusFree() API.
 */
#define I3C_Target_IsBusFree I3C1_IsBusFree
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BusErrorStatusGetAndClear() API.
 */
#define I3C_Target_BusErrorStatusGetAndClear I3C1_BusErrorStatusGetAndClear
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_PeripheralReset() API.
 */
#define I3C_Target_PeripheralReset I3C1_PeripheralReset
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_ResetActionGetAndClear() API.
 */
#define I3C_Target_ResetActionGetAndClear I3C1_ResetActionGetAndClear
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_TransactionCompleteCallbackRegister() API.
 */
#define I3C_Target_TransactionCompleteCallbackRegister I3C1_TransactionCompleteCallbackRegister
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_BusErrorCallbackRegister() API.
 */
#define I3C_Target_BusErrorCallbackRegister I3C1_BusErrorCallbackRegister
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_ResetPatternDetectedCallbackRegister() API.
 */
#define I3C_Target_ResetPatternDetectedCallbackRegister I3C1_ResetPatternDetectedCallbackRegister
/**
 * @ingroup i3c_target_driver
 * @brief Defines the Custom Name for I3C1_RxSoftwareBufferFullCallbackRegister() API.
 */
#define I3C_Target_RxSoftwareBufferFullCallbackRegister I3C1_RxSoftwareBufferFullCallbackRegister

#endif // I3C1_H
/**
 End of File
*/