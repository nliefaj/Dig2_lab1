/*
 * display7.c
 *
 * Created: 1/23/2025 7:08:03 PM
 *  Author: njfg0
 */ 
#include "display7.h"

/*    VARIABLES   */
//const uint8_t display7[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};


//iniciar pines del display
void initDisplay(void){
	//PROGRAMAR SALIDAS DEL DISPLAY
	DDRD=0b11111111;
}
//función para desplegar un número
void display(uint8_t numero){
	switch (numero){
		case 0:
			PORTD=0x3F;
		break;
		case 1:
			PORTD=0x06;	
		break;
		case 2:
			PORTD=0x5B;	
		break;
		case 3:
			PORTD=0x4F;	
		break;
		case 4:
			PORTD=0x66;	
		break;
		case 5:
			PORTD=0x6D;	
		break;
		case 6:
			PORTD=0x7D;	
		break;
		case 7:
			PORTD=0x07;	
		break;
		case 8:
			PORTD=0x7F;	
		break;
		case 9:
			PORTD=0x6F;	
		break;
		
	}
	
}