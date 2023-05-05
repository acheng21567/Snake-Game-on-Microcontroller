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

// Queue for Snake board and length
extern QueueHandle_t Queue;

// Display board
extern uint8_t board[6][6];

// Length of snake
extern uint8_t length;

// Speed of snake
extern uint8_t speed;

/**
 * Debounce S2 and return true if S2 is pressed
 */
bool S2_pressed();

#endif /* MAIN_H_ */
