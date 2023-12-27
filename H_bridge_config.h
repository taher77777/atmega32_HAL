/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  HAL             **************************/
/*****************    SWC:    H_BRIDGE        **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#ifndef H_BRIDGE_CONFIG_H_
#define H_BRIDGE_CONFIG_H_

/************************************************
					PINS
************************************************/
/*****TIMER TYPES******/
#define TIMER0     1
#define TIMER1     2
#define TIMER2     3

//MOTOR1
#define H_BRIDGE_ENA_TIMER         TIMER0
#define H_BRIDGE_N1_PORT		   DIO_u8PORTA
#define H_BRIDGE_N1_PIN			   DIO_u8PIN0
#define H_BRIDGE_N2_PORT           DIO_u8PORTA
#define H_BRIDGE_N2_PIN            DIO_u8PIN1
//MOTOR2
#define H_BRIDGE_ENB_TIMER         TIMER2
#define H_BRIDGE_N3_PORT           DIO_u8PORTA
#define H_BRIDGE_N3_PIN            DIO_u8PIN2
#define H_BRIDGE_N4_PORT           DIO_u8PORTA
#define H_BRIDGE_N4_PIN            DIO_u8PIN3
#endif