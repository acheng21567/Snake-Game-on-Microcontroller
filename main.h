/*
 * main.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef MAIN_H_
#define MAIN_H_


#include "msp.h"
#include "msp432p401r.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Project header files */
#include "task_sensor.h"
#include "task_accelerometer.h"
#include "i2c.h"
#include "lcd.h"
#include "task_lcd.h"
#include "image.h"
#include <buzzer.h>

// Semaphore for I2C
extern SemaphoreHandle_t Sem_i2c;

// Queue for Snake board and length
extern QueueHandle_t Queue;

// Display board
extern uint8_t board[6][6];

// Length of snake
extern uint8_t length;

// Speed of snake
extern uint8_t speed;

/**
 *       1
 *  2  Head  0
 *       3
 */
typedef enum {
    SNAKE_DIR_RIGHT,
    SNAKE_DIR_UP,
    SNAKE_DIR_LEFT,
    SNAKE_DIR_DOWN,
} SNAKE_DIR_t;

#endif /* MAIN_H_ */
