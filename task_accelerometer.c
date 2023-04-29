/*
 * task_accelerometer.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#include "main.h"

// Add a global variable that holds the most recent value of the X direction
volatile uint32_t ACCER_X_DIR = 0;
// Add a global variable that holds the most recent value of the Y direction
volatile uint32_t ACCER_Y_DIR = 0;

/**
 * Initialize the accelerometer
 */
void accelerometer_init(void){
    // Accelerometer x: J3.23 -> P6.1 (A14)
    // Accelerometer y: J3.24 -> P4.0 (A13)
    // Accelerometer z: J3.25 -> P4.2 (A11)

    // Configure the X direction as an analog input pin.
    ACCER_X_PORT->SEL0 |= ACCER_X_PIN;
    ACCER_X_PORT->SEL1 |= ACCER_X_PIN;      // Always 11 for ADC pin

    // Configure the Y direction as an analog input pin.
    ACCER_Y_PORT->SEL0 |= ACCER_Y_PIN;
    ACCER_Y_PORT->SEL1 |= ACCER_Y_PIN;      // Always 11 for ADC pin

    ADC14->CTL0 = ADC14_CTL0_SHP           // pulsed sample mode
                | ADC14_CTL0_SHT02         // sample 16-times
                | ADC14_CTL0_CONSEQ_1;     // sequence-of-channels

    // Configure ADC to return 12-bit values
    ADC14->CTL1 = ADC14_CTL1_RES_2;

    // Associate the X direction analog signal with MEM[0]
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_14;

    // Associate the Y direction analog signal with MEM[1]
    ADC14->MCTL[1] = ADC14_MCTLN_INCH_13;

    // Make sure to indicate this is the end of a sequence.
    ADC14->MCTL[1] |= ADC14_MCTLN_EOS;

    // Enable interrupts in the ADC AFTER a value is written into MEM[1].
    ADC14->IER0 = ADC14_IER0_IE1;

    // Enable ADC Interrupt in the NVIC
    NVIC_EnableIRQ(ADC14_IRQn);
    NVIC_SetPriority(ADC14_IRQn, 2);

    // Turn ADC ON
    ADC14->CTL0 |= ADC14_CTL0_ON;
}

/**
 * Start the ADC14 Conversion every 50ms
 */
void Task_Acceler_Timer(void *pvParameters){

}

/**
 * Bottom Half of ADC14 Handler
 * Determine the head direction based on accelerometer value
 * Notified by ADC14_IRQHandler
 */
void Task_Acceler_Bottom_Half(void *pvParameters){

}

/*
 * Top Half of ADC14 Handler
 */
void ADC14_IRQHandler(void){

}
