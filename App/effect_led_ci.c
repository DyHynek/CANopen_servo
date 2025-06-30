#include "effect_led_ci.h"

void set_effect_led(char **argv, uint8_t argv_num)
{
	uint8_t index_effect = atoi(argv[1]);
	if(index_effect == 1)
	{
		uint16_t freq = atoi(argv[2]);
		app_led_blink_all(freq);
//		response_print("ok_10\n");
//		HAL_Delay(30);
		response_print("ok_1\n");
	}
	if(index_effect == 2)
	{
		uint16_t freq = atoi(argv[2]);
		app_led_light_up(freq);
		response_print("ok_2\n");
	}
}
