all: Lab6 clean

Lab6: main.o Test.o
	g++ -g -std=c++11 main.o Test.o -o Lab6

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c main.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp
	
clean:
	rm *.o
	echo clean done