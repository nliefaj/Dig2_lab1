/*
 * display7.h
 *
 * Created: 1/23/2025 7:06:55 PM
 *  Author: njfg0
 */ 


#ifndef DISPLAY7_H_
#define DISPLAY7_H_

#include <stdint.h>
#include <avr/io.h>
//iniciar pines del display
void initDisplay(void);
//función para desplegar un número
void display(uint8_t numero);



#endif /* DISPLAY7_H_ */