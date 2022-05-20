/**
 * @file led.h
 * @author Rohit Nimkar (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"

#define LED_PIN	13

#define LED_GPIO			GPIOC
#define AHB1ENR_LEDGPIO_EN	2

void gpio_init(uint32_t pin);
void gpio_set(uint32_t pin);
void gpio_clear(uint32_t pin);
void gpio_pulse(uint32_t pin, uint32_t ms);

#endif /* LED_H_ */
