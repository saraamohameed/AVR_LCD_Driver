/*
 * LCD_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: hp
 */


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



void LCD_void_write(u8 Copy_u8_val);
void LCD_void_wirte_data(u8 Copy_u8_data);
void LCD_void_wirte_Command(u8 Copy_u8_cmd);
void LCD_void_inti(void);
void LCD_void_set_CGRAM_ADD(u8 copy_CGRAM_ADD);
void LCD_void_set_DDRAM_ADD(u8 copy_DDRAM_ADD);
void LCD_void_Write_String(u8 *Ptr_u8String,u8 copy_u8x_Pos,u8 copy_u8y_Pos);

#endif /* LCD_INTERFACE_H_ */


