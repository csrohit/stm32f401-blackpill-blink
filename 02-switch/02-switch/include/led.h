#include "stm32f4xx.h"


#ifndef __LED_H

#define BV(n)     (1 << (n))
#define LED_PORT GPIOC
#define AHB1ENR_LEDPORT_EN 2
#define LED_PIN 13

void ms_delay(int ms);

void led_init(uint8_t pin);
void led_on(uint32_t pin);
void led_off(uint32_t pin);
void led_blink(uint32_t pin, uint32_t ms);
#define __LED_H

#endif