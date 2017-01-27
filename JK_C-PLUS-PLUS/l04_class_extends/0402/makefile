OBJS=main.o Soldier.o Person.o
main: ${OBJS}
	g++ -o test ${OBJS};
	rm ${OBJS};
main.o: main.cpp
	g++ -c main.cpp
Soldier.o: Soldier.cpp Soldier.h
	g++ -c Soldier.cpp
Person.o: Person.cpp Person.h
	g++ -c Person.cpp
clean:
	rm -f test