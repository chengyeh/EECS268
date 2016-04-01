/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: This is the main class that all classes are called from.
 * Created on: Nov 13, 2015
 *
 */

#include <iostream>

#include "MazeReader.h"
#include "MazeWalker.h"
#include "ArrayHelper.h"
#include "Test.h"

int main(int argc, char** argv)
{
	if(argc == 2)
	{
		std::string mode = argv[1];

		try
		{
			if(mode == "-test")
			{
				Test test;
				test.runTests();
			}
			else
			{
				throw 1;
			}
		}
		catch(int e)
		{
			std::cout << "\nValid command line options:\n\n"
					  << "./Lab09 -dfs filename\n"
					  << "./Lab09 -bfs filename\n"
					  << "./Lab09 -test\n" << std::endl;
		}
	}
	if(argc == 3)
	{
		std::string mode = argv[1];
		std::string fileName = argv[2];

		try
		{
			if(mode != "-dfs" && mode != "-bfs")
			{
				throw 1;
			}
			else
			{
				if(mode == "-dfs")
				{
					Search s = Search::DFS;

					try
					{
						MazeReader* reader = new MazeReader(fileName);
						MazeWalker* walker = new MazeWalker(reader -> getMaze(), reader -> getStartRow(), reader -> getStartCol(), reader -> getRows(), reader -> getCols(), s);
						walker -> walkMaze();
						ArrayHelper<int>::print2DArray(walker -> getVisited(), walker -> getVisitedRows(), walker -> getVisitedCols(), "\t");
						delete reader;
						delete walker;
					}
					catch(MazeCreationException& e)
					{
						std::cout << e.what() << std::endl;
					}
				}
				if(mode == "-bfs")
				{
					Search s = Search::BFS;

					try
					{
						MazeReader* reader = new MazeReader(fileName);
						MazeWalker* walker = new MazeWalker(reader -> getMaze(), reader -> getStartRow(), reader -> getStartCol(), reader -> getRows(), reader -> getCols(), s);
						walker -> walkMaze();
						ArrayHelper<int>::print2DArray(walker -> getVisited(), walker -> getVisitedRows(), walker -> getVisitedCols(), "\t");
						delete reader;
						delete walker;
					}
					catch(MazeCreationException& e)
					{
						std::cout << e.what() << std::endl;
					}
				}
			}
		}
		catch(int e)
		{
			std::cout << "\nValid command line options:\n\n"
					  << "./Lab09 -dfs filename\n"
					  << "./Lab09 -bfs filename\n" << std::endl;
		}

	}
	else if(argc < 2 || argc > 3)
	{
		std::cout << "\nValid command line options:\n\n"
				  << "./Lab09 -dfs filename\n"
				  << "./Lab09 -bfs filename\n"
				  << "./Lab09 -test\n" << std::endl;
	}

	return(0);
}


