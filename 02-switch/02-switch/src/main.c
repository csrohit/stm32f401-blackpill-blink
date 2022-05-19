
#include "stm32f4xx.h"
#include "led.h"
#include "switch.h"


int main(void){
    
    led_init(LED_PIN);
    while (1)
    {
        led_blink(LED_PIN, 2000);
        ms_delay(2000);
    }
}