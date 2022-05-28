/**
 * @file switch.c
 * @author Rohit Nimkar
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "switch.h"
#include "led.h"

volatile uint8_t flag = 0;

/**
 * @brief Initialise GPIO pin as
 * 	INPUT
 * 	LOW SPEED
 * 	NO PUSH PULL
 *
 * @param pin pin number
 */
void switch_init(uint32_t pin)
{
	// enable GPIO clock
	RCC->AHB1ENR |= BV(AHB1ENR_SWITCH_GPIO_EN);
	// set gpio mode as input
	SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set gpio speed as low
	SWITCH_GPIO->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set pupd as none
	SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));

	/* configure exti to generate interrupt when switch is released */
	// enable falling edge detection
	EXTI->FTSR |= BV(SWITCH_PIN);
	// enable (unmask) exti interrupt for switch (exti0)
	EXTI->IMR |= BV(SWITCH_PIN);
	// PA0 --> EXTI0 : configure in SYSCFG EXTICR0 regr
	SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));
	/* configure NVIC to send exti0 interrupt to ARM core */
	// enable exti0 interrupt in ISER
	//NVIC->ISER[0] |= BV(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);

}

/**
 * @brief Read status of gpio pin
 *
 * @param pin pin number
 * @return int state of gpio pin
 */
int gpio_read(uint32_t pin)
{
	return (SWITCH_GPIO->IDR & BV(SWITCH_PIN)) == 0 ? 0 : 1;
}

/**
 * @brief Interrupt service routine for EXTI0 interrupt
 *
 */
void EXTI0_IRQHandler()
{
	EXTI->PR |= BV(SWITCH_PIN);
	
	flag = 1;
}