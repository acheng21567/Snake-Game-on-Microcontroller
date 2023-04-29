/*
 * task_sensor.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#include "main.h"

/**
 * Use I2C to initialize sensor
 *
 * Take Semaphore_I2C
 */
void sensor_init(void){
    // Initialize OPT3001
    i2c_write_16(OPT3001_SLAVE_ADDRESS, CONFIG_REG, 0xC610);
}

/**
 * Use I2C to read lux value and change the
 * snake's speed every 50 ms
 *
 * Take Semaphore_I2C
 */
void Task_Read_Lux(void *pvParameters){

}
