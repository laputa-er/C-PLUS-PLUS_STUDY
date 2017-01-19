LIBS=-lm
OBJS=MazeMap.o maze.o MazePerson.o
CFLAGS=-Wall
SO=test.exe

main:${OBJS}
	g++ -o ${SO} ${OBJS}
MazeMap.o:MazeMap.cpp MazeMap.h Public.h
	g++ -c MazeMap.cpp
MazePerson.o:MazePerson.cpp MazePerson.h
	g++ -c MazePerson.cpp
maze.o: Maze.cpp MazeMap.cpp
	g++ -c maze.cpp
clean:
	rm -f ${OBJS} ${SO}