/*
 * File Name: SortDriver.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Header file of SortDriver class. 
 * Created on: Oct 30, 2015
 *
 */

#ifndef SORTDRIVER_H_
#define SORTDRIVER_H_

#include <iostream>
#include <fstream>

#include "Sorts.h"

class SortDriver
{
	public:
        /**
	*  @pre arguments is a valid 2-D array and the arguments contained within are valid
	*  @post A file is created containing the timing information of the chosen sort(s) on the supplied file
	*  @return none
	*/
	static void run(int argc, char** argv);

        /**
	*  @pre none
	*  @post print help menu
	*  @return none
	*/
	static void printHelpMenu();

	private:
        /**
	*  @pre the input file was created by a NumberFileGenerator
	*  @post  return true if the file exists, false otherwise
	*  @return true if the file exists, false otherwise
	*/
	static bool isFileAccessible(std::string fileName);

        /**
	*  @pre none
	*  @post none
	*  @return true if the sort parameter matches a valid one
	*/
	static bool isSortValid(std::string sortParameter);

        /**
	*  @pre none
	*  @post none
	*  @return Ttrue is the file specified by inputFileName exists and the sort parameter is valid, false otherwise
	*/
	static bool areParametersValid(std::string sortName, std::string inputFileName);

        /**
	*  @pre the input file was created with the Number File Generator
	*  @post the first line of the file is read in, containing the count
	*  @return how many numbers are in the file
	*/
	static int getFileCount(std::ifstream& inputFile);

        /**
	*  @pre the input file was created with the Number File Generator, the size was read in, and that size if correct
	*  @post  the remainder of input file numbers are read in. File is NOT closed
	*  @return  a pointer to a new array containing the values from the input file
	*/
	static int* createArray(std::ifstream& inputFile, int size);

        /**
	*  @pre original and copy are valid arrays of the correct size
	*  @post  all values from original are copied into copy
	*  @return none
	*/
	static void copyArray(int original[], int copy[], int size);

};


#endif /* SORTDRIVER_H_ */
