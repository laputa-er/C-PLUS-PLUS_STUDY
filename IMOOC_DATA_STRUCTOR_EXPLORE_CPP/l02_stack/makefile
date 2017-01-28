OBJS=main.o MyStack.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
MyQueue.o: MyStack.cpp MyStack.h
	g++ -c MyStack.cpp
clean:
	rm -f test ${OBJS}