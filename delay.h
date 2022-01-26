/*
 * delay.h
 *
 *  Created on: Jan 26, 2022
 *      Author: atay
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "stm32f4xx_hal.h"

void pwm(void);
void delay_init(void) ;
void delay_us(int) ;
void delay_ms(int) ;



#endif /* INC_DELAY_H_ */
