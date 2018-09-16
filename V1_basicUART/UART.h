

#pragma once

#include <stdio.h>
#include <pigpio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

class UART
{
	private:
	
	char uart0_filestream;
	
	//----- RX -----	
	int rx_length;
	char rx_buffer[256];
	char data[1] ;
	int i = 0;
	
	
	//----- TX -----
	char tx_buffer[20];
	char *p_tx_buffer;
	int count;
	
	public:
	
	UART();
	~UART();


    //  RX & TX Functions
    void RX();
	void TX();
};
