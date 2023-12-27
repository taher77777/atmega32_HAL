
#ifndef H_BRIDGE_INTERFACE_H_
#define H_BRIDGE_INTERFACE_H_
/************************************************
					INCLUDES
************************************************/
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "H_bridge_config.h"
#include "TIMER0_interface.h"
#include "TIMER2_interface.h"

/************************************************
					functions
************************************************/


void H_BRIDGE_Start(u8 motor1_u8Speed,u8 motor2_u8Speed);

void H_BRIDGE_Stop(void);

void H_BRIDGE_Forword(void);

void H_BRIDGE_Backword(void);

void H_BRIDGE_Right(void);

void H_BRIDGE_Left(void);

void H_BRIDGE_SetSpeed(u8 motor1_u8Speed,u8 motor2_u8Speed);

void H_BRIDGE_IncreaseSpeed(u8 motor1_u8IncreaseValue,u8 motor2_u8IncreaseValue);

void H_BRIDGE_DecreaseSpeed(u8 motor1_u8DecreaseValue,u8 motor2_u8DecreaseValue);



#endif /* H_BRIDGE_H_ */
