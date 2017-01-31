OBJS=main.o Tree.o Node.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
clean:
	rm -f test ${OBJS}