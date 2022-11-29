/*
 * main.c
 *
 *  Created on: Nov 25, 2022
 *      Author: hp
 */
#include "BIT_CALC.h"
#include "STD_Types.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include <avr/delay.h>
void main()
{
	//u8 arr[]="SARA";
   //LCD_void_Init();
	LCD_void_inti();
	/*LCD_void_set_DDRAM_ADD(64);
	LCD_void_wirte_data('S');
	LCD_void_wirte_data('A');
	LCD_void_wirte_data('R');
	LCD_void_wirte_data('A');
	//LCD_void_Write_String(arr,0,0);*/

u8 ch[]={0, 0, 1, 1, 31, 0, 4, 0};
  LCD_void_set_CGRAM_ADD(0);
		for(u8 i=0;i<8;i++)
		{
			LCD_void_wirte_data(ch[i]);
		}
	LCD_void_set_DDRAM_ADD(0);
	LCD_void_wirte_data(0);

	while(1)
	{
	}
}


