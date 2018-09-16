/*
 * Heat_Map.cpp
 * 
 * Author: Chris Barreiro Stewart
 * 
 * 
 */


#include <time.h>
#include <unistd.h>
#include <iostream>

#include "UART.h"
// #include "SPI.h"

using namespace std;

int main(int argc, char **argv)
{
	UART uart;
	//SPI	 spi
	while (true)
	{
	
	uart.RX();
	//spi.TX();	
	}

	return 0;
}

