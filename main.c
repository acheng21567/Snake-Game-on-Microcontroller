/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main_freertos.c ========
 */
#include "main.h"

// Queue for Snake board and length
QueueHandle_t Queue;

/**
 * Display board
 * | | | | | | |
 * | | | | | | |
 * | | | | | | |
 * |T|2|H| | | |
 * | | | | |A| |
 * | | | | | | |
 *
 * Apple = Length + 1
 * Head = Length
 * Body = 1 ~ Length - 1
 * Tail = 1
 * Nothing = 0
 */
uint8_t board[6][6] = {
                 {0,0,0,0,0,0},
                 {0,0,0,0,0,0},
                 {0,0,0,0,0,0},
                 {1,2,3,0,0,0},
                 {0,0,0,0,4,0},
                 {0,0,0,0,0,0}};

// Length of snake
uint8_t length = 3;

// Speed of snake
uint8_t speed = 5;

/**
 * Initialize all peripherals used
 */
void init_all(void){
    sensor_init();
    accelerometer_init();
    buzzer_init();
    Crystalfontz128x128_Init();
    // Initialize S2 button
    P3->DIR &= ~BIT5;
}

/**
 * Debounce S2 and return true if S2 is pressed
 */
bool S2_pressed(){
    static uint8_t debounce_state = 0x00;

    // Shift the de-bounce variable to the left
    debounce_state = debounce_state << 1;

    // If S2 is being pressed, set the LSBit of debounce_state to a 1;
    if((P3->IN & BIT5) == 0){
        debounce_state |= 0x01;
    }

    // If the de-bounce variable is equal to 0x7F, change the color of the tri-color LED.
    if(debounce_state == 0x7F){
        return true;
    }
    else{
        return false;
    }
}

/*
 *  ======== main ========
 */
int main(void){
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    // Initialize all peripherals used
    init_all();

    __enable_irq();

    // Initialize Queue with size 2
    Queue = xQueueCreate(2, sizeof(SNAKE_DIR_t));

    // Make the LCD White
    lcd_draw_rectangle(66, 66, 132,132,LCD_COLOR_WHITE);

    draw_board(SNAKE_DIR_RIGHT);
    while(1){
        if(S2_pressed()){
            break;
        }
    }

    // Create all the tasks
    xTaskCreate(
            Task_Acceler_Timer,
            "Task_Acceler_Timer",
            configMINIMAL_STACK_SIZE,
            NULL,
            1,
            &Task_Acceler_Timer_Handle);

    xTaskCreate(
            Task_LCD_Display,
            "Task_LCD_Display",
            configMINIMAL_STACK_SIZE,
            NULL,
            3,
            &Task_LCD_Display_Handle);

    xTaskCreate(
            Task_Read_Lux,
            "Task_Read_Lux",
            configMINIMAL_STACK_SIZE,
            NULL,
            4,
            &Task_Read_Lux_Handle);

    xTaskCreate(
            Task_Acceler_Bottom_Half,
            "Task_Acceler_Bottom_Half",
            configMINIMAL_STACK_SIZE,
            NULL,
            5,
            &Task_Acceler_Bottom_Half_Handle);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    while(1){};
    return (0);
}

//*****************************************************************************
//
//! \brief Application defined malloc failed hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationMallocFailedHook(){
    /* Handle Memory Allocation Errors */
    while(1){
    }
}

//*****************************************************************************
//
//! \brief Application defined stack overflow hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName){
    //Handle FreeRTOS Stack Overflow
    while(1){
    }
}
