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

    // Make sure the apple is not created on snake
    while(board[num/6][num%6] != 0){
        num = rand() % 36;
    }
    board[num/6][num%6] = length + 1;
}

/**
 * Action when the snake die
 */
void game_over(){
    // Turn on the buzzer and output game over message
    buzzer_on(true);
    lcd_draw_image(SCREEN_ROW_CENTER, SCREEN_COL_CENTER, 120, 120, game_overBitmaps, LCD_COLOR_RED, LCD_COLOR_WHITE);

    while(1){
        // Restart the game if s2 button pressed
        if(S2_pressed()){
            int i, j;
            for(i = 0; i < 6; i++){
                for(j = 0; j < 6; j++){
                    board[i][j] = 0;
                }
            }
            board[3][0] = 1;
            board[3][1] = 2;
            board[3][2] = 3;
            length = 3;
            speed = 5;

            // Randomly create apple
            create_apple();

            // Turn off the buzzer
            buzzer_on(false);

            // Make the LCD White
            lcd_draw_rectangle(66, 66, 132,132,LCD_COLOR_WHITE);
            break;
        }
    }
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
            // Determine the next head position based on direction
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

            // Record tail position for future use
            if(board[i][j] == 1){
                tail[0] = i;
                tail[1] = j;
            }

            // Reduce number by 1 for snake
            if(board[i][j] != 0 && board[i][j] != length + 1){
                board[i][j]--;
            }
        }
    }

    // If we get the orange
    if(board[next_head_pos[0]][next_head_pos[1]] == length + 1){
        board[next_head_pos[0]][next_head_pos[1]] = length;
        // Increase snake length
        length++;
        for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                if(board[i][j] != 0){
                    board[i][j]++;
                }
            }
        }
        // Recreate the apple randomly
        create_apple();
        // Add back the tail
        board[tail[0]][tail[1]] = 1;
    }
    // Game end if we touch the snake's body
    else if(board[next_head_pos[0]][next_head_pos[1]] != 0){
        game_over();
    }
    else{
        board[next_head_pos[0]][next_head_pos[1]] = length;
    }
}

/**
 * Draw the board based on current board
 */
void draw_board(SNAKE_DIR_t dir){
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
            int color = (board[i][j] <= 1 || board[i][j] >= length) ? LCD_COLOR_WHITE : LCD_COLOR_GREEN;
            lcd_draw_rectangle(x,y,IMAGE_SIZE,IMAGE_SIZE,color);

            if(board[i][j] == length + 1){
                lcd_draw_image(x, y, ORANGE_SIZE, ORANGE_SIZE, orangeBitmaps, LCD_COLOR_RED, LCD_COLOR_WHITE);
            }
            else if(board[i][j] == length){
                if(dir == SNAKE_DIR_RIGHT){
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, headBitmapsRight, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
                else if(dir == SNAKE_DIR_UP){
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, headBitmapsUp, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
                else if(dir == SNAKE_DIR_LEFT){
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, headBitmapsLeft, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
                else{
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, headBitmapsDown, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
            }
            if(board[i][j] == 1){
                if(board[(i+1)%6][j] == 2){
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, tailBitmapsDown, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
                else if(board[(i+5)%6][j] == 2){
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, tailBitmapsUp, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
                else if(board[i][(j+1)%6] == 2){
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, tailBitmapsRight, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
                else{
                    lcd_draw_image(x, y, IMAGE_SIZE, IMAGE_SIZE, tailBitmapsLeft, LCD_COLOR_GREEN, LCD_COLOR_WHITE);
                }
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
        // Wait until we receive a message from accelerometer
        xQueueReceive(Queue, &dir, portMAX_DELAY);

        // Move the snake based on direction
        snake_move(dir);

        // Update the board
        draw_board(dir);
    }
}


