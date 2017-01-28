LIBS=-lm
OBJS=main.o Coordinate.o
CFLAGS=-Wall
SO=test
main: ${OBJS}
	g++ -o ${SO} ${OBJS}
main.o: main.cpp Coordinate.cpp
	g++ -c main.cpp ${CFLAGS}
Coordinate.o:Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp
clean:
	rm -f ${OBJS} ${SO}

