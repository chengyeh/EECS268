all: Lab01 clean

Lab01: main.o Dice.o Pokemon.o Colosseum.o
	g++ -g -o Lab01 main.o Dice.o Pokemon.o Colosseum.o
	
main.o: main.cpp Dice.h Pokemon.h Colosseum.h
	g++ -c -g main.cpp
	
Colosseum.o: Colosseum.h Colosseum.cpp
	g++ -c -g Colosseum.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -c -g Pokemon.cpp
	
Dice.o: Dice.h Dice.cpp
	g++ -c -g Dice.cpp
	
clean: 
	rm *.o
	echo clean done
	