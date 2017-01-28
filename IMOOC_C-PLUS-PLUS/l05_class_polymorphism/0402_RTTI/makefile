OBJS=main.o Bird.o Plane.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Plane.o: Plane.cpp Plane.h Flyable.h
	g++ -c Plane.cpp
Bird.o: Bird.cpp Bird.h Flyable.h
	g++ -c Bird.cpp
clean:
	rm -f test