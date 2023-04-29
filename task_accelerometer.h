/*
 * task_accelerometer.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef TASK_ACCELEROMETER_H_
#define TASK_ACCELEROMETER_H_

#include "main.h"

// Accelerometer x: J3.23 -> P6.1 (A14)
// Accelerometer y: J3.24 -> P4.0 (A13)
// Accelerometer z: J3.25 -> P4.2 (A11)
#define ACCER_X_PORT        P6
#define ACCER_X_PIN         BIT1
#define ACCER_Y_PORT        P4
#define ACCER_Y_PIN         BIT0
#define ACCER_Z_PORT        P4
#define ACCER_Z_PIN         BIT2

TaskHandle_t Task_Acceler_Timer_Handle;
TaskHandle_t Task_Acceler_Bottom_Half_Handle;

// Add a global variable that holds the most recent value of the X direction
extern volatile uint32_t ACCER_X_DIR;
// Add a global variable that holds the most recent value of the Y direction
extern volatile uint32_t ACCER_Y_DIR;

/**
 * Initialize the accelerometer
 */
void accelerometer_init(void);

/**
 * Start the ADC14 Conversion every 50ms
 */
void Task_Acceler_Timer(void *pvParameters);

/**
 * Bottom Half of ADC14 Handler
 * Determine the head direction based on accelerometer value
 * Notified by ADC14_IRQHandler
 */
void Task_Acceler_Bottom_Half(void *pvParameters);

/*
 * Top Half of ADC14 Handler
 */
void ADC14_IRQHandler(void);

#endif /* TASK_ACCELEROMETER_H_ */
