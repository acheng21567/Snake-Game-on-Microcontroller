/*
 * task_accelerometer.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef TASK_ACCELEROMETER_H_
#define TASK_ACCELEROMETER_H_

#include "main.h"

TaskHandle_t Task_Acceler_Timer_Handle;
TaskHandle_t Task_Acceler_Bottom_Half_Handle;

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
