set1: challenge1 challenge2
	./challenge1
	./challenge2

challenge1: set1.o challenge1.cc
	g++ -o challenge1 challenge1.cc set1.o

challenge2: set1.o challenge2.cc
	g++ -o challenge2 challenge2.cc set1.o

set1.o: set1.cc set1.h
	g++ -c set1.cc

clean:
	-rm challenge1 challenge2 *.o