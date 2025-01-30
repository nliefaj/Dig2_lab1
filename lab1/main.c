/*
 * laboratorio 1
 * UNIVERSIDAD DEL VALLE DE GUATEMALA
 * eLECTRÓNICA DIGITAL 2
 * AUTOR:Nathalie Fajardo/ lefaj
 * CREADO: 1/23/2025 4:51
 *esto ya funciona
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "display7/display7.h"

/*      VARIABLES            */
uint8_t conteo=0;
uint8_t jugador1=0;
uint8_t j2=0;
uint8_t pulsador=0;
uint8_t regresion=5;
uint8_t start_flag=0;
uint8_t valor_PC=0;
uint8_t valor_PB=0;
uint8_t decada[]={0b00000000,0b00000001,0b00000010,0b00000100,0b00001000,0b00001111};

uint8_t estado_j1_a=1;
uint8_t estado_j1_b=0;
uint8_t estado_j2_a=1;
uint8_t estado_j2_b=0;


ISR(PCINT1_vect){
	valor_PC=PINC;
	if (pulsador==0){
		if (valor_PC&(1<<0)){
			jugador1=0;
			j2=0;
			regresion=5;
			conteo=1;
			pulsador++;
		}	
	}else{
		pulsador=0;
	}
}
ISR(PCINT0_vect){
	valor_PB=PINB;
	estado_j1_b=(valor_PB&(1<<PB4))>>PB4;
	estado_j2_b=(valor_PB&(1<<PB5))>>PB5;
	if (pulsador==0){
		if ((estado_j1_a==1)&&(estado_j1_b==0)){
			if (start_flag==1){
				jugador1++;
				pulsador++;
			}
		}
		if ((estado_j2_a==1)&&(estado_j2_b==0)){
			if (start_flag==1){
				j2++;
				pulsador++;
			}
		}
		estado_j1_a=estado_j1_b;
		estado_j2_a=estado_j2_b;
		
		}else{
		pulsador=0;
	}
}


void setup(void){
	cli();
	DDRB=0b00001111;
	DDRD=0b11111111;
	PORTD=0x00;
	DDRC=0b00011110;
	PCICR=0;
	PCICR |=(1<<PCIE1)|(1<<PCIE0);
	PCMSK1|=(1<<PCINT8);
	PCMSK0|=(1<<PCINT4)|(1<<PCINT5);
	UCSR0B=0;
	sei();
}

void ganador(void){
	if (jugador1==5){
		PORTB=decada[5];
		display(1);
		start_flag=0;
		
	}
	if (j2==5){
		PORTC=decada[5]<<1;
		display(2);
		start_flag=0;
	}
	else{
		PORTB=decada[jugador1];
		PORTC=decada[j2]<<1;
	}
}


int main(void)
{
    /* Replace with your application code */
	setup();
	initDisplay();
	PORTD=0x00;
	PORTB=0x00;
    while (1) 
    {
		if (conteo==1){
			display(regresion);
			if (regresion==0){
				conteo=0;
				regresion=5;
				start_flag=1;
			}else{
				regresion--;
			}
			_delay_ms(1000);
		}
		if (start_flag==1){
			ganador();
		}
		
    }
}

