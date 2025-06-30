#include "PDO_cmd_user.h"
extern RNG_HandleTypeDef hrng;

extern uint32_t tmp ;
extern uint8_t amount_read ;
ServoParams Params;

void Random_position()
{
	uint32_t randomSeed;
		if (HAL_RNG_GenerateRandomNumber(&hrng, &randomSeed) == HAL_OK) {
			  srand(randomSeed);
		} else {
			  Error_Handler();
		}
}

CO_ReturnError_t Send_PDOPosition(CANopenNodeSTM32 *canopenNode, uint32_t __node_id, uint32_t TargetPosition)
{
	canopenNode->canOpenStack->CANmodule->txArray->DLC = 4;
	canopenNode->canOpenStack->CANmodule->txArray->ident =  __node_id;

	canopenNode->canOpenStack->CANmodule->txArray->data[0] = TargetPosition 		& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[1] = (TargetPosition>>8)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[2] = (TargetPosition>>16)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[3] = (TargetPosition>>24)	& 0xFFU;

	return CO_CANsend(canopenNode->canOpenStack->CANmodule, canopenNode->canOpenStack->CANmodule->txArray);
}
CO_ReturnError_t Send_PDOProfileSpeed(CANopenNodeSTM32 *canopenNode, uint32_t __node_id, uint32_t TargetSpeed)
{
	canopenNode->canOpenStack->CANmodule->txArray->DLC = 4;
	canopenNode->canOpenStack->CANmodule->txArray->ident =   __node_id;

	canopenNode->canOpenStack->CANmodule->txArray->data[0] = TargetSpeed 		& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[1] = (TargetSpeed>>8)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[2] = (TargetSpeed>>16)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[3] = (TargetSpeed>>24)	& 0xFFU;

	return CO_CANsend(canopenNode->canOpenStack->CANmodule, canopenNode->canOpenStack->CANmodule->txArray);
}
CO_ReturnError_t Send_PDOAcceleration(CANopenNodeSTM32 *canopenNode, uint32_t __node_id, uint32_t Acceleration)
{
	canopenNode->canOpenStack->CANmodule->txArray->DLC = 4;
	canopenNode->canOpenStack->CANmodule->txArray->ident =  __node_id;

	canopenNode->canOpenStack->CANmodule->txArray->data[0] = Acceleration 		& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[1] = (Acceleration>>8)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[2] = (Acceleration>>16)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[3] = (Acceleration>>24)	& 0xFFU;

	return CO_CANsend(canopenNode->canOpenStack->CANmodule, canopenNode->canOpenStack->CANmodule->txArray);
}

CO_ReturnError_t Send_PDODeceleration(CANopenNodeSTM32 *canopenNode, uint32_t __node_id, uint32_t Deceleration)
{
	canopenNode->canOpenStack->CANmodule->txArray->DLC = 4;
	canopenNode->canOpenStack->CANmodule->txArray->ident =   __node_id;

	canopenNode->canOpenStack->CANmodule->txArray->data[0] = Deceleration 		& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[1] = (Deceleration>>8)	& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[0] = (Deceleration>>16) & 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[1] = (Deceleration>>24)	& 0xFFU;

	return CO_CANsend(canopenNode->canOpenStack->CANmodule, canopenNode->canOpenStack->CANmodule->txArray);
}



CO_ReturnError_t Send_PDOControlWord(CANopenNodeSTM32 *canopenNode, uint32_t __node_id, uint16_t ControlWord)
{
	canopenNode->canOpenStack->CANmodule->txArray->DLC = 2;
	canopenNode->canOpenStack->CANmodule->txArray->ident =   __node_id;

	canopenNode->canOpenStack->CANmodule->txArray->data[0] = ControlWord 		& 0xFFU;
	canopenNode->canOpenStack->CANmodule->txArray->data[1] = (ControlWord>>8)	& 0xFFU;

	return CO_CANsend(canopenNode->canOpenStack->CANmodule, canopenNode->canOpenStack->CANmodule->txArray);
}


uint32_t actual_p;
void CO_PDO_running(CANopenNodeSTM32 *canopenNode, uint8_t node_id, int32_t targetP)
{
//	Random_position();
//	uint32_t targetP = 100000;
//	uint32_t randomNumber = (rand() % 20)*10000;
	Send_PDOPosition(canopenNode, 0x300 + node_id, targetP);
	HAL_Delay(1);
//	Start of a movement and set relative position
	Send_PDOControlWord(canopenNode, 0x200 + node_id, 0x1F);
	HAL_Delay(50);
	Send_PDOControlWord(canopenNode, 0x200 + node_id, 0x0F);
	actual_p = SDO_user_read(canopenNode, node_id, 0x6064, 0x00);
	response_print("Servo: %d 	Target Position: %u		Actual Position: %u\n",node_id, targetP, actual_p);
//	//Response from status word
//	Send_SDO(canopenNode, 1, 0x40, 0x604100, 0x00);
	HAL_Delay(300);
//
//	if(((Rx_Data[5] >>4) & 0001) == 1)
//	{
//		// Reset of the start bit
//		Send_PDOControlWord(&canopenNode_1, 0x201, 0x0F);
//		HAL_Delay(10);
//	}
}


void store_to_buffer(uint32_t value, uint8_t *buffer, size_t *index, size_t sizeOfvalue) {
    memcpy(&buffer[*index], &value, sizeOfvalue);
    *index += sizeOfvalue;
}

uint32_t chartohex(char *value)
{
    char *endptr;
    uint32_t num  = strtol(value, &endptr, 10);
    if (*endptr != '\0') {
        return -1;
    } else {
        return num;
    }
}



void running_servo(char **argv, uint8_t argv_num)
{
//	uint8_t buffer[10];
//	size_t index = 0;

//	uint8_t node_id_1 = chartohex(argv[1]);
//	uint32_t targetP_1 = chartohex(argv[2]);
//	uint8_t node_id_2 = chartohex(argv[3]);
//	uint32_t targetP_2 = chartohex(argv[4]);
	 Params.node_id_1 = chartohex(argv[1]);
	 Params.targetP_1 = chartohex(argv[2]);
	 Params.node_id_2 = chartohex(argv[3]);
	 Params.targetP_2 = chartohex(argv[4]);
//    store_to_buffer(node_id_1, buffer, &index, sizeof(uint8_t));
//    store_to_buffer(targetP_1, buffer, &index, sizeof(uint32_t));
//    store_to_buffer(node_id_2, buffer, &index, sizeof(uint8_t));
//    store_to_buffer(targetP_2, buffer, &index, sizeof(uint32_t));

//    response_print("%02X %02X %02X %02X\n",Params.node_id_1, Params.node_id_2, Params.targetP_1, Params.targetP_2);
}

void CO_PDO_execute(CANopenNodeSTM32 *canopenNode)
{
	CO_PDO_running(canopenNode, Params.node_id_1, Params.targetP_1);
	CO_PDO_running(canopenNode, Params.node_id_2, Params.targetP_2);
//	CO_PDO_running(canopenNode, 2 ,9000);
}
