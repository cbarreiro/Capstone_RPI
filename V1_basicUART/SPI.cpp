/*
 * SPI.cpp
 * 
 * Author: Chris Barreiro Stewart
 * 
 */


#include "SPI.h"

	//-------------------------
	//----- SETUP SPI -----
	// MISO - 35
	// MOSI - 38
	// SCLK - 40
	// CE0 - 24
	// CE1 - 26
	//-------------------------
 //respectively
	SPI::SPI()
	{
		// Initialize Pigpio
		gpioInitialise();
		spi0_filestream = -1;
		
		//OPEN THE SPI
		//baud: 32K-125M (values above 30M are unlikely to work)
		
		if(spi0_filestream = spiOpen(0,57600,0) < 0)
		{
			printf("Unable to open SPI ");
		}
	gpioDelay(1000*10);	
	}
	
	SPI::~SPI()
	{
		//----- CLOSE THE SPI -----
		spiClose(spi0_filestream);
		gpioTerminate();
	}

void SPI::RX()
{
	//----- CHECK FOR ANY RX BYTES -----
	if (uart0_filestream != -1)
	{
		// Read up to 255 characters from the port if they are there
		rx_length = spiRead(spi0_filestream, rx_buffer, 255);		//Filestream, buffer to store in, number of bytes to read (max)
		
		if (rx_length < 0)
		{
			//An error occured (will occur if there are no bytes)
			printf("SPI ERROR");
		}
		else if (rx_length == 0)
		{
			//No data waiting
			printf("No data ");
			gpioDelay(1000*10);
		}
		else
		{
			//Bytes received
			rx_buffer[rx_length] = '\0';
			printf("%i bytes read : %s\n", rx_length, rx_buffer);
			
		}
	}

	
  
}



