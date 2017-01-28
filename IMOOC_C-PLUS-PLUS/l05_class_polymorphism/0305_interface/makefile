OBJS=main.o FighterPlane.o Plane.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Plane.o: Plane.cpp Plane.h
	g++ -c Plane.cpp
FighterPlane.o: FighterPlane.cpp FighterPlane.h Flyable.h
	g++ -c FighterPlane.cpp
clean:
	rm -f test