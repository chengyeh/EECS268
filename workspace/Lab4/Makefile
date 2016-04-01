all: Lab4 clean

Lab4: main.o Test.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o Test.o PreconditionViolationException.o -o Lab4

main.o: main.cpp StackInterface.h Stack.h Stack.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c main.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp
	
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp
	
clean:
	rm *.o
	echo clean done