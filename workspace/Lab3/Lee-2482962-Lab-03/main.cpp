/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab3
 * Description: This is the main class. It is where we test DoubleLinkedList class and give the user a set of options to interact with DoubleLinkedList.
 * Created on: Sep 21, 2015
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "DoubleLinkedList.h"
#include "Test.h"

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}

int main()
{
	//Declare class instances and variables
	DoubleLinkedList<int> list;
	Test myTester(std::cout);
	bool exit = false;
	int userChoice = 0;
	int userInput = 0;
	int insertValue = 0;

	while(exit == false)
	{
		printMenu();
		cin >> userChoice;
		cout << "You chose: " << userChoice << endl;

		if(userChoice < 1 || userChoice > 10)
		{
			cout << "Invalid choice." << endl;
		}
		//Call pushFront method
		if(userChoice == 1)
		{
			cout << "Give a value. ";
			cin >> userInput;
			list.pushFront(userInput);
			cout << "\n" << userInput << " added to front of list." << endl;
		}
		//Call pushBack method
		if(userChoice == 2)
		{
			cout << "Give a value. ";
			cin >> userInput;
			list.pushBack(userInput);
			cout << "\n" << userInput << " added to back of list." << endl;
		}
		//Call insertBehind method
		if(userChoice == 3)
		{
			try
			{
				cout << "Give a value to insert. ";
				cin >> insertValue;
				cout << "Pick a value to insert behind. ";
				cin >> userInput;
				cout << "\nAttempting to insert " << insertValue << " behind " << userInput << endl;
				list.insertBehind(userInput, insertValue);
				cout << "\n" << insertValue << " inserted behind " << userInput << endl;
			}
			catch  (std::runtime_error& e)
			{
				cout << "The value given isn't in the list. Insert failed." << endl;
			}

		}
		//Call insertAhead method
		if(userChoice == 4)
		{
			try
			{
				cout << "Give a value to insert. ";
				cin >> insertValue;
				cout << "Pick a value to insert ahead of. ";
				cin >> userInput;
				cout << "\nAttempting to insert " << insertValue << " ahead of " << userInput << endl;
				list.insertAhead(userInput, insertValue);
				cout << "\n" << insertValue << " inserted ahead of " << userInput << endl;
			}
			catch  (std::runtime_error& e)
			{
				cout << "The value given isn't in the list. Insert failed." << endl;
			}

		}
		//Call removeFront method
		if(userChoice == 5)
		{
			if(list.removeFront())
			{
				cout << "\nFront of list removed." << endl;
			}
			else
			{
				cout << "\nList empty" << endl;
			}
		}
		//Call removeBack method
		if(userChoice == 6)
		{
			if(list.removeBack())
			{
				cout << "\nBack of list removed." << endl;
			}
			else
			{
				cout << "\nList empty" << endl;
			}
		}
		//Call remove method
		if(userChoice == 7)
		{
			cout << "Give a value to remove. ";
			cin >> userInput;
			cout << "You gave " << userInput << endl;
			if(list.remove(userInput))
			{
				cout << "\n" << userInput << " removed from list." << endl;
			}
			else
			{
				cout << "\n" <<  userInput << " could not be removed from list." << endl;
			}
		}
		//Call printList method
		if(userChoice == 8)
		{
			list.printList();
		}
		//Exit the loop
		if(userChoice == 9)
		{
			exit = true;
		}
		//Call runTests method
		if(userChoice == 10)
		{
			 myTester.runTests();
		}
	}

	cout << "\nProgram ending..." << endl;
	return(0);
}
