/*
 * task_buzzer.c
 *
 *  Created on: Apr 28, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#include "task_buzzer.h"

/**
 * Initialize the buzzer with 8000 ticks
 * and 50% duty cycle
 */
void buzzer_init(void){
    // Set buzzer to output pin
    BUZZER_PORT->DIR |= BUZZER_PIN;

    // Set to select primary mode
    BUZZER_PORT->SEL0 |= BUZZER_PIN;
    BUZZER_PORT->SEL1 &= ~BUZZER_PIN;

    // Turn off timer
    BUZZER_TIMER->CTL = 0;

    // Set the period of the timer.
    BUZZER_TIMER->CCR[0] = TICKS - 1;

    // Set Duty Cycle to 50%
    BUZZER_TIMER->CCR[BUZZER_CHANNEL] = (TICKS / 2) -1;

    // Set the OUT MODE to be mode 7 (RESET/SET Mode)
    BUZZER_TIMER->CCTL[BUZZER_CHANNEL] = TIMER_A_CCTLN_OUTMOD_7;

    // Set the clock to use master clock
    BUZZER_TIMER->CTL = TIMER_A_CTL_SSEL__SMCLK;

    // Turn off the timer
    BUZZER_TIMER->CTL &= ~TIMER_A_CTL_MC_MASK;
}

/**
 * Turn on buzzer if on is true
 * Otherwise turn off
 */
void buzzer_on(bool on){
    if(on){
        // Clear current control mode bit
        BUZZER_TIMER->CTL &= ~TIMER_A_CTL_MC_MASK;

        // Turn on the first TimerA peripheral
        BUZZER_TIMER->CTL |= TIMER_A_CTL_MC__UP     // Set to UP mode
                          | TIMER_A_CTL_CLR;        // CLR the current count
    }
    else{
        // Turn off the timer
        BUZZER_TIMER->CTL &= ~TIMER_A_CTL_MC_MASK;
    }
}
