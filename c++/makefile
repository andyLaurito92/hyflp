conways: conways.o tablero.o
	g++ -g -o conways conways.o tablero.o

conways.o: conways.cpp
	g++ -g -c conways.cpp

tablero.o: tablero.cpp tablero.h
	g++ -g -c tablero.cpp


clean: 
	rm conways *.o
