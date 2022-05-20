/*
 * led.c
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */

#ifndef LED_C_
#define LED_C_

#include "led.h"

void LedInit(uint32_t pin) {
	// enable GPIO clock
	RCC->AHB1ENR |= BV(AHB1ENR_LEDGPIO_EN);
	// set GPIO mode as output
	LED_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	LED_GPIO->MODER |= BV(pin * 2);
	// set GPIO speed as low
	LED_GPIO->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set GPIO output type as push-pull
	LED_GPIO->OTYPER &= ~BV(pin);
	// set GPIO pupd as none
	LED_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
}

void LedOn(uint32_t pin) {
	// make pin high
	LED_GPIO->ODR |= BV(pin);
}

void LedOff(uint32_t pin) {
	// make pin low
	LED_GPIO->ODR &= ~BV(pin);
}

void LedBlink(uint32_t pin, uint32_t ms) {
	LedOn(pin);
	DelayMs(ms);
	LedOff(pin);
}

#endif /* LED_C_ */
