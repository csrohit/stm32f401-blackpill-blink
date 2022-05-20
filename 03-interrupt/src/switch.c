/*
 * switch.c
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */
#include "switch.h"

void SwitchInit(uint32_t pin) {
	// enable GPIO clock
	RCC->AHB1ENR |= BV(AHB1ENR_SWITCH_GPIO_EN);
	// set gpio mode as input
	SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set gpio speed as low
	SWITCH_GPIO->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set pupd as none
	SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
}

int SwitchGetState(uint32_t pin) {
	// get switch state
	uint32_t state = SWITCH_GPIO->IDR;
	// return 1 when pressed, 0 when released
	return (state & BV(SWITCH_PIN)) ? 1 : 0;
}

