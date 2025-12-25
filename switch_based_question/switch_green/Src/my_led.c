/*
 * my_led.c
 *
 *  Created on: Dec 17, 2025
 *      Author: kiran_z6dopa8
 */

#include "my_led.h"

void led_init(void)
{
	//0. enable clock for GPIOD in AHB1
	RCC->AHB1ENR |= BV(3);
	//1. select mode as output
	LED_PORT->MODER &= ~(BV(25) );
	LED_PORT->MODER |= BV(24) ;
	//2. select type as push pull
	LED_PORT->OTYPER &= ~(BV(12) );
	//3. select speed as low
	LED_PORT->OSPEEDR &= ~(BV(25) );
	GPIOD->OSPEEDR &= ~(BV(24) );
	//4. select pull up/down as no
	LED_PORT->PUPDR &= ~(BV(25) );
	LED_PORT->PUPDR &= ~(BV(24) );
}
void led_on(void)
{
	GPIOD->ODR |= BV(GREEN_LED);
}
void led_off(void)
{
	GPIOD->ODR &= ~(BV(GREEN_LED));
}

