/*
 * software_timer.h
 *
 *  Created on: Nov 19, 2023
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


extern int timer1_flag;


void setTimer1(int duration);
void clearTimer1();

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
