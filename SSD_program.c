/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  HAL             **************************/
/*****************    SWC:    SSD             **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

/*SSD NUMBERS*/
u8 Sev_u8Seg [10] ={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

/*CONFIGRATION*/
#if SSD_TYPE == SSD_COMMEN_CATHODE

void SSD_u8SetNumber(u8 Copy_u8Number,u8 Copy_u8Port)
{	
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA :PORTA=Sev_u8Seg[Copy_u8Number];  break;
	case DIO_u8PORTB :PORTB=Sev_u8Seg[Copy_u8Number];  break;
	case DIO_u8PORTC :PORTC=Sev_u8Seg[Copy_u8Number];  break;
	case DIO_u8PORTD :PORTD=Sev_u8Seg[Copy_u8Number];  break;
	default :break;
	}
}
void SSD_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
}

void SSD_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
}
#elif SSD_TYPE==SSD_COMMEN_ANODE
void SSD_u8SetNumber(u8 Copy_u8Number,u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA :PORTA=~Sev_u8Seg[Copy_u8Number];  break;
	case DIO_u8PORTB :PORTB=~Sev_u8Seg[Copy_u8Number];  break;
	case DIO_u8PORTC :PORTC=~Sev_u8Seg[Copy_u8Number];  break;
	case DIO_u8PORTD :PORTD=~Sev_u8Seg[Copy_u8Number];  break;
	default : break;
	}
}
void SSD_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
}

void SSD_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
}
#endif
