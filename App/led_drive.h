#ifndef LED_DRIVER_H
#define LED_DRIVER_H
#include "main.h"

typedef struct
{
	void (*test_function)();
}led;

void set_led(uint8_t index, uint8_t sta);
void toggle_led();
void set_all_led(uint8_t sta);
void led_driver_init(void);
void led_init(led* __led_test, void (*__test_function)(void));
#endif
