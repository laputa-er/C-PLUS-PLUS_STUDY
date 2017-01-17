LIBS=-lm
OBJS=main.o Coordinate.o Line.o
CFLAGS=-Wall
SO=test
main: ${OBJS}
	g++ -o ${SO} ${OBJS}
main.o: main.cpp Line.cpp
	g++ -c main.cpp ${CFLAGS}
Line.o:Line.cpp Line.h
	g++ -c Line.cpp
Coordinate.o:Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp
clean:
	rm -f ${OBJS} ${SO}

