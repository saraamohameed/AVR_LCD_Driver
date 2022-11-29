/*
 * LCD_Program.c

 *
 *  Created on: Nov 25, 2022
 *      Author: hp
 */
//8 BIT MODE

#include "BIT_CALC.h"
#include "STD_Types.h"
#include "DIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_Configration.h"
#include "LCD_Interface.h"
#include <avr/delay.h>

void LCD_void_inti()
{
	DIO_Set_Port_dir(LCD_u8_ctrl_PORT,0b11111111);
	DIO_Set_Port_dir(LCD_u8_DATA_PORT,0b11111111);

	_delay_ms(40);
	LCD_void_wirte_Command(0b00111000); //Function set (8 bit mode , 2 lines , 5x7 format).
	_delay_us(50);
	LCD_void_wirte_Command(0b00001100); //Display ON/OFF control. (Display ON , cursor ON , blinking off)
	_delay_us(50);
	LCD_void_wirte_Command(0b00000001); //display clear
	_delay_ms(2);
	LCD_void_wirte_Command(0x06); // Entry mode. (No display shift , AC increase)
	_delay_ms(1);

}

void LCD_void_wirte_Command(u8 Copy_u8_cmd)
{
	DIO_Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_RS_Pin,LCD_u8_RS_CMD);
	LCD_void_write(Copy_u8_cmd);
}

void LCD_void_wirte_data(u8 Copy_u8_data)
{
	DIO_Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_RS_Pin,LCD_u8_RS_data);
	LCD_void_write(Copy_u8_data);
}

void LCD_void_write(u8 Copy_u8_val){
	DIO_Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_RW_Pin,LCD_u8_RW_write);

	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_0,Get_Bit(Copy_u8_val,0));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_1,Get_Bit(Copy_u8_val,1));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_2,Get_Bit(Copy_u8_val,2));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_3,Get_Bit(Copy_u8_val,3));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_4,Get_Bit(Copy_u8_val,4));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_5,Get_Bit(Copy_u8_val,5));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_6,Get_Bit(Copy_u8_val,6));
	DIO_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_7,Get_Bit(Copy_u8_val,7));

	DIO_Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_ENAble_Pin,LCD_u8_enable_HIGH);
	_delay_ms(2);
	DIO_Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_ENAble_Pin,LCD_u8_Enable_LOW);
}

void LCD_void_set_DDRAM_ADD(u8 copy_DDRAM_ADD){
	//set DDRAM address
	//0b00000001
	//0b10000000
	//-----------OR
	//0b10000001
	LCD_void_wirte_Command(0b10000000|copy_DDRAM_ADD);
	}

void LCD_void_Write_String(u8 *Ptr_u8String,u8 copy_u8x_Pos,u8 copy_u8y_Pos){
	u8 Loc_u8DDRAM_ADD = copy_u8x_Pos+(copy_u8y_Pos*64);
	//x=0 y=0
	//0b10000000
	//x=0  y=1
	//0b1
	//DDRAM_ADD =x+y*64
	//DDRAM_ADD =DDRAM_ADD|0b10000000
	//set DDRAM_ADD
	while (*Ptr_u8String !='\0'){
		//start write from
		LCD_void_wirte_data(*Ptr_u8String);
		Ptr_u8String++;
		Loc_u8DDRAM_ADD++; //to know final location
		//end line 1 move to line 2
		if(Loc_u8DDRAM_ADD == 16){
			Loc_u8DDRAM_ADD = 64;
			LCD_void_set_DDRAM_ADD(Loc_u8DDRAM_ADD);
		}
		LCD_void_wirte_data(*Ptr_u8String);
		Ptr_u8String++;
		Loc_u8DDRAM_ADD++;
	}
}

void LCD_void_set_CGRAM_ADD(u8 copy_CGRAM_ADD){
	LCD_void_wirte_Command(0b01000000|copy_CGRAM_ADD);
	}
