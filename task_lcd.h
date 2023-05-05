/*
 * task_lcd.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef TASK_LCD_H_
#define TASK_LCD_H_

#include "main.h"

#define SCREEN_X            132
#define SCREEN_Y            132

#define SCREEN_COL_CENTER   SCREEN_X / 2
#define SCREEN_ROW_CENTER   SCREEN_Y / 2

#define SCREEN_ROW_POS      SCREEN_X / 6
#define SCREEN_COL_POS      SCREEN_Y / 6

#define IMAGE_OFFSET        11

#define LINE_LENGTH         132
#define LINE_WIDTH          1
#define IMAGE_SIZE          22 - 1

#define LCD_COLOR_BLACK     0x0000
#define LCD_COLOR_WHITE     0xFFFF
#define LCD_COLOR_RED       0xF800
#define LCD_COLOR_GREEN     0x07E0

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

TaskHandle_t Task_LCD_Display_Handle;

/**
 * Draw the board based on current board
 */
void draw_board(SNAKE_DIR_t dir);

/**
 * Display the board every 100 ms
 *
 * Take I2C Semaphore
 */
void Task_LCD_Display(void *pvParameters);

#endif /* TASK_LCD_H_ */
