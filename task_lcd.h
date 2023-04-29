/*
 * task_lcd.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef TASK_LCD_H_
#define TASK_LCD_H_

#include "main.h"

TaskHandle_t Task_LCD_Display_Handle;

/**
 * Display the board based on queue struct
 * passed by the Task_Acceler_Bottom_Half
 */
void Task_LCD_Display(void *pvParameters);

#endif /* TASK_LCD_H_ */
