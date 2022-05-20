#include "stm32f4xx.h"
#include "led.h"


/**
 * @brief Add blocking delay
 * 
 * @param ms number of milliseconds
 */
void ms_delay(int ms)
{
    while (ms-- > 0)
    {
        volatile int x = 500;
        while (x-- > 0)
            __asm("nop");
    }
}

/**
 * @brief Initialize led pin as output in push pull state
 * 
 * @param pin pin number
 */
void led_init(uint8_t pin){
	// enable GPIO clock
	RCC->AHB1ENR |= BV(AHB1ENR_LEDPORT_EN);
	// set GPIO mode as output
	LED_PORT->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	LED_PORT->MODER |= BV(pin * 2);
	// set GPIO speed as low
	LED_PORT->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set GPIO output type as push-pull
	LED_PORT->OTYPER &= ~BV(pin);
	// set GPIO pupd as none
	LED_PORT->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));


}

/**
 * @brief Turn on the led connected to the pin
 * 
 * @param pin pin number
 */
void led_on(uint32_t pin) {
	// make pin high
	LED_PORT->ODR |= BV(pin);
}

/**
 * @brief Turn off the led connected to the pin
 * 
 * @param pin pin number
 */
void led_off(uint32_t pin) {
	// make pin low
	LED_PORT->ODR &= ~BV(pin);
}

/**
 * @brief Blink led connected to pin
 * 
 * @param pin pin number
 * @param ms delay in milliseconds
 */
void led_blink(uint32_t pin, uint32_t ms) {
	led_on(pin);
	ms_delay(ms);
	led_off(pin);
}
