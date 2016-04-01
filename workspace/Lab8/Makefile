all: Lab8 clean

Lab8: main.o Test.o
	g++ -g -std=c++11 main.o Test.o -o Lab8

main.o: main.cpp Node.h Node.hpp BSTI.h BinarySearchTree.h BinarySearchTree.hpp
	g++ -g -std=c++11 -c main.cpp
	
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp
	
clean:
	rm *.o
	echo clean done