OBJS=main.o CMap.o Node.o Edge.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
CMap.o: CMap.cpp CMap.h
	g++ -c CMap.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
Edge.o: Edge.cpp Edge.h
	g++ -c Edge.cpp
clean:
	rm -f test ${OBJS}