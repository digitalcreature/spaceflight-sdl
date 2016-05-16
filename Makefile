TARGET=spaceflight.exe
LIB=-l mingw32 -L lib/ -l SDL2 -L SDL2main
INC=-I inc/ -I /usr/include/
all:
	g++ -std=gnu++11 -g -Wall -o $(TARGET) src/*.cpp $(INC) $(LIB)

clean:
	rm -f $(TARGET)
