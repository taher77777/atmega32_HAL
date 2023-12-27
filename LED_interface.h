/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  HAL             **************************/
/*****************    SWC:    LED             **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* SET LED ON */
void LED_voidTurnOn(u8 Copy_u8Port,u8 Copy_u8Pin);

/* SET LED off */
void LED_voidTurnOff(u8 Copy_u8Port,u8 Copy_u8Pin);

/* TOGGLE LED */
void LED_voidToggle(u8 Copy_u8Port,u8 Copy_u8Pin);

#endif
