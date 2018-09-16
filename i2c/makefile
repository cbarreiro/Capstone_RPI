# The compiler to use is for C++
CC=g++
# The compiler options are (all warnings)
CFLAGS=-Wall -std=c++11 -c
# The linker options are (all warnings)
LDFLAGS=-Wall -std=c++11 -lpigpio -lrt -lpthread 


all: HeatMap

HeatMap: i2c.o 
	$(CC) $(LDFLAGS) i2c.o -o HeatMap


i2c.o: i2c.cpp
	$(CC) $(CFLAGS) i2c.cpp


clean:
	rm -f *o HeatMap





