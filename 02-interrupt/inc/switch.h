/*
 * switch.h
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "stm32f4xx.h"

#define SWITCH_GPIO				GPIOA
#define SWITCH_PIN				0
#define AHB1ENR_SWITCH_GPIO_EN	0

void SwitchInit(uint32_t pin);
int SwitchGetState(uint32_t pin);

#endif /* SWITCH_H_ */
