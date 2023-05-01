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
    i2c_init();
    i2c_write_16(OPT3001_SLAVE_ADDRESS, CONFIG_REG, 0xC610);
}

/**
 * Use I2C to read lux value and change the
 * snake's speed every 50 ms
 *
 * Take Semaphore_I2C
 */
void Task_Read_Lux(void *pvParameters){
    while(1){
        // Take the I2C Semaphore
        xSemaphoreTake(Sem_i2c, portMAX_DELAY);

        uint16_t result = i2c_read_16(OPT3001_SLAVE_ADDRESS, RESULT_REG);
        float lux = 0.01 * powf(2, result >> 12) * (result & 0x0FFF);

        // Snake moves faster if dark
        if(lux < 200.0){
            speed = 2;
        }
        // Snake moves faster if dark
        else if (lux > 500.0){
            speed = 8;
        }
        else{
            speed = 5;
        }

        // Give the I2C Semaphore
        xSemaphoreGive(Sem_i2c);

        // Delay 50ms
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}
