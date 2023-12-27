/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: HAL				**************/
/********************		SWC: ULTRASONIC			**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "TIMER1_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"

#define TRIG_PORT    DIO_u8PORTA
#define TRIG_PIN     DIO_u8PIN0


void ULTRASONIC_u8Init(void);
u8 ULTRASONIC_u8GETReadCM(void);

void ULTRASONIC_voidStart(void);
void ULTRASONIC_voidStop(void);


void ISR_ULTRASONIC(void);

#endif
