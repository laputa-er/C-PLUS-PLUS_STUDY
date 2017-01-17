LIBS=-lm
OBJS=MazeMap.o maze.o
CFLAGS=-Wall
SO=test

main:${OBJS}
	g++ -o ${SO} ${OBJS}
MazeMap.o:MazeMap.cpp MazeMap.h Public.h
	g++ -c MazeMap.cpp
maze.o: Maze.cpp MazeMap.cpp
	g++ -c maze.cpp
clean:
	rm -f ${OBJS} ${SO}