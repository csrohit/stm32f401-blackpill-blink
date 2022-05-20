#include <stdint.h>
#include "stm32f4xx.h"
#include "led.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SwitchInit(SWITCH_PIN);
	gpio_init(LED_PIN);
	while(1) {
		// wait until switch is pressed
		while(SwitchGetState(SWITCH_PIN) == 0)
			;
		// blink
		gpio_pulse(LED_PIN, 1000);
	}
	return 0;
}
