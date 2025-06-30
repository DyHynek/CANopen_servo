#include "LM35.h"
float LM35_Gettemp(uint8_t channel)
{
	float temp=24.4;
	if(channel == 0) temp = temp *2;
	if(channel == 1) temp = temp /2;
	return temp;
}
