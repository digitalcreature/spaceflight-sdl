TARGET=spaceflight.exe

all:
	g++ -std=gnu++11 -g -Wall -o $(TARGET) src/*.cpp -I inc/

clean:
	rm -f $(TARGET)
