#include "GetTemperature_ci.h"
#include "response_ci.h"

void GetTemperature(char **argv, uint8_t argv_num)
{                              
	if(argv_num < 2 )            
	{                            
		response_print("don't enough argv, argv = %d", argv_num);
		return;                    
	}
	if(argv_num > 2 )            
	{                            
		response_print("too much argv, argv = %d", argv_num);
		return;                    
	}
	if(argv_num == 2 )            
	{ 
//		response_print("data\n");
		response_print("test = %s\n", argv[1]);
//		uint8_t channel = atoi(argv[1]);
//		response_print("temperature = %f\n", LM35_Gettemp(channel));
		return;                    
	}	
}
