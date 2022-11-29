/*
 * DIO_Interface.h
 *
 *  Created on: Nov 20, 2022
 *      Author: hp
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define GROUP_A 0
#define GROUP_B 1
#define GROUP_C 2
#define GROUP_D 3

#define DIO_u8_Pin_0 0
#define DIO_u8_Pin_1 1
#define DIO_u8_Pin_2 2
#define DIO_u8_Pin_3 3
#define DIO_u8_Pin_4 4
#define DIO_u8_Pin_5 5
#define DIO_u8_Pin_6 6
#define DIO_u8_Pin_7 7

#define DIO_u8_High 1
#define DIO_u8_Low 0

#define DIO_u8_Input 0
#define DIO_u8_Output 1

#define DIO_u8_ERR_Inil_Val 0
#define DIO_u8_ERR_Port_ID 1
#define DIO_u8_ERR_Pin_ID 2
#define DIO_u8_ERR_Pin_Val 3
#define DIO_u8_ERR_Pin_Dir 4
#define DIO_u8_ERR_Port_Val 5
#define DIO_u8_ERR_Port_Dir 6

u8 DIO_Set_Pin_value (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_Val);
u8 DIO_Set_Pin_dir (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,  u8 Copy_u8_Pin_dir);
u8 DIO_Get_Pin_value (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,u8 *Copy_u8_Pin_Val);

u8 DIO_Set_Port_value (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_Val);
u8 DIO_Set_Port_dir (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_dir);
u8 DIO_Ger_Port_value (u8 Copy_u8_Port_ID, u8 *Copy_u8_Port_dir);


#endif /* DIO_INTERFACE_H_ */
