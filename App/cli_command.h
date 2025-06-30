#ifndef CLI_COMMMAND_H
#define CLI_COMMMAND_H
#include "stdint.h"
#include "string.h"
#include "GetTemperature_ci.h"
#include "response_ci.h"

void cli_command_excute(char *uart_buff, uint8_t len);
#endif
