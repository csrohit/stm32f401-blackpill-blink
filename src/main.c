#include <stdint.h>
#include "stm32f4xx.h"
#include "led.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	// switch_init(SWITCH_PIN);
	gpio_init(LED_PIN);
	// gpio_set(LED_PIN);
	while (1)
	{
		// wait until switch is pressed
		// if (flag == 1)
		// {
		// 	flag = 0;
			gpio_pulse(LED_PIN, 200);
			DelayMs(200);

		// }
	}
	return 0;
}
