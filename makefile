CC=g++
CFLAGS=-g -std=c++11 -Wall
LFLAGS=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
SRC=$(wildcard ./src/*.cpp)

all: $(SRC)
	$(CC) -o ./bin/main $^ $(CFLAGS) $(LFLAGS)

clean:
	rm ./bin/main
