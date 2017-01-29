OBJS=main.o List.o Coordinate.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
List.o: List.cpp List.h
	g++ -c List.cpp
Coordinate.o: Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp
clean:
	rm -f test ${OBJS}