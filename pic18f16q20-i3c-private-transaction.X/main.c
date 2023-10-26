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
void ReadyToReceiveData(void);
void PrintReceivedData(void);
void TransmitData(void);
void TransactionCompleteCallback(struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS *transactionCompleteStatus);

uint8_t receivedData[21]; 
uint8_t sendData[20];
uint16_t numberOfBytesReceived; 
volatile bool isDataReceived = false;

int main(void)
{     
    enum I3C_TARGET_OPERATING_MODE;
    
    SYSTEM_Initialize(); 
    
    //Register user callback for Transaction Complete interrupt. This will be used to
    //know the status of data receive operation.
    I3C_Target_TransactionCompleteCallbackRegister(TransactionCompleteCallback);

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
    
    
    printf("Waiting for dynamic address assignment\r\n");
    while(I3C1_OperatingModeGet() != I3C_TARGET_OPERATING_MODE_I3C_SDR);
    printf("Dynamic address is assigned\r\n");
    
    ReadyToReceiveData();
    
    printf("Waiting for data to be received\r\n");
    //Wait till data is received
    while(isDataReceived != true);
    isDataReceived = false;
    
    PrintReceivedData();
    
    TransmitData();
 
    while(1)
    {

    }    
}

void ReadyToReceiveData(void)
{   
    enum I3C_TARGET_BUFFER_RECEIVE_ERROR receiveError;
 
    printf("Ready to receive data\r\n");
    receiveError = I3C_Target_BufferReceive(receivedData, sizeof(receivedData));
 
    if (receiveError == I3C_TARGET_BUFFER_RECEIVE_BUFFER_SIZE_EXCEEDED)
    {
        printf("BufferReceive: Software buffer size exceeded\r\n");
    }
    else if (receiveError == I3C_TARGET_BUFFER_RECEIVE_NO_ERROR)
    {   
        printf("BufferReceive: No error\r\n");
    }
   
    I3C_Target_NextPrivateTransactionACK();
}
 
void TransactionCompleteCallback(struct I3C_TARGET_TRANSACTION_COMPLETE_STATUS *transactionCompleteStatus)
{
    if(transactionCompleteStatus->dataFlowDirection == I3C_TARGET_DATA_RECEIVED)
    {
        //Data is received
        isDataReceived = true;
         
        //Get number of bytes received during last transaction
        numberOfBytesReceived = transactionCompleteStatus->numOfBytesReceived;
    }
    else if(transactionCompleteStatus->dataFlowDirection == I3C_TARGET_DATA_TRANSMITTED)
    {
        //Data is transmitted
    }
}

void PrintReceivedData(void)
{ 
    uint16_t count = 0;
    
    printf("Number of bytes received : %u\r\n",  numberOfBytesReceived); 
    printf("Received data : \r\n"); 
        
    for(count = 0; count < numberOfBytesReceived; count++)
    {
        printf("0x%X ", receivedData[count]);
    }
    printf("\r\n");
}

void TransmitData(void)
{
    uint16_t count = 0;
    
    enum I3C_TARGET_BUFFER_TRANSMIT_ERROR sendError;
    
    //Copy data 
    for(count = 0; count < numberOfBytesReceived; count++ )
    {
        sendData[count] = receivedData[count];
    }
     
    printf("Sending data\r\n");
    //Setup to transmit 20 bytes of data
    sendError = I3C_Target_BufferTransmit(sendData, 20);
     
    if(sendError == I3C_TARGET_BUFFER_TRANSMIT_BUFFER_SIZE_EXCEEDED)
    {
        printf("BufferTransmit: Software buffer size exceeded\r\n");
    }
    else if(sendError == I3C_TARGET_BUFFER_TRANSMIT_NO_ERROR)
    {
        printf("BufferTransmit: No error \r\n");
    }  
    
    I3C_Target_NextPrivateTransactionACK();
}
 
