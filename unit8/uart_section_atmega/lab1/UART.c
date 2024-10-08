﻿/*
 * UART.c
 *
 * Created: 23/08/2024 11:05:17 م
 *  Author: HP
 */ 
#include "UART.h"
void UART_INIT(void){
	//Asynchronous select
	//frame
	//one stop bit
	//8-bit

	// buad rate
	UCSRA&=~(1<<U2X);
	UBRRL=51;
	
	//enable 
	UCSRB|=(1<<RXEN);
	UCSRB|=(1<<TXEN);
}

void UART_SEND(uint8_t data){
	while (!(UCSRA&(1<<UDRE)));
	UDR=data;
}

uint8_t UART_RECEIVE(void){
	while (!(UCSRA&(1<<RXC)));
	return UDR;
	
}
void UART_SEND_string(char* string)
{
	while (*string !='\0'){
		UART_SEND((uint8_t)*string);
	string++;}
	UART_SEND('#');
	
}
char* UART_RECEIVE_STRING() {
	char* rec = (char*)malloc(25 * sizeof(char)); // Dynamically allocate memory

	uint8_t i = 0;
	while (1) {
		rec[i] = UART_RECEIVE();
		if (rec[i] == '#') {
			rec[i] = '\0'; // Null-terminate the string
			break;
		}
		i++;
	}

	return rec;
}