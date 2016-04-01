all: Lab5 clean

Lab5: main.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o PreconditionViolationException.o -o Lab5

main.o: main.cpp FarmAnimal.h
	g++ -g -std=c++11 -c main.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp StackInterface.h Stack.h Stack.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c AnimalPen.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -c FarmAnimal.cpp
	
Cow.o: Cow.h Cow.cpp FarmAnimal.h
	g++ -g -std=c++11 -c Cow.cpp

Chicken.o: Chicken.h Chicken.cpp FarmAnimal.h
	g++ -g -std=c++11 -c Chicken.cpp

CyberChicken.o: CyberChicken.h CyberChicken.cpp Chicken.h
	g++ -g -std=c++11 -c CyberChicken.cpp
	
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp
	
clean:
	rm *.o
	echo clean done