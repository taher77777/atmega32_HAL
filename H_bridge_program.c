#include "H_bridge_interface.h"

u8 Global_u8Motor1Speed = 00;
u8 Global_u8Motor2Speed = 00;

void H_BRIDGE_Start(u8 motor1_u8Speed, u8 motor2_u8Speed) {

	if ((motor1_u8Speed < +100) && (motor2_u8Speed <= 100)) {
		Global_u8Motor1Speed = motor1_u8Speed;
		Global_u8Motor2Speed = motor2_u8Speed;
#if H_BRIDGE_ENA_TIMER==TIMER0
		TIMER0_voidInit();
		TIMER0_voidSetDyty(motor1_u8Speed);
		TIMER0_voidStart();
#elif H_BRIDGE_ENA_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
		TIMER2_voidInit();
		TIMER2_voidSetDyty(motor1_u8Speed);
		TIMER2_voidStart();
#endif
#if H_BRIDGE_ENB_TIMER==TIMER0
		TIMER0_voidInit();
		TIMER0_voidSetDyty(motor2_u8Speed);
		TIMER0_voidStart();
#elif H_BRIDGE_ENB_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
		TIMER2_voidInit();
		TIMER2_voidSetDyty(motor2_u8Speed);
		TIMER2_voidStart();
#endif
	} else {
		//do nothing
	}

}

void H_BRIDGE_Stop(void) {
	Global_u8Motor1Speed = 0;
	Global_u8Motor2Speed = 0;
#if H_BRIDGE_ENA_TIMER==TIMER0
	TIMER0_voidSetDyty(0);
#elif H_BRIDGE_ENA_TIMER==TIMER1
	//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
	TIMER2_voidSetDyty(0);
#endif
#if H_BRIDGE_ENB_TIMER==TIMER0
	TIMER0_voidSetDyty(0);
#elif H_BRIDGE_ENB_TIMER==TIMER1
	//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
	TIMER2_voidSetDyty(0);
#endif
}

void H_BRIDGE_Forword(void) {
	DIO_u8SetPinValue(H_BRIDGE_N1_PORT, H_BRIDGE_N1_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(H_BRIDGE_N2_PORT, H_BRIDGE_N2_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(H_BRIDGE_N3_PORT, H_BRIDGE_N3_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(H_BRIDGE_N4_PORT, H_BRIDGE_N4_PIN, DIO_u8PIN_LOW);
}

void H_BRIDGE_Backword(void) {
	DIO_u8SetPinValue(H_BRIDGE_N1_PORT, H_BRIDGE_N1_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(H_BRIDGE_N2_PORT, H_BRIDGE_N2_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(H_BRIDGE_N3_PORT, H_BRIDGE_N3_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(H_BRIDGE_N4_PORT, H_BRIDGE_N4_PIN, DIO_u8PIN_HIGH);
}

void H_BRIDGE_Right(void) {
	Global_u8Motor2Speed = 0;
#if H_BRIDGE_ENB_TIMER==TIMER0
	TIMER0_voidSetDyty(0);
#elif H_BRIDGE_ENB_TIMER==TIMER1
	//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
	TIMER2_voidSetDyty(0);
#endif
}

void H_BRIDGE_Left(void) {
	Global_u8Motor1Speed = 0;
#if H_BRIDGE_ENA_TIMER==TIMER0
	TIMER0_voidSetDyty(0);
#elif H_BRIDGE_ENA_TIMER==TIMER1
	//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
	TIMER2_voidSetDyty(0);
#endif
}

void H_BRIDGE_SetSpeed(u8 motor1_u8Speed, u8 motor2_u8Speed) {

	if ((motor1_u8Speed < +100) && (motor2_u8Speed <= 100)) {
		Global_u8Motor1Speed = motor1_u8Speed;
		Global_u8Motor2Speed = motor2_u8Speed;
#if H_BRIDGE_ENA_TIMER==TIMER0
		TIMER0_voidSetDyty(motor1_u8Speed);
#elif H_BRIDGE_ENA_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
		TIMER2_voidSetDyty(motor1_u8Speed);
#endif

#if H_BRIDGE_ENB_TIMER==TIMER0
		TIMER0_voidSetDyty(motor2_u8Speed);
#elif H_BRIDGE_ENB_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
		TIMER2_voidSetDyty(motor2_u8Speed);
#endif
	} else {
		//do nothing
	}
}


void H_BRIDGE_IncreaseSpeed(u8 motor1_u8IncreaseValue,u8 motor2_u8IncreaseValue) {

	if (((Global_u8Motor1Speed + motor1_u8IncreaseValue) <= 100)
			&& ((Global_u8Motor2Speed + motor2_u8IncreaseValue) <= 100)) {
		Global_u8Motor1Speed += motor1_u8IncreaseValue;
		Global_u8Motor2Speed += motor1_u8IncreaseValue;
#if H_BRIDGE_ENA_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENA_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif

#if H_BRIDGE_ENB_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENB_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif
	} else {
		Global_u8Motor1Speed = 99;
		Global_u8Motor2Speed = 99;
#if H_BRIDGE_ENA_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENA_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif

#if H_BRIDGE_ENB_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENB_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif
	}
}

void H_BRIDGE_DecreaseSpeed(u8 motor1_u8DecreaseValue,u8 motor2_u8DecreaseValue) {


	if (((Global_u8Motor1Speed - motor1_u8DecreaseValue) > 0)
			&& ((Global_u8Motor2Speed - motor2_u8DecreaseValue) >0)) {

		Global_u8Motor1Speed -= motor1_u8DecreaseValue;
		Global_u8Motor2Speed -= motor2_u8DecreaseValue;

#if H_BRIDGE_ENA_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENA_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif

#if H_BRIDGE_ENB_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENB_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif
	} else {
		Global_u8Motor1Speed = 0;
		Global_u8Motor2Speed = 0;
#if H_BRIDGE_ENA_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENA_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENA_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif

#if H_BRIDGE_ENB_TIMER==TIMER0
		TIMER0_voidSetDyty(Global_u8Motor1Speed);
#elif H_BRIDGE_ENB_TIMER==TIMER1
		//no yet
#elif H_BRIDGE_ENB_TIMER==TIMER2
		TIMER2_voidSetDyty(Global_u8Motor1Speed);
#endif
	}
}
