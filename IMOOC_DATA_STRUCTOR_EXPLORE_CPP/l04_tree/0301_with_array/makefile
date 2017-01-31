OBJS=main.o Tree.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp
clean:
	rm -f test ${OBJS}