#include "led_drive.h"

void set_led(uint8_t index, uint8_t sta)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 << index, (GPIO_PinState)sta);
}
void toggle_led()
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_0 << 13);
}
void set_all_led(uint8_t sta)
{
	for(uint8_t i=0; i<8; i++)
	{
		set_led(i,sta);
	}
}
void led_driver_init()
{
	
}

led led_test;
void led_init(led* __led_test, void (*__test_function)(void))
{
	__led_test->test_function = __test_function;
}

