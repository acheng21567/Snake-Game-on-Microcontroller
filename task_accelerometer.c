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

SNAKE_DIR_t prev_dir = SNAKE_DIR_RIGHT;

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
    while(1){
        // Start ADC Conversion
        ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

        // Delay 50 ms
        vTaskDelay(pdMS_TO_TICKS(speed * 100));
    }
}

/**
 * Bottom Half of ADC14 Handler
 * Determine the head direction based on accelerometer value
 * Notified by ADC14_IRQHandler
 */
void Task_Acceler_Bottom_Half(void *pvParameters){
    SNAKE_DIR_t dir;
    while(1){
        // Wait until we get a task notification from the ADC14 ISR
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        // Change direction based on accelerometer
        if(ACCER_X_DIR > VOLT_1P8 && prev_dir % 2 == 1){
            dir = SNAKE_DIR_RIGHT;
        }
        else if(ACCER_X_DIR < VOLT_1P4 && prev_dir % 2 == 1){
            dir = SNAKE_DIR_LEFT;
        }
        else if(ACCER_Y_DIR > VOLT_1P8 && prev_dir % 2 == 0){
            dir = SNAKE_DIR_UP;
        }
        else if(ACCER_Y_DIR < VOLT_1P4 && prev_dir % 2 == 0){
            dir = SNAKE_DIR_DOWN;
        }
        else{
            dir = prev_dir;
        }

        // Send queue
        prev_dir = dir;
        xQueueSendToBack(Queue, &dir, portMAX_DELAY);
    }
}

/*
 * Top Half of ADC14 Handler
 */
void ADC14_IRQHandler(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // Read the X value
    ACCER_X_DIR = ADC14->MEM[0];

    // Read the Y value
    ACCER_Y_DIR = ADC14->MEM[1];

    // Send a task notification to Task_Acceler_Bottom_Half
    vTaskNotifyGiveFromISR(
            Task_Acceler_Bottom_Half_Handle,
            &xHigherPriorityTaskWoken
    );

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}
