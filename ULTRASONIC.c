/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: HAL				**************/
/********************		SWC: ULTRASONIC			**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-10-2023		**************/
/*****************************************************************/
/*****************************************************************/
#include "ULTRASONIC.h"

static void (*ULTRASONIC_pvCallBackFunc)(void)=NULL;
static f32 ontime=0;

//ultrasonic init
void ULTRASONIC_u8Init(void)
{
	TIMER1_voidInit();
	ICU_voidSetCallBack(ISR_ULTRASONIC);
	ICU_voidInit();
	ICU_EnableINT();
}

//this will return value after ICU finished its work
u8 ULTRASONIC_u8GETReadCM()
{
	return ontime;
}

//this call to start ICU and Ultrasonic
void ULTRASONIC_voidStart(void)
{
	TIMER1_voidSTART();
	DIO_u8SetPinValue(TRIG_PORT,TRIG_PIN,DIO_u8PIN_HIGH);
	_delay_us(15);
	DIO_u8SetPinValue(TRIG_PORT,TRIG_PIN,DIO_u8PIN_LOW);
}

void ULTRASONIC_voidStop(void)
{
	TIMER1_voidSTOP();
}

void ISR_ULTRASONIC(void)
{
	static u8 count=0;
	static u16 R1,R2=0;
	count++;
	if(count==1)
	{
		R1=ICU_u16ReadInputCapture();
		ICU_voidSetTriggerEdge(ICU_FALLING_EDGE);
	}
	else if(count==2)
	{
		R2=ICU_u16ReadInputCapture();
		ULTRASONIC_voidStop();
		ICU_voidSetTriggerEdge(ICU_RISING_EDGE);
		count=0;
		ontime=R2-R1;
		ontime/=2;
		ontime/=235 ;

		ULTRASONIC_pvCallBackFunc();
	}
}

void ULTRASONIC_voidSetCallBack(void (*copy_pvCallBackFunc)(void))
{
	ULTRASONIC_pvCallBackFunc=copy_pvCallBackFunc;
}
