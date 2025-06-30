#include "cli_command_table.h"

const cli_command_info_t command_infor_gettemp =
{
	GetTemperature,
	"command get temp from LM35: \"Gettemp argv\" "
};
const cli_command_info_t command_infor_settemp_max =
{
	SetTemperatureMax,
	"command set temp max: \"SetTempMax argv\" "
};
const cli_command_info_t command_infor_setEffect_led =
{
	set_effect_led,
	"command set effect led: \"SetEffect_Led argv\" "
};
const cli_command_info_t command_infor_running_servo =
{
	running_servo,
	"command set effect led: \"SetEffect_Led argv\" "
};
const	cli_command_entry_t command_entry_table[] = 
{
	{"Gettem",&command_infor_gettemp},
	{"SetTempMax",&command_infor_settemp_max},
	{"SetEffect_Led",&command_infor_setEffect_led},
	{"Running_Servo",&command_infor_running_servo},
	{NULL,NULL},
};
