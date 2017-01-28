OBJS=main.o Time.o Match.o
PARA=-W c++11-extensions
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Time.o: Time.cpp Time.h
	g++ -c Time.cpp
Match.o: Match.cpp Match.h
	g++ -c Match.cpp
clean:
	rm -f test ${OBJS}