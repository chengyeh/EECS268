/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab6
 * Description: This is the main class. It is where we test Sorts class and give the user a set of options to interact with Sorts.
 * Created on: Oct 23, 2015
 *
 */

#include <iostream>
#include <chrono>
#include "Sorts.h"
#include "Test.h"

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
            << "5) Run Tests\n"
			<< "Enter choice: ";
}

void printArray(int arr[], int size)
{
	std::cout << "[";
	for(int i = 0; i < size; i++)
	{
		if(i < size -1)
		{
			std::cout << arr[i] << ",";
		}
		else
		{
			std::cout << arr[i] << "]" << std::endl;
		}

	}
}

int main()
{
	Sorts<int> s;
	Test myTester(std::cout);
	int userChoice;
	int size;
	int low;
	int high;
	char print;
	char exit;
	double time = 0.0;
	bool quit = false;

	while(quit == false)
	{
		printMenu();
		std::cin >> userChoice;
		if(userChoice == 1)
		{
			std::cout << "Input a size for the random array: ";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: ";
			std::cin >> low;
			std::cout << "Input an upper bound on the range of random numbers: ";
			std::cin >> high;

			int* arr = s.createTestArray(size, low, high);
			do
			{
				std::cout << "Do you want to print the unsorted array? (y/n): ";
				std::cin >> print;
			}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

			if(print == 'Y' || print == 'y')
			{
				std::cout << "Here is the unsorted array:" << std::endl;
				printArray(arr, size);
			}

			std::cout << "\nSorting with bubble sort..." << std::endl;
			s.bubbleSort(arr,size);
			do
			{
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin >> print;
			}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

			if(print == 'Y' || print == 'y')
			{
				std::cout << "Here is the sorted array:" << std::endl;
				printArray(arr, size);
			}

			time = s.sortTimer(s.bubbleSort, arr, size);
			std::cout << "\n" << size << " numbers were sorted in " << std::fixed << time << " seconds." << std::endl;
			delete arr;
			arr = nullptr;
		}
		if(userChoice == 2)
		{
			std::cout << "Input a size for the random array: ";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: ";
			std::cin >> low;
			std::cout << "Input an upper bound on the range of random numbers: ";
			std::cin >> high;

			int* arr = s.createTestArray(size, low, high);
			do
			{
				std::cout << "Do you want to print the unsorted array? (y/n): ";
				std::cin >> print;
			}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

			if(print == 'Y' || print == 'y')
			{
				std::cout << "Here is the unsorted array:" << std::endl;
				printArray(arr, size);
			}

			std::cout << "\nSorting with insertion sort..." << std::endl;
			s.insertionSort(arr, size);
			do
			{
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin >> print;
			}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

			if(print == 'Y' || print == 'y')
			{
				std::cout << "Here is the sorted array:" << std::endl;
				printArray(arr, size);
			}

			time = s.sortTimer(s.insertionSort, arr, size);
			std::cout << "\n" << size << " numbers were sorted in " << std::fixed << time << " seconds." << std::endl;
			delete arr;
			arr = nullptr;
		}
		if(userChoice == 3)
		{
			std::cout << "Input a size for the random array: ";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: ";
			std::cin >> low;
			std::cout << "Input an upper bound on the range of random numbers: ";
			std::cin >> high;

			int* arr = s.createTestArray(size, low, high);
			do
			{
				std::cout << "Do you want to print the unsorted array? (y/n): ";
				std::cin >> print;
			}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

			if(print == 'Y' || print == 'y')
			{
				std::cout << "Here is the unsorted array:" << std::endl;
				printArray(arr, size);
			}

			std::cout << "\nSorting with selection sort..." << std::endl;
			s.selectionSort(arr, size);
			do
			{
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin >> print;
			}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

			if(print == 'Y' || print == 'y')
			{
				std::cout << "Here is the sorted array:" << std::endl;
				printArray(arr, size);
			}

			time = s.sortTimer(s.selectionSort, arr, size);
			std::cout << "\n" << size << " numbers were sorted in " << std::fixed << time << " seconds." << std::endl;
			delete arr;
			arr = nullptr;
		}
		if(userChoice == 4)
		{
			std::cout << "Input a size for the random array: ";
		    std::cin >> size;
		    std::cout << "Input a lower bound on the range of random numbers: ";
		    std::cin >> low;
		    std::cout << "Input an upper bound on the range of random numbers: ";
		    std::cin >> high;

		    int* arr = s.createTestArray(size, low, high);
		    do
		    {
		    	std::cout << "Do you want to print the unsorted array? (y/n): ";
		    	std::cin >> print;
	    	}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

		    if(print == 'Y' || print == 'y')
	  	    {
			    std::cout << "Here is the unsorted array:" << std::endl;
			    printArray(arr, size);
	    	}

	    	std::cout << "\nSorting with bogo sort..." << std::endl;
	    	s.bogoSort(arr,size);
	    	do
	    	{
		    	std::cout << "Do you want to print the sorted array? (y/n): ";
			    std::cin >> print;
    		}while(print != 'Y' && print != 'y' && print != 'N' && print != 'n');

	    	if(print == 'Y' || print == 'y')
		    {
			    std::cout << "Here is the sorted array:" << std::endl;
	    		printArray(arr, size);
	    	}

	    	time = s.sortTimer(s.bogoSort, arr, size);
	    	std::cout << "\n" << size << " numbers were sorted in " << std::fixed << time << " seconds." << std::endl;
    		delete arr;
	    	arr = nullptr;
		}
		if(userChoice == 5)
		{
			myTester.runTests();
		}

		do
		{
			std::cout << "\nDo you want to quit? (y/n): ";
			std::cin >> exit;
		}while(exit != 'Y' && exit != 'y' && exit != 'N' && exit != 'n');

		if(exit == 'Y' || exit == 'y')
		{
			quit = true;
		}
	}
	return(0);
}

