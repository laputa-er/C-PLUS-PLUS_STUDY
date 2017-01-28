OBJS=main.o Array.o
main: ${OBJS}
	g++ -o test ${OBJS}
main.o: main.cpp
	g++ -c main.cpp
Array.o: Array.cpp Array.h
	g++ -c Array.cpp
clean:
	rm -f ${OBJS} test