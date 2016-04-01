/*
 * File Name: NumberFileGenerator.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Implementation of NumberFileGenerator class.
 * Created on: Oct 29, 2015
 *
 */

#include "NumberFileGenerator.h"

void NumberFileGenerator::ascending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);

	if(myOutputFile.good() && amount > 0)
	{
		myOutputFile << amount << std::endl;
		for(int i = 1; i < amount; i++)
		{
			myOutputFile << i << std::endl;
		}
		myOutputFile.close();
	}
}


void NumberFileGenerator::descending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);

	if(myOutputFile.good() && amount > 0)
	{
		myOutputFile << amount << std::endl;
		for(int i = 1; i < amount; i++)
		{
			myOutputFile << amount - i << std::endl;
		}
		myOutputFile.close();
	}
}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max);
	std::ofstream myOutputFile(fileName);
    int randomNumber;

	if(myOutputFile.good() && amount > 0)
	{
		myOutputFile << amount << std::endl;
		for(int i = 1; i < amount; i++)
		{
			randomNumber = distribution(generator);
			myOutputFile << randomNumber << std::endl;
		}
		myOutputFile.close();
	}
}


void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
	std::ofstream myOutputFile(fileName);

	if(myOutputFile.good() && amount > 0)
	{
		myOutputFile << amount << std::endl;
		for(int i = 1; i < amount; i++)
		{
			myOutputFile << value << std::endl;
		}
		myOutputFile.close();
	}

}
