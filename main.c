/*
 * Timer)Driver02.c
 *
 * Created: 21/08/2020 06:23:43 م
 * Author : Ali
 */ 

#include "UART.h"
#include "DC_Motor.h"
#include "LCD.h"
#include "LED.h"

#include "Smart_Home_Cfg.h"
#define  F_CPU  16000000
#include <util/delay.h>








int main(void)
{
	
	 uint8 Uart_Data = 0 ;
	 
	 
	 // LCD Initialization
	 LCD_Init();
 LCD_GoTo(0,5);
 LCD_WriteString("Welcome");
 
 LCD_GoTo(1,3);
 LCD_WriteString("to our home");
 _delay_ms(1500);
 LCD_Clear();
 
 LCD_GoTo(0,5);
 LCD_WriteString("Smile !");
 
 
 // UART Initialization
	UART_Init();
	
	
	//DC_Motor Initialization
	DC_Motor_Init();
	DC_Motor_SetDir(0);
	DC_Motor_Stop();
	
	
	
	
	// LED Initialization
	LED0_Init();
	LED1_Init();
	LED2_Init();
	
	
			
	
	
	
	
    while (1) 
    {
		Uart_Data = UART_ReceiveByte();
		
		switch( Uart_Data)
		{

			case ROOM1_LED_ON :
			
			LED0_ON();
			
			break;

			case ROOM2_LED_ON :

			LED1_ON();

			break;

			case ROOM3_LED_ON :

			LED2_ON();

			break;

			case ROOM1_LED_OFF :

			LED0_OFF();

			break;
			
			
			case ROOM2_LED_OFF :
			
			LED1_OFF();

			break;
			
			
			case ROOM3_LED_OFF :
			
			LED2_OFF();
			
			break;
			
			case ROOM1_FAN_ON :
			DC_Motor_SetDir(CLOCK_WISE_DIR );
			DC_Motor_SetSpeed(10);
			DC_Motor_Start();
			
			break;
			
			
			case ROOM1_FAN_OFF :
			
			
			DC_Motor_Stop();
			
			break;
			
			

			default:
			break;
		}
		
		
    }
	
	
}



