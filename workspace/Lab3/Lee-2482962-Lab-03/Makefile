all: Lab3 clean

Lab3: main.o Test.o
	g++ -g -std=c++11 main.o Test.o -o Lab3 
	
main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c main.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp
	
clean:
	rm *.o
	echo clean done
	