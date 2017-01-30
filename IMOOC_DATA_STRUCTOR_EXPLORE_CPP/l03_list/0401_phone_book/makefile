OBJS=main.o List.o Node.o Person.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
List.o: List.cpp List.h
	g++ -c List.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
Person.o: Person.cpp Person.h
	g++ -c Person.cpp
clean:
	rm -f test ${OBJS}