/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: This is the main class that all classes are called from.
 * Created on: Nov 07, 2015
 *
 */

#include "NumberFileDriver.h"
#include "SortDriver.h"
#include "Test.h"

int main(int argc, char** argv)
{

	Test test(std::cout);

	if(argc >= 2)
	{
                std::string mode = argv[1];
		if(mode == "-create")
		{
			NumberFileDriver::run(argc, argv);
		}
		else if(mode == "-sort")
		{
			SortDriver::run(argc, argv);
		}
		else if(mode == "-test")
		{
			test.runTests();
		}
		else
		{
			NumberFileDriver::printHelpMenu();
			SortDriver::printHelpMenu();
		}
	}
	else
	{
		NumberFileDriver::printHelpMenu();
		SortDriver::printHelpMenu();
	}

	return(0);
}


