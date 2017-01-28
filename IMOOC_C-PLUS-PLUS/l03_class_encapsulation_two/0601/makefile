LIBS=-lm
OBJS=MazeMap.o maze.o MazePerson.o MyMazeMap.o MyMazePerson.o
CFLAGS=-Wall
SO=test.exe
INPUT=UTF-8
OUTPUT=GBK
main:${OBJS}
	g++ -o ${SO} ${OBJS};
	rm -f ${OBJS};
MazeMap.o:MazeMap.cpp MazeMap.h Public.h
	g++ -c MazeMap.cpp -finput-charset=${INPUT} -fexec-charset=${OUTPUT}
MazePerson.o:MazePerson.cpp MazePerson.h
	g++ -c MazePerson.cpp -finput-charset=${INPUT} -fexec-charset=${OUTPUT}
MyMazeMap.o:MyMazeMap.cpp MyMazeMap.h
	g++ -c MyMazeMap.cpp -finput-charset=${INPUT} -fexec-charset=${OUTPUT}
MyMazePerson.o:MyMazePerson.cpp MyMazePerson.h
	g++ -c MyMazePerson.cpp -finput-charset=${INPUT} -fexec-charset=${OUTPUT}
maze.o: Maze.cpp MazeMap.cpp
	g++ -c maze.cpp -finput-charset=${INPUT} -fexec-charset=${OUTPUT}
clean:
	rm -f ${SO}