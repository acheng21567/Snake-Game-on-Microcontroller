/*
 * task_sensor.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef TASK_SENSOR_H_
#define TASK_SENSOR_H_


#include "main.h"

#define OPT3001_SLAVE_ADDRESS 0x44
#define OPT_INTERRUPT_PIN 11
#define RESULT_REG 0x00
#define CONFIG_REG 0x01
#define LOWLIMIT_REG 0x02
#define HIGHLIMIT_REG 0x03
#define MANUFACTUREID_REG 0x7E
#define DEVICEID_REG 0x7F

/**
 * Use I2C to initialize sensor
 *
 * Take Semaphore_I2C
 */
void sensor_init(void);

/**
 * Use I2C to read lux value and change the
 * snake's speed every 50 ms
 *
 * Take Semaphore_I2C
 */
void Task_Read_Lux(void *pvParameters);

#endif /* TASK_SENSOR_H_ */
