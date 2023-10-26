/**
 * Configuration Bits Generated Driver Source File
 * 
 * @file config_bits.c
 * 
 * @ingroup config_bitsdriver
 * 
 * @brief This is the generated Device Configuration bits file.
 *
 * @version Driver Version 1.0.0
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

// Configuration bits: selected in the GUI

//CONFIG1
#pragma config FEXTOSC = ECH     // External Oscillator Selection->EC (external clock) above 8 MHz
#pragma config RSTOSC = HFINTOSC_64MHZ     // Reset Oscillator Selection->HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1

//CONFIG2
#pragma config CLKOUTEN = OFF     // Clock out Enable bit->CLKOUT function is disabled
#pragma config PR1WAY = ON     // PRLOCKED One-Way Set Enable bit->PRLOCKED bit can be cleared and set only once
#pragma config BBEN = OFF     // Boot Block enable bit->User PFM code protection disabled
#pragma config CSWEN = ON     // Clock Switch Enable bit->Writing to NOSC and NDIV is allowed
#pragma config FCMEN = ON     // Fail-Safe Clock Monitor Enable bit->Fail-Safe Clock Monitor enabled
#pragma config FCMENP = ON     // Fail-Safe Clock Monitor - Primary XTAL Enable bit->Fail-Safe Clock Monitor enabled; timer will flag FSCMP bit and OSFIF interrupt on EXTOSC failure.
#pragma config FCMENS = ON     // Fail-Safe Clock Monitor - Secondary XTAL Enable bit->Fail-Safe Clock Monitor enabled; timer will flag FSCMS bit and OSFIF interrupt on SOSC failure.

//CONFIG3
#pragma config MCLRE = EXTMCLR     // MCLR Enable bit->If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR 
#pragma config PWRTS = PWRT_OFF     // Power-up timer selection bits->PWRT is disabled
#pragma config MVECEN = OFF     // Multi-vector enable bit->Interrupt contoller does not use vector table to prioritze interrupts
#pragma config IVT1WAY = ON     // IVTLOCK bit One-way set enable bit->IVTLOCKED bit can be cleared and set only once
#pragma config LPBOREN = OFF     // Low Power BOR Enable bit->Low-Power BOR disabled
#pragma config BOREN = OFF     // Brown-out Reset Enable bits->Brown-out Reset disabled

//CONFIG4
#pragma config BORV = VBOR_1P9     // Brown-out Reset Voltage Selection bits->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config PPS1WAY = ON     // PPSLOCK bit One-Way Set Enable bit->PPSLOCKED bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle
#pragma config STVREN = ON     // Stack Full/Underflow Reset Enable bit->Stack full/underflow will cause Reset
#pragma config LVP = ON     // Low Voltage Programming Enable bit->Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored
#pragma config DEBUG = OFF     // Debug enable bit->Backround debugger disabled
#pragma config XINST = OFF     // Extended Instruction Set Enable bit->Extended Instruction Set and Indexed Addressing Mode disabled

//CONFIG5
#pragma config WDTCPS = WDTCPS_31     // WDT Period selection bits->Divider ratio 1:65536; software control of WDTPS
#pragma config WDTE = OFF     // WDT operating mode->WDT Disabled; SEN is ignored

//CONFIG6
#pragma config WDTCWS = WDTCWS_7     // WDT Window Select bits->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = SC     // WDT input clock selector->Software Control (when WDTE != 0b00)

//CONFIG7
#pragma config VDDIO2MD = STANDARD_RANGE     // VDDIO2 supply mode bit->Standard Operating Range (VDDIO2 >= 1.62V)
#pragma config VDDIO3MD = LOW_VOLTAGE_RANGE     // VDDIO3 supply mode bit->Low-voltage Operating Range (VDDIO3 < 1.62V)

//CONFIG8
#pragma config BBSIZE = BBSIZE_16384     // Boot Block Size Selection bits->Boot Block size is 16384 words

//CONFIG9
#pragma config SAFSZ = SAFSZ_NONE     // SAF Block Size Selection bits->NONE

//CONFIG10
#pragma config WRTB = OFF     // Boot Block Write Protection bit->Boot Block is not write-protected
#pragma config WRTC = OFF     // Configuration Register Write Protection bit->Configuration registers are not write-protected
#pragma config WRTD = OFF     // Data EEPROM Write Protection bit->Data EEPROM is not write-protected
#pragma config WRTSAF = OFF     // Storage Area Flash (SAF) Write Protection bit->SAF is not write-protected
#pragma config WRTAPP = OFF     // Application Block Write Protection bit->Application Block is not write-protected

//CONFIG11
#pragma config CP = OFF     // User Program Flash Memory (PFM) Code Protection bit->User PFM code protection is disabled

//CONFIG12
#pragma config CPD = OFF     // Data EEPROM Code Protection bit->Data EEPROM code protection is disabled

//CONFIG14
#pragma config SAFLOCK = OFF     // SAF Lock Enable bit->SAF Lock disabled


/**
 End of File
*/