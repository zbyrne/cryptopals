compile = clang++ -std=c++11

set1: challenge1.out challenge2.out challenge3.out challenge4.out challenge5.out challenge6.out
	./challenge1.out
	./challenge2.out
	./challenge3.out
	./challenge4.out
	./challenge5.out
	./challenge6.out

challenge1.out: set1.o challenge1.cc
	$(compile) -o challenge1.out challenge1.cc set1.o

challenge2.out: set1.o challenge2.cc
	$(compile) -o challenge2.out challenge2.cc set1.o

challenge3.out: set1.o challenge3.cc
	$(compile) -o challenge3.out challenge3.cc set1.o

challenge4.out: set1.o challenge4.cc
	$(compile) -o challenge4.out challenge4.cc set1.o

challenge5.out: set1.o challenge5.cc
	$(compile) -o challenge5.out challenge5.cc set1.o

challenge6.out: set1.o challenge6.cc
	$(compile) -o challenge6.out challenge6.cc set1.o

set1.o: set1.cc set1.h
	$(compile) -c set1.cc

clean:
	-rm *.out *.o

b64test.out: set1.o b64test.cc
	$(compile) -o b64test.out b64test.cc set1.o
	./b64test.out
