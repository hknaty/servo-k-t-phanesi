/*
 * delay.c
 *
 *  Created on: Jan 26, 2022
 *      Author: atay
 */


#include "delay.h"



void delay_init()
{
	__HAL_RCC_TIM5_CLK_ENABLE();  // TIM5 ENABLE YAPILDI. RCC->APB1ENR |= 1<<3;

	TIM5->PSC  =  16-1 ;          //16M/16-1 1000Mh
	TIM5->ARR  =  0xffff;


	TIM5->CR1  |= 1<<0;           //enable timer
	while(!(TIM5->SR &(1<<0)));   //UIF bagragı 1 oldu mu diye bak
}
void delay_us(int time)
{
	TIM5->CNT = 0;
	while((TIM5->CNT) < time);

}
void delay_ms(int time)
{
	for (int i=0; i<time; i++){

		delay_us(1000);
	}

}

void pwm()
{
	__HAL_RCC_TIM2_CLK_ENABLE();  // TIM2 ENABLE YAPILDI. RCC->APB1ENR |= 1<<3;
	TIM2->PSC  =  178-1 ;          //16Mhz/16-1 1Mhz      16000000hz/16000 = 1000Hz 16000000/80
	TIM2->ARR  =  1799;           // sayılacak total deger periyotu belirler
	TIM2->CCR1 =  0;              // duty oranını belirler. 

	//TIM2->CCMR1=  6<<4;             //      OC1M6:4 PWM MODE 1 SELECTED 110
	TIM2->CCMR1|= TIM_CCMR1_OC1M_2;
	TIM2->CCMR1|= TIM_CCMR1_OC1M_1;
	TIM2->CCMR1|=  TIM_CCMR1_OC1PE;  //1<<3  OUTPUT COMPARE ENABLE//TIM2->CR1  =  TIM_CR1_ARPE;     //1<<7  AUTO-RELOAD ENABLE  //TIM2->CCER = ~TIM_CCER_CC1P;    //0<<1  ACTİVE HIGH
	TIM2->CCER |=  TIM_CCER_CC1E;    //1<<0  ENABLE OCx

	TIM2->CR1  |= 1<<0;           //enable timer
	TIM2->EGR  |= 1<<0;           //UG SET EDİLDİ
	//while(!(TIM2->SR &(1<<0)));   //UIF bagragı 1 oldu mu diye bak
}
