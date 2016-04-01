/*
 * File Name: NumberFileGenerator.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Header file of NumberFileGenerator class. This class creates files with a numbers, specifically ints, in them. At the top of every file will be the count of how many numbers are stored in the file.
 * Created on: Oct 29, 2015 
 * 
 */


#ifndef NUMBERFILEGENERATOR_H_
#define NUMBERFILEGENERATOR_H_

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>

class NumberFileGenerator
{
	public:
	/**
	*  @pre fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with the amount of number is ascending order. The amount of numbers in the file is the first entry in the file
	*  @return none
	*/
	static void ascending(std::string fileName, int amount);

	/**
	*  @pre fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with the amount of number is descending order. The amount of numbers in the file is the first entry in the file
	*  @return none
	*/
	static void descending(std::string fileName, int amount);

	/**
	*  @pre fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with the specifed amount of numbers. All number are random and fall between min and max (inclusively). The amount of numbers in the file is the first entry in the file
	*  @return none
	*/
	static void random(std::string fileName, int amount, int min, int max);

	/**
	*  @pre fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with a single number, specified by value, amount of times. The amount of numbers in the file is the first entry in the file
	*  @return none
	*/
	static void singleValue(std::string fileName, int amount, int value);

};



#endif /* NUMBERFILEGENERATOR_H_ */
