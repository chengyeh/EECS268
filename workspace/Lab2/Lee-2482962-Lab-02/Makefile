all: Lab2 clean

Lab2: main.o Node.o LinkedList.o Test.o
	g++ -g -std=c++11 main.o Node.o LinkedList.o Test.o -o Lab2
	
main.o: main.cpp Node.h LinkedList.h
	g++ -g -std=c++11 -c main.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -c Node.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -g -std=c++11 -c LinkedList.cpp
	
Test.o: Test.cpp Test.h
	g++ -g -std=c++11 -c Test.cpp

clean:
	rm *.o
	echo clean done	