OBJS=main.o Exception.o IndexException.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Exception.o: Exception.cpp Exception.h
	g++ -c Exception.cpp
IndexException.o: IndexException.cpp IndexException.h
	g++ -c IndexException.cpp
clean:
	rm -f test ${OBJS}