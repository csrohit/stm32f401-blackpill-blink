/*
 * led.h
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"

#define LED_GREEN_PIN	12
#define LED_ORANGE_PIN	13
#define LED_RED_PIN		14
#define LED_BLUE_PIN	15

#define LED_GPIO			GPIOD
#define AHB1ENR_LEDGPIO_EN	3

void LedInit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
void LedBlink(uint32_t pin, uint32_t ms);

#endif /* LED_H_ */
