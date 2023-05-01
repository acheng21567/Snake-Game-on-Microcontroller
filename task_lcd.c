/*
 * taks_lcd.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#include "main.h"

/**
 * Create a new apple on board randomly
 * Could not be on snake
 */
void create_apple(){
    time_t t;
    // Initialize random number generator
    srand((unsigned) time(&t));

    uint8_t num = rand() % 36;
    while(board[num/6][num%6] != 0){
        num = rand() % 36;
    }
    board[num/6][num%6] = length + 1;
}

/**
 * Move the snake based on the direction
 */
void snake_move(SNAKE_DIR_t dir){
    uint8_t next_head_pos[2];
    uint8_t tail[2];
    int i,j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(board[i][j] == length){
                if(dir == SNAKE_DIR_RIGHT){
                    next_head_pos[0] = i;
                    next_head_pos[1] = (j + 1) % 6;
                }
                else if(dir == SNAKE_DIR_UP){
                    next_head_pos[0] = (i + 5) % 6;
                    next_head_pos[1] = j;
                }
                else if(dir == SNAKE_DIR_LEFT){
                    next_head_pos[0] = i;
                    next_head_pos[1] = (j + 5) % 6;
                }
                else{
                    next_head_pos[0] = (i + 1) % 6;
                    next_head_pos[1] = j;
                }
            }
            if(board[i][j] == 1){
                tail[0] = i;
                tail[1] = j;
            }
            if(board[i][j] != 0 && board[i][j] != length + 1){
                board[i][j]--;
            }
        }
    }
    if(board[next_head_pos[0]][next_head_pos[1]] == length + 1){
        board[next_head_pos[0]][next_head_pos[1]] = length;
        length++;
        for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                if(board[i][j] != 0){
                    board[i][j]++;
                }
            }
        }
        create_apple();
        board[tail[0]][tail[1]] = 1;
    }
    else if(board[next_head_pos[0]][next_head_pos[1]] != 0){
        buzzer_on(true);
    }
    else{
        board[next_head_pos[0]][next_head_pos[1]] = length;
    }
}

/**
 * Draw the board based on current board
 */
void draw_board(void){
    uint8_t i, j;

    // Draw Horizontal and Vertical Lines
    for(i = 0; i < 6; i++){
        lcd_draw_rectangle(SCREEN_ROW_POS*i,SCREEN_COL_CENTER,LINE_WIDTH,LINE_LENGTH,LCD_COLOR_BLACK);
        lcd_draw_rectangle(SCREEN_ROW_CENTER,SCREEN_COL_POS*i,LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLACK);
    }

    // Draw snake board
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            int x = SCREEN_ROW_POS * j + IMAGE_OFFSET;
            int y = SCREEN_COL_POS * i + IMAGE_OFFSET;
            int color = (board[i][j] == 0 || board[i][j] == length+1) ? 0xFFFF : (board[i][j] == 1) ? 0x001F : (board[i][j] == length) ? 0x07FF : 0xFFE0;
            lcd_draw_rectangle(x,y,IMAGE_SIZE,IMAGE_SIZE,color);

            if(board[i][j] == length + 1){
                lcd_draw_image(x, y, ORANGE_SIZE, ORANGE_SIZE, orangeBitmaps, LCD_COLOR_RED, LCD_COLOR_WHITE);
            }
        }
    }
}

/**
 * Display the board every 100 ms
 *
 * Take I2C Semaphore
 */
void Task_LCD_Display(void *pvParameters){
    SNAKE_DIR_t dir;
    while(1){
        // Take the I2C Semaphore
        xSemaphoreTake(Sem_i2c, portMAX_DELAY);

        // Wait until we receive a message from accelerometer
        xQueueReceive(Queue, &dir, portMAX_DELAY);

        snake_move(dir);

        draw_board();

        // Give the I2C Semaphore
        xSemaphoreGive(Sem_i2c);
    }
}


