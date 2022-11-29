/*
 * DIO_Program.c

 *
 *  Created on: Nov 20, 2022
 *      Author: hp
 */

#include "BIT_CALC.h"
#include "STD_Types.h"

#include "DIO_Private.h"
#include "DIO_Configration.h"
#include "DIO_Interface.h"


u8 DIO_Set_Pin_value (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_Val)
{
	u8 Error_state= DIO_u8_ERR_Inil_Val;

	if((Copy_u8_Port_ID >= MIN_Port_ID) && (Copy_u8_Port_ID) <= MAX_Port_ID ){
		if((Copy_u8_Pin_ID >= MIN_Pin_ID) && (Copy_u8_Pin_ID) <= MAX_Pin_ID ){
			if((Copy_u8_Pin_Val == MIN_Pin_Val) || (Copy_u8_Pin_Val) == MAX_Pin_Val ){
				switch (Copy_u8_Port_ID){
				case GROUP_A :
					Assign_Bit(DIO_u8_PORTA,Copy_u8_Pin_ID,Copy_u8_Pin_Val);
					break;

				case GROUP_B :
					Assign_Bit(DIO_u8_PORTB,Copy_u8_Pin_ID,Copy_u8_Pin_Val);
					break;

				case GROUP_C :
					Assign_Bit(DIO_u8_PORTC,Copy_u8_Pin_ID,Copy_u8_Pin_Val);
					break;

				case GROUP_D :
					Assign_Bit(DIO_u8_PORTD,Copy_u8_Pin_ID,Copy_u8_Pin_Val);
					break;
				}
			}else{
				Error_state=  DIO_u8_ERR_Pin_Val;
			}
		}else{
			Error_state= DIO_u8_ERR_Pin_ID;
		}
	}else{
		Error_state= DIO_u8_ERR_Port_ID;
	}
	return Error_state;
}

u8 DIO_Set_Pin_dir (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_dir)
{
	u8 Error_state= DIO_u8_ERR_Inil_Val;
	if((Copy_u8_Port_ID >= MIN_Port_ID) && (Copy_u8_Port_ID) <= MAX_Port_ID ){
			if((Copy_u8_Pin_ID >= MIN_Pin_ID) && (Copy_u8_Pin_ID) <= MAX_Pin_ID ){
				if((Copy_u8_Pin_dir == MIN_Pin_dir) || (Copy_u8_Pin_dir) == MAX_Pin_dir ){
					switch (Copy_u8_Port_ID){
					case GROUP_A :
						Assign_Bit(DIO_u8_PORTA,Copy_u8_Pin_ID,Copy_u8_Pin_dir);
						break;

					case GROUP_B :
						Assign_Bit(DIO_u8_PORTB,Copy_u8_Pin_ID,Copy_u8_Pin_dir);
						break;

					case GROUP_C :
						Assign_Bit(DIO_u8_PORTC,Copy_u8_Pin_ID,Copy_u8_Pin_dir);
						break;

					case GROUP_D :
						Assign_Bit(DIO_u8_PORTD,Copy_u8_Pin_ID,Copy_u8_Pin_dir);
						break;
					}
				}else{
					Error_state=  DIO_u8_ERR_Pin_Dir;
				}
			}else{
				Error_state= DIO_u8_ERR_Pin_ID;
			}
		}else{
			Error_state= DIO_u8_ERR_Port_ID;
		}

	return Error_state;
}

