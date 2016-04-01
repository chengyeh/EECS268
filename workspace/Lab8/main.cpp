/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab8
 * Description: This is the main class that all classes are called from.
 * Created on: Nov 06, 2015
 *
 */

#include <iostream>
#include <random>
#include <ctime>
#include <climits>

#include "BinarySearchTree.h"
#include "Test.h"


void printMenu()
{
	std::cout << "Input a selection.\n"
			  << "1) Add more values to original tree\n"
			  << "2) Copy the original tree\n"
			  << "3) Delete the original tree (one time only)\n"
			  << "4) Print original tree\n"
			  << "5) Print copy\n"
			  << "6) Search original tree\n"
			  << "7) Search copy\n"
			  << "8) Exit\n"
			  << "9) Run tests\n"
			  << "Your choice: ";
}

int main(int argc, char** argv)
{

	BSTI<int>* bstPtr = new BinarySearchTree<int>();
	BSTI<int>* myClone = new BinarySearchTree<int>();
	Test test;
	std::vector<int> vec;
	int randomNumber = 0;
	int input = 0;
	int numberAdded = 0;
	bool end = false;
	int userChoice = 0;
	int printType = 0;
	int value = 0;
	int flag = 1;
	int search = 0;
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);

	if(argc == 2)
	{
		std::string mode = argv[1];

		if(mode == "-test")
		{
			test.runTests();
		}
		else
		{
			input = std::stoi(argv[1]);

			while(input > numberAdded)
			{
				randomNumber = distribution(generator);
				vec.push_back(randomNumber);
				numberAdded++;
			}
		}

		for(std::size_t i = 0; i < vec.size(); i++)
		bstPtr -> add(vec[i]);
	}
	else if(argc == 3)
	{
		std::string mode = argv[1];

		if(mode == "-nodes")
		{
			input = std::stoi(argv[2]);

			while(input > numberAdded)
			{
				randomNumber = distribution(generator);
				vec.push_back(randomNumber);
				numberAdded++;
			}
		}

		for(std::size_t i = 0; i < vec.size(); i++)
		bstPtr -> add(vec[i]);
	}
	else if(argc > 3)
	{
		std::cout << "Invalid Number of Arguments." << std::endl;
	}

	while(end == false)
	{
		printMenu();
		std::cin >> userChoice;

		if(userChoice == 1)
		{
			std::cout << "Input Value to add to Tree: ";
			std::cin >> value;
			bstPtr -> add(value);
			std::cout << "successfully added.\n\n" << std::endl;
		}
		else if(userChoice == 2)
		{
			myClone = bstPtr -> clone();
			std::cout << "\n" << std::endl;
		}
		else if(userChoice == 3)
		{
			if(flag == 1 && !(bstPtr -> isEmpty()))
			{
				delete bstPtr;
				flag = 0;
				bstPtr = new BinarySearchTree<int>();
				std::cout<<"Original tree deleted.\n\n" << std::endl;;
			}
			else if(flag == 0)
			{
				std::cout << "Original tree has already been deleted. Cannot delete.\n\n" << std::endl;
			}
			else
			{
				std::cout << "Original tree doesn't exist. Cannot delete.\n\n" << std::endl;
			}
		}
		else if(userChoice == 4)
		{
			if(bstPtr -> isEmpty())
			{
				std::cout << "OriginalTree doesn't exist. Cannot print.\n\n" << std::endl;
			}
			else
			{
				std::cout << "\nPlease choose an order you like to print:\n"
						  << "1) Pre Order\n"
						  << "2) In Order\n"
						  << "3) Post Order\n"
						  << "Your Choice: ";
				std::cin >> printType;
				std::cout << "\n";

				if(printType == 1)
				{
					bstPtr -> printTree(PRE_ORDER);
					std::cout << "\n\n";
				}
				else if(printType == 2)
				{
					bstPtr -> printTree(IN_ORDER);
					std::cout << "\n\n";
				}
				else if(printType == 3)
				{
					bstPtr -> printTree(POST_ORDER);
					std::cout << "\n\n";
				}

			}
		}
		else if(userChoice == 5)
		{
			if(myClone -> isEmpty())
			{
				std::cout << "Tree doesn't exist. Cannot print.\n\n" << std::endl;
			}
			else
			{
				std::cout << "\nPlease choose an order you like to print:\n"
						  << "1) Pre Order\n"
						  << "2) In Order\n"
						  << "3) Post Order\n"
						  << "Your Choice: ";
				std::cin >> printType;
				std::cout << "\n";

				if(printType == 1)
				{
					myClone->printTree(PRE_ORDER);
					std::cout << "\n\n";
				}
				else if(printType == 2)
				{
					myClone->printTree(IN_ORDER);
					std::cout << "\n\n";
				}
				else if(printType == 3)
				{
					myClone->printTree(POST_ORDER);
					std::cout << "\n\n";
				}
			}
		}
		else if(userChoice == 6)
		{
			std::cout << "Enter Value to Search for: ";
			std::cin >> search;
			std::cout << "Searching for " << search << " in the original tree...\n\n";

			if(bstPtr -> search(search))
			{
				std::cout << "The value " << search << " is found in the tree.\n\n";
			}
			else
			{
				std::cout << "The value " << search << " is not found in the tree.\n\n";
			}
		}
		else if(userChoice == 7)
		{
			std::cout << "Enter Value to Search for: ";
			std::cin >> search;
			std::cout << "Searching for " << search << " in the tree...\n\n";

			if(myClone->search(search))
			{
				std::cout << "The value " << search << " is found in the tree.\n\n";
			}
			else
			{
				std::cout << "The value " << search << " is not found in the tree.\n\n";
			}
		}
		else if(userChoice == 8)
		{
			end = true;
		}
		else if(userChoice == 9)
		{
			test.runTests();
		}
		else
		{
			std::cout << "Invalid choice.\n\n";
		}
	}

	delete bstPtr;
	delete myClone;
	bstPtr = nullptr;
	myClone = nullptr;

	std::cout << "Exiting Program...";

	return 0;
}
