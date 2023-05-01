/*
 * task_buzzer.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "main.h"

// Buzzer J4.40 -> P2.7 -> PM_TA0.4
#define BUZZER_PORT     P2
#define BUZZER_PIN      BIT7
#define BUZZER_TIMER    TIMER_A0
#define BUZZER_CHANNEL  4
#define TICKS           8000

TaskHandle_t Task_Buzzer_On_Handle;

/**
 * Initialize the buzzer with 8000 ticks
 * and 50% duty cycle
 */
void buzzer_init(void);

/**
 * Turn on buzzer if on is true
 * Otherwise turn off
 */
void buzzer_on(bool on);

#endif /* BUZZER_H_ */
