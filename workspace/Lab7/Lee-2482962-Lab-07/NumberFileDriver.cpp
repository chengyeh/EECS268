/*
 * File Name: NumberFileDriver.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Implementation of NumberFileDriver class.
 * Created on: Oct 29, 2015
 *
 */

#include "NumberFileDriver.h"

void NumberFileDriver::run(int argc, char** argv)
{
	std::string order = argv[2];

	if(isValidOption(order))
	{
		if (order == "-a")
		{
			if (argc == 5)
			{
				NumberFileGenerator::ascending(argv[3], std::stoi(argv[4]));
			}
			else
			{
				printHelpMenu();
			}

		}
		else if(order == "-d")
		{
			if (argc == 5)
			{
				NumberFileGenerator::descending(argv[3], std::stoi(argv[4]));
			}
			else
			{
				printHelpMenu();
			}
		}
		else if(order == "-s")
		{
			if (argc == 6)
			{
				NumberFileGenerator::singleValue(argv[3], std::stoi(argv[4]), std::stoi(argv[5]));
			}
			else
			{
				printHelpMenu();
			}
		}
		else if(order == "-r")
		{
			if(argc == 7)
			{
				NumberFileGenerator::random(argv[3], std::stoi(argv[4]), std::stoi(argv[5]), std::stoi(argv[6]));
			}
			else
			{
				printHelpMenu();
			}
		}
	}
}

void NumberFileDriver::printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

bool NumberFileDriver::isValidOption(std::string option)
{
	if(option == "-a" || "-d" || "-r" || "-s")
	{
		return(true);
	}
	else
	{
		printHelpMenu();
		return(false);
	}
}

