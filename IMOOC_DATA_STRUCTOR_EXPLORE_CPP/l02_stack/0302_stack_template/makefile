OBJS=main.o Coordinate.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp MyStack.h
	g++ -c main.cpp
Coordinate.o: Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp
clean:
	rm -f test ${OBJS}