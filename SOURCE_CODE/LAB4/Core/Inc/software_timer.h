/*
 * software_timer.h
 *
 *  Created on: Nov 19, 2023
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"


extern int timer1_flag;


void setTimer1(int duration);
void clearTimer();

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
