all: Lab09 clean

Lab09: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o
	g++ -g -std=c++11 main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o -o Lab09
	
main.o: main.cpp ArrayHelper.h ArrayHelper.hpp
	g++ -g -std=c++11 -c main.cpp
	
MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -c MazeReader.cpp
	
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -c MazeWalker.cpp
	
Position.o: Position.h Position.cpp 
	g++ -g -std=c++11 -c Position.cpp
	
Test.o: Test.h Test.cpp ArrayHelper.h ArrayHelper.hpp
	g++ -g -std=c++11 -c Test.cpp
	
clean:
	rm *.o
	echo clean done