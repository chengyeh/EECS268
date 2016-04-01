/*
 * File Name: SortDriver.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Implementation of SortDriver class.
 * Created on: Oct 30, 2015
 *
 */

#include "SortDriver.h"

void SortDriver::run(int argc, char** argv)
{
	if(argc == 5)
	{
		std::string sort = argv[2];
		std::string inFileName = argv[3];

		if(areParametersValid(sort, inFileName))
		{
			std::string outFileName = argv[4];

			std::ifstream myInputFile(inFileName);
			int size = getFileCount(myInputFile);

			int* array = createArray(myInputFile, size);
			myInputFile.close();
			int* copy = new int[size];

			double sortTime;
			std::ofstream myOutputFile(outFileName);
			std::cout << "Calculating sort timing information...\n"
					  << "Calculations finshed. Results stored in " << outFileName << ".\n"
					  << "Exiting..." << std::endl;
			if(sort == "-bubble")
			{
                                copyArray(array, copy, size);
                                sortTime = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, copy, size);
				myOutputFile << "bubble " << size << " " << sortTime;
                                delete[] copy;
                                copy = nullptr;
			}
			else if(sort == "-selection")
			{
                                copyArray(array, copy, size);
                                sortTime = Sorts<int>::sortTimer(Sorts<int>::selectionSort, copy, size);
				myOutputFile << "selection " << size << " " << sortTime;
                                delete[] copy;
                                copy = nullptr;
			}
			else if(sort == "-insertion")
			{
                                copyArray(array, copy, size);
                                sortTime = Sorts<int>::sortTimer(Sorts<int>::insertionSort, copy, size);
				myOutputFile << "insertion " << size << " " << sortTime;
                                delete[] copy;
                                copy = nullptr;
			}
			else if(sort == "-quick")
			{
                                copyArray(array, copy, size);
                                sortTime = Sorts<int>::sortTimer(Sorts<int>::quickSort, copy, size);
				myOutputFile << "quick " << size << " " << sortTime;
                                delete[] copy;
                                copy = nullptr;
			}
			else if(sort == "-quick3")
			{
                                copyArray(array, copy, size);
                                sortTime = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, copy, size);
				myOutputFile << "quick3 " << size << " " << sortTime;
                                delete[] copy;
                                copy = nullptr;
			}
			else if(sort == "-merge")
			{
                                copyArray(array, copy, size);
                                sortTime = Sorts<int>::sortTimer(Sorts<int>::mergeSort, copy, size);
				myOutputFile << "merge " << size << " " << sortTime;
                                delete[] copy;
                                copy = nullptr;
			}
			else if(sort == "-all")
			{
                            copyArray(array, copy, size);
                            sortTime = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, copy, size);
			    myOutputFile << "bubble " << size << " " << sortTime << std::endl;
                            delete[] copy;
                            copy = nullptr;

			    copyArray(copy, array, size);
                            sortTime = Sorts<int>::sortTimer(Sorts<int>::selectionSort, copy, size);
			    myOutputFile << "selection " << size << " " << sortTime << std::endl;
                            delete[] copy;
                            copy = nullptr;

			    copyArray(array, copy, size);
                            sortTime = Sorts<int>::sortTimer(Sorts<int>::insertionSort, copy, size);
			    myOutputFile << "insertion " << size << " " << sortTime << std::endl;
                            delete[] copy;
                            copy = nullptr;

			    copyArray(copy, array, size);
                            sortTime = Sorts<int>::sortTimer(Sorts<int>::mergeSort, copy, size);
			    myOutputFile << "merge " << size << " " << sortTime << std::endl;
                            delete[] copy;
                            copy = nullptr;

			    copyArray(array, copy, size);
                            sortTime = Sorts<int>::sortTimer(Sorts<int>::quickSort, copy, size);
			    myOutputFile << "quick " << size << " " << sortTime << std::endl;
                            delete[] copy;
                            copy = nullptr;

			    copyArray(copy, array, size);
                            sortTime = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, copy, size);
			    myOutputFile << "quick3 " << size << " " << sortTime;
                            delete[] copy;
                            copy = nullptr;
			}
			myOutputFile.close();
                        delete[] array;
                        delete[] copy;
			array = nullptr;
                        copy = nullptr;

		}
	}
	else
	{
		printHelpMenu();
	}
}

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}

bool SortDriver::isFileAccessible(std::string fileName)
{
	std::ifstream myInputFile(fileName);

	if(myInputFile.good())
	{
		return(true);
	}
	else
	{
		return(false);
	}
}


bool SortDriver::isSortValid(std::string sortParameter)
{
	if(sortParameter == "-bubble" || sortParameter == "-selection" || sortParameter == "-insertion" || sortParameter == "-quick" || sortParameter == "-quick3" || sortParameter == "-merge" || sortParameter == "-all")
	{
		return(true);
	}
	else
	{
		return(false);
	}
}


bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if(isSortValid(sortName) && isFileAccessible(inputFileName))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
	std::string str;
	inputFile >> str;
	return(std::stoi(str));
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
	std::string str;
	int* array = new int[size];
	for(int i = 0; i < size; i++)
	{
		inputFile >> str;
		array[i] = std::stoi(str);
	}

	return(array);
}


void SortDriver::copyArray(int original[], int copy[], int size)
{
	for(int i = 0; i < size; i++)
	{
		copy[i] = original[i];
	}
}


