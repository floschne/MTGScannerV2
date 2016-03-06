CC=g++
CFLAGS=-g -std=c++11 -Wall
LFLAGS=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
SRC=$(wildcard *.cpp)

all: $(SRC)
	$(CC) -o main $^ $(CFLAGS) $(LFLAGS)

clean:
	rm main
