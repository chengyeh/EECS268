/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab2
 * Description: The main class. It is where we test LinkedList class and give the user a set of options to interact with LinkedList.
 * Created on: Sep 14, 2015
 *
 */

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Test.h"

using namespace std;

void printMenu()
{
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "8) Run tests\n"
			<< "Enter your choice: ";
}

int main()
{
	//Declare class instances and variables
	LinkedList list;
	Test myTester(std::cout);
	bool exit = false;
	int userChoice = 0;
	int userInput = 0;

	while(exit == false)
	{
		printMenu();
		cin >> userChoice;
		cout << "You chose: " << userChoice << endl;

		if(userChoice < 1 || userChoice > 8)
		{
			cout << "Invalid choice." << endl;
		}
		//Call addFront method
		if(userChoice == 1)
		{
			cout << "Input a value to add: ";
			cin >> userInput;
			list.addFront(userInput);
			cout << "Adding " << userInput << " to the list" << endl;
		}
		//Call addBack method
		if(userChoice == 2)
		{
			cout << "Input a value to add: ";
			cin >> userInput;
			list.addBack(userInput);
			cout << "Adding " << userInput << " to the list" << endl;
		}
		//Call removeFront method
		if(userChoice == 3)
		{
			cout << "Attempting removal from front of list." << endl;
			if(list.removeFront())
			{
				cout << "Removal successful." << endl;
			}
			else
			{
				cout << "There are no values to remove." << endl;
			}
		}
		//Call removeBack method
		if(userChoice == 4)
		{
			cout << "Attempting removal from back of list." << endl;
			if(list.removeBack())
			{
				cout << "Removal successful." << endl;
			}
			else
			{
				cout << "There are no values to remove." << endl;
			}
		}
		//Call printList method
		if(userChoice == 5)
		{
			cout << "Printng list:" << endl;
			list.printList();
		}
		//Call search method
		if(userChoice == 6)
		{
			cout << "Enter a value to search for: ";
			cin >> userInput;
			cout << "Searching for " << userInput << "..." << endl;

			if(list.search(userInput))
			{
				cout << userInput << " is in the list." << endl;
			}
			else
			{
				cout << userInput << " is not in the list." << endl;
			}
		}
		//Exit the loop
		if(userChoice == 7)
		{
			exit = true;
		}
		//Call runTests method
		if(userChoice == 8)
		{
			 myTester.runTests();
		}
	}

	cout << "Exiting..." << endl;
	return(0);

}

