

#pragma once

#include <stdio.h>
#include <pigpio.h>

using namespace std;

class SPI
{
	private:
	
	char spi0_filestream;
	int rx_length;
	char rx_buffer[256];
	
	public:
	
	SPI();
	~SPI();


    //  RX
    void RX();
};
