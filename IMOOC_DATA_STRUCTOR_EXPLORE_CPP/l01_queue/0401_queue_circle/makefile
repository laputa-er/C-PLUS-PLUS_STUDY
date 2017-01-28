OBJS=main.o MyQueue.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
MyQueue.o: MyQueue.cpp MyQueue.h
	g++ -c MyQueue.cpp
clean:
	rm -f test ${OBJS}