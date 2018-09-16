/*
 * UART.cpp
 * 
 * Author: Chris Barreiro Stewart
 * 
 */


#include "UART.h"

	//-------------------------
	//----- SETUP USART 0 -----
	//-------------------------
	//At bootup, pins 8 and 10 are already set to UART0_TXD, UART0_RXD respectively
	
UART::UART()
{
	//printf("Unable to open UART ");
	//gpioTerminate();
	// Initialize Pigpio
	gpioInitialise();
	uart0_filestream = -1;
	//OPEN THE UART
	//115200 BAUD 
	
	if(uart0_filestream = serOpen("/dev/ttyS0",9600,0) < 0)
	{
		printf("Unable to open UART ");
	}
//gpioDelay(1000*10);	
}

UART::~UART()
{
	//----- CLOSE THE UART -----
	serClose(uart0_filestream);
	gpioTerminate();
}

void UART::RX()
{
	//----- CHECK FOR ANY RX BYTES -----
	if (uart0_filestream != -1)
	{
		
		// Read up to 255 characters from the port if they are there
		rx_length = serRead(uart0_filestream, data, 1);		//Filestream, buffer to store in, number of bytes to read (max)
		
		if (rx_length < 0)
		{
			//An error occured (will occur if there are no bytes)
			printf("UART ERROR");
		}
		else if (rx_length == 0)
		{
			//No data waiting
			//printf("UART is STUPID ");
			//gpioDelay(1000*10);
		}
		else if (data[0] != 'w' )
		{
			rx_buffer[i] = data[0] ;
			i++;
			
		}
		else if (data[0] == 'w' )
		{
			//Bytes received
			//printf("%i bytes read : %s", i, rx_buffer);
			printf(rx_buffer);
			i = 0 ;
			
		}
	}

	
  
}

void UART::TX()
{
	p_tx_buffer = &tx_buffer[0];
	*p_tx_buffer++ = 'H';
	*p_tx_buffer++ = 'e';
	*p_tx_buffer++ = 'l';
	*p_tx_buffer++ = 'l';
	*p_tx_buffer++ = 'o';
	
	if (uart0_filestream != -1)
	{
		count = serWrite(uart0_filestream, &tx_buffer[0], (p_tx_buffer - &tx_buffer[0]));		//Filestream, bytes to write, number of bytes to write
		if (count < 0)
		{
			printf("UART TX error\n");
		}
	}
}

