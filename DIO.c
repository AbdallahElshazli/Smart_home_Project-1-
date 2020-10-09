/*
 * DIO.c
 *
 * Created: 10/4/2020 1:14:07 PM
 *  Author: ALLaH
 */ 
#include "DIO.h"




void DIO_SetPortDir(uint8 Port , uint8 Dir)
{


	switch(Port)
	{

		case DIO_PORTA :

		DDRA = Dir;

		break;

		case DIO_PORTB :

		DDRB = Dir;

		break;

		case DIO_PORTC :

		DDRC = Dir;

		break;

		case DIO_PORTD :

		DDRD = Dir;

		break;

		default:
		break;
	}

}








void DIO_SetPinDir(uint8 Port ,uint8 Pin , uint8 Dir)
{



	switch (Dir)
	{


		case DIO_PIN_OUTPUT :


		switch (Port)
		{
			case DIO_PORTA :

			SET_BIT(DDRA,Pin);

			break;

			case DIO_PORTB :

			SET_BIT(DDRB,Pin);

			break;

			case DIO_PORTC :

			SET_BIT(DDRC,Pin);

			break;

			case DIO_PORTD :

			SET_BIT(DDRD,Pin);

			break;

			default:
			break;
		}

		break;

		case DIO_PIN_INPUT :


		switch (Port)
		{
			case DIO_PORTA :

			CLR_BIT(DDRA,Pin);

			break;

			case DIO_PORTB :

			CLR_BIT(DDRB,Pin);

			break;

			case DIO_PORTC :

			CLR_BIT(DDRC,Pin);

			break;

			case DIO_PORTD :

			CLR_BIT(DDRD,Pin);

			break;

			default:
			break;
		}

		break;


		default :
		break;
	}



}







void DIO_WritePort(uint8 Port , uint8 Val)
{

	switch (Port)
	{
		case DIO_PORTA :

		PORTA = Val;

		break;

		case DIO_PORTB :

		PORTB = Val;

		break;

		case DIO_PORTC :

		PORTB = Val;

		break;

		case DIO_PORTD :

		PORTD = Val;

		break;

		default:
		break;
	}

}









void DIO_WritePin(uint8 Port ,uint8 Pin, uint8 Val)
{
	switch (Val)
	{


		case DIO_PIN_HIGH :


		switch (Port)
		{
			case DIO_PORTA :

			SET_BIT(PORTA,Pin);

			break;

			case DIO_PORTB :

			SET_BIT(PORTB,Pin);

			break;

			case DIO_PORTC :

			SET_BIT(PORTC,Pin);

			break;

			case DIO_PORTD :

			SET_BIT(PORTD,Pin);

			break;

			default:
			break;
		}

		break;

		case DIO_PIN_LOW :


		switch (Port)
		{
			case DIO_PORTA :

			CLR_BIT(PORTA,Pin);

			break;

			case DIO_PORTB :

			CLR_BIT(PORTB,Pin);

			break;

			case DIO_PORTC :

			CLR_BIT(PORTC,Pin);

			break;

			case DIO_PORTD :

			CLR_BIT(PORTD,Pin);

			break;

			default:
			break;
		}

		break;


		default :
		break;
	}
}










void DIO_ReadPort(uint8 Port , uint8* Val)
{
	switch (Port)
	{
		case DIO_PORTA :

		*Val = PINA;

		break;

		case DIO_PORTB :

		*Val = PINB;

		break;

		case DIO_PORTC :

		*Val = PINC;

		break;

		case DIO_PORTD :

		*Val = PIND;

		break;

		default:
		break;
	}

}








void DIO_ReadPin (uint8 Port ,uint8 Pin, uint8* Val)
{
	switch (Port)
	{
		case DIO_PORTA :

		*Val =  GET_BIT(PINA,Pin);

		break;

		case DIO_PORTB :

		*Val = GET_BIT(PINB,Pin);

		break;

		case DIO_PORTC :

		*Val = GET_BIT(PINC,Pin);

		break;

		case DIO_PORTD :

		*Val = GET_BIT(PIND,Pin);

		break;

		default:
		break;
	}

}



void DIO_TogglePin(uint8 port , uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA :
		Toggle_BIT(PORTA , pin);
		break;
		
		case DIO_PORTB :
		Toggle_BIT(PORTB , pin);
		break;
		
		case DIO_PORTC :
		Toggle_BIT(PORTC , pin);
		break;
		
		case DIO_PORTD :
		Toggle_BIT(PORTD , pin);
		break;
		
		default:
		break;
	}
}