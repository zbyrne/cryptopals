compile = clang++ -std=c++11

set1: challenge1 challenge2 challenge3 challenge4 challenge5 challenge6
	./challenge1
	./challenge2
	./challenge3
	./challenge4
	./challenge5
	./challenge6

challenge1: set1.o challenge1.cc
	$(compile) -o challenge1 challenge1.cc set1.o

challenge2: set1.o challenge2.cc
	$(compile) -o challenge2 challenge2.cc set1.o

challenge3: set1.o challenge3.cc
	$(compile) -o challenge3 challenge3.cc set1.o

challenge4: set1.o challenge4.cc
	$(compile) -o challenge4 challenge4.cc set1.o

challenge5: set1.o challenge5.cc
	$(compile) -o challenge5 challenge5.cc set1.o

challenge6: set1.o challenge6.cc
	$(compile) -o challenge6 challenge6.cc set1.o

set1.o: set1.cc set1.h
	$(compile) -c set1.cc

clean:
	-rm challenge1 challenge2 challenge3 challenge4 challenge5 *.o