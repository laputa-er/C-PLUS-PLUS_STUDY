OBJS=main.o Tank.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Tank.o: Tank.cpp Tank.h
	g++ -c Tank.cpp
clean:
	rm -f test ${OBJS}