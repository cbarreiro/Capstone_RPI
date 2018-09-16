# The compiler to use is for C++
CC=g++
# The compiler options are (all warnings)
CFLAGS=-Wall -std=c++11 -c
# The linker options are (all warnings)
LDFLAGS=-Wall -std=c++11 -lpigpio -lrt -lpthread 


all: HeatMap

HeatMap: Heat_Map.o UART.o  
	$(CC) $(LDFLAGS) Heat_Map.o UART.o -o HeatMap

Heat_Map.o: Heat_Map.cpp
	$(CC) $(CFLAGS) Heat_Map.cpp
	
UART.o: UART.cpp
	$(CC) $(CFLAGS) UART.cpp



clean:
	rm -f *o HeatMap





