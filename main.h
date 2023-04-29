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

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Project header files */
#include "task_buzzer.h"
#include "task_sensor.h"
#include "task_accelerometer.h"
#include "i2c.h"
#include "lcd.h"
#include "task_lcd.h"

typedef struct{
    uint8_t board[6][6];
    uint8_t length;
} Snake_t;

#endif /* MAIN_H_ */