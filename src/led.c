/*
 * led.c
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */

#ifndef LED_C_
#define LED_C_

#include "led.h"

/**
 * @brief Initialise gpio pin as
 * 	OUTPUT
 * 	PUSH-PULL
 * 	NO_PULLUP_PULLDOWN
 * 	set LOW SPEED
 * 
 * @param pin 
 */
void gpio_init(uint32_t pin) {
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

/**
 * @brief Set gpio pin
 * 
 * @param pin pin number
 */
void gpio_set(uint32_t pin) {
	LED_GPIO->ODR |= BV(pin);
}

/**
 * @brief clear gpio pin
 * 
 * @param pin pin number
 */
void gpio_clear(uint32_t pin) {
	// make pin low
	LED_GPIO->ODR &= ~BV(pin);
}

/**
 * @brief Send high to low pulse to gpio
 * 
 * @param pin pin number
 * @param ms high time in milliseconds
 */
void gpio_pulse(uint32_t pin, uint32_t ms) {
	gpio_clear(pin);
	DelayMs(ms);
	gpio_set(pin);
}

#endif /* LED_C_ */