u8 DIO_Get_Pin_value (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,u8 *Copy_u8_Pin_Val){

	u8 Error_state= DIO_u8_ERR_Inil_Val;
		if((Copy_u8_Port_ID >= MIN_Port_ID) && (Copy_u8_Port_ID) <= MAX_Port_ID ){
				if((Copy_u8_Pin_ID >= MIN_Pin_ID) && (Copy_u8_Pin_ID) <= MAX_Pin_ID ){
						switch (Copy_u8_Port_ID){
						case GROUP_A :
							*Copy_u8_Pin_Val = Get_Bit(DIO_u8_PINA,Copy_u8_Port_ID);
							break;

						case GROUP_B :
							*Copy_u8_Pin_Val = Get_Bit(DIO_u8_PINB,Copy_u8_Port_ID);
							break;

						case GROUP_C :
							*Copy_u8_Pin_Val = Get_Bit(DIO_u8_PINC,Copy_u8_Port_ID);
							break;

						case GROUP_D :
							*Copy_u8_Pin_Val = Get_Bit(DIO_u8_PIND,Copy_u8_Port_ID);
							break;
						}
				}else{
						Error_state= DIO_u8_ERR_Pin_ID;
					}
				}else{
					Error_state= DIO_u8_ERR_Port_ID;
				}
			return Error_state;
		}

u8 DIO_Set_Port_value (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_Val)
{
	u8 Error_state= DIO_u8_ERR_Inil_Val;

	if((Copy_u8_Port_ID >= MIN_Port_ID) && (Copy_u8_Port_ID <= MAX_Port_ID) ){
			if((Copy_u8_Port_Val >= MIN_Port_Val) && (Copy_u8_Port_Val <= MAX_Port_Val) ){
				switch (Copy_u8_Port_ID){
				case GROUP_A :
					DIO_u8_PORTA =Copy_u8_Port_Val ;
					break;

				case GROUP_B :
					DIO_u8_PORTB =Copy_u8_Port_Val ;
					break;

				case GROUP_C :
					DIO_u8_PORTC =Copy_u8_Port_Val ;
					break;

				case GROUP_D :
					DIO_u8_PORTD =Copy_u8_Port_Val ;
					break;
				}
			}else{
				Error_state=  DIO_u8_ERR_Port_Val;
			}
	}else{
		Error_state= DIO_u8_ERR_Port_ID;
	}
	return Error_state;
}

u8 DIO_Set_Port_dir (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_dir)
{
	u8 Error_state= DIO_u8_ERR_Inil_Val;
	if((Copy_u8_Port_ID >= MIN_Port_ID) && (Copy_u8_Port_ID <= MAX_Port_ID) ){
				if((Copy_u8_Port_dir >= MIN_Port_dir) && (Copy_u8_Port_dir <= MAX_Port_dir) ){
					switch (Copy_u8_Port_ID){
					case GROUP_A :
						DIO_u8_DDRA= Copy_u8_Port_dir;
						break;

					case GROUP_B :
						DIO_u8_DDRB= Copy_u8_Port_dir;
						break;

					case GROUP_C :
						DIO_u8_DDRC= Copy_u8_Port_dir;
						break;

					case GROUP_D :
						DIO_u8_DDRD= Copy_u8_Port_dir;
						break;
					}
				}else{
					Error_state=  DIO_u8_ERR_Port_Dir;
				}
		}else{
			Error_state= DIO_u8_ERR_Port_ID;
		}

	return Error_state;
}

u8 DIO_Get_Port_value (u8 Copy_u8_Port_ID,u8 *Copy_u8_Port_Val){
	u8 Error_state= DIO_u8_ERR_Inil_Val;
		if((Copy_u8_Port_ID >= MIN_Port_ID) && (Copy_u8_Port_ID) <= MAX_Port_ID ){
						switch (Copy_u8_Port_ID){
						case GROUP_A :
							*Copy_u8_Port_Val = DIO_u8_PINA;
							break;

						case GROUP_B :
							*Copy_u8_Port_Val = DIO_u8_PINB;
							break;

						case GROUP_C :
							*Copy_u8_Port_Val = DIO_u8_PINC;
							break;

						case GROUP_D :
							*Copy_u8_Port_Val =DIO_u8_PIND;
							break;
						}
				}else{
					Error_state= DIO_u8_ERR_Port_ID;
				}
			return Error_state;
		}






