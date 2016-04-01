all: prog clean

prog: main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o Test.o
	g++ -g -std=c++11 main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o Test.o -o prog

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c main.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c NumberFileDriver.cpp 
	
NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c NumberFileGenerator.cpp 

SortDriver.o: SortDriver.h SortDriver.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c SortDriver.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp
	
clean:
	rm *.o
	echo clean done