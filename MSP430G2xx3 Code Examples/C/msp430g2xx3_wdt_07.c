//******************************************************************************
//  MSP430G2xx3 Demo - WDT+ periodic reset
//
//  Description; Various reset intervals are configured in watchdog mode.
//  To illustrate the speed of the reset time the LED flashes in accordance 
//  of the selected interval. 
//
//  ACLK = 32khz, MCLK = SMCLK = default DCO
//
//		  MSP430G2xx3
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  D. Dang
//  Texas Instruments Inc.
//  February 2011
//  Built with CCS Version 4.2.0 and IAR Embedded Workbench Version: 5.10
//******************************************************************************
#include  <msp430g2553.h>

void main(void)
{
                                            // WDT is clocked by fSMCLK (1MHz)
  WDTCTL = WDT_MRST_32;                       // ~32ms interval (default)
  //WDTCTL = WDT_MRST_8;                      // ~8ms
  //WDTCTL = WDT_MRST_0_5;                    // ~0.5ms
  //WDTCTL = WDT_MRST_0_064;                  // ~0.064ms
                                            // WDT is clocked by fACLK (32KHz) 
  //WDTCTL = WDT_ARST_1000;                   // 1000ms
  //WDTCTL = WDT_ARST_250;                    // 250ms
  //WDTCTL = WDT_ARST_16;                     // 16ms  
  //WDTCTL = WDT_ARST_1_9;                    // 1.9ms
  P1DIR |= 0x01;
  P1OUT ^=0x01;

  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM3 w/interrupt
}


