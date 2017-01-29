OBJS=main.o List.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
List.o: List.cpp List.h
	g++ -c List.cpp
clean:
	rm -f test ${OBJS}