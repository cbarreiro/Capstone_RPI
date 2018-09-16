/*
 * Heat_Map.cpp
 * 
 * Author: Chris Barreiro Stewart
 * 
 * 
 */

 // SCL - gpio 18
 // SDA - gpio 19
 //100kps 

#include <pigpio.h>
#include <iostream>
using namespace std;

int main(){
    bsc_xfer_t xfer;
    gpioInitialise();
    xfer.control = (0x0A<<16) | 0x305; // Set I2C slave Address to 0x0A
    int status = bscXfer(&xfer);
    if (status >= 0)
    {
        xfer.rxCnt = 0;
        while(1){
			int status = bscXfer(&xfer);
            if (xfer.rxCnt > 0){
                cout << xfer.rxBuf;
				memset( xfer.rxBuf, '\0', sizeof(char)*BSC_FIFO_SIZE );
            }
       }    
    }

    return 1;
} 