/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab4
 * Description: This is the main class. It is where we test Stack class and give the user a set of options to interact with Stack.
 * Created on: Sep 28, 2015
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "StackInterface.h"
#include "Stack.h"
#include "Test.h"

using namespace std;

void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Add to stack 1\n"
			<< "2) See what is at the top of stack\n"
			<< "3) Print all stack\n"
			<< "4) Pop stack\n"
			<< "5) Quit\n"
 			<< "6) Run Tests\n"
			<< "Enter choice: ";
}

int main()
{
	StackInterface<int>* siPtr = new Stack<int>();
	Test myTester(std::cout);
	bool exit = false;
	int userChoice = 0;
	int value = 0;

	while(exit == false)
	{
		printMenu();
		cin >> userChoice;
		cout << "You chose: " << userChoice << endl;

		if(userChoice < 1 || userChoice > 6)
		{
			cout << "Invalid choice." << endl;
		}
		//Call push method
		if(userChoice == 1)
		{
			cout << "What is going in stack 1?: ";
			cin >> value;
			siPtr -> push(value);
			cout << value << " successfully added to stack 1" << endl;
		}
		//Call peek method
		if(userChoice == 2)
		{
			try
			{
				cout << siPtr -> peek() << " is at the top of stack 1" << endl;
			}
			catch(std::exception& e)
			{
				cout << "Exception: Peek attempted on empty stack" << endl;
			}

		}
		//Call print method
		if(userChoice == 3)
		{
			siPtr -> print();
		}
		//Call pop method
		if(userChoice == 4)
		{
			try
			{
				int topValue = siPtr -> peek();
				siPtr -> pop();
				cout << topValue << " removed from stack 1" << endl;
			}
			catch(std::exception& e)
			{
				cout << "Exception: Pop attempted on empty stack" << endl;
			}
		}
		//End the program
		if(userChoice == 5)
		{
			exit = true;
		}
		//Call runTests method
		if(userChoice == 6)
		{
			 myTester.runTests();
		}
	}

	delete siPtr;
	siPtr = nullptr;
	cout << "Program ending" << endl;

	return(0);
}


