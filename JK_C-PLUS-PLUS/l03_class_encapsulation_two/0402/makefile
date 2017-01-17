OBJS=main.o Coordinate.o
main: ${OBJS}
	g++ -o test ${OBJS}
main.o: main.cpp
	g++ -c main.cpp
Array.o: Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp
clean:
	rm -f ${OBJS} test