OBJS=main.o Worker.o Person.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Worker.o: Worker.cpp Worker.h
	g++ -c Worker.cpp
Person.o: Person.cpp Person.h
	g++ -c Person.cpp
clean:
	rm -f test