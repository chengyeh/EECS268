/*
 * File Name: NumberFileDriver.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Header file of NumberFileDriver class. This class handles validating of command line arguments and displaying a help menus should the user provide invalid arguments.
 * Created on: Oct 29, 2015
 *
 */

#ifndef NUMBERFILEDRIVER_H_
#define NUMBERFILEDRIVER_H_

#include <iostream>

#include "NumberFileGenerator.h"

class NumberFileDriver
{
	public:
        /**
	*  @pre arguments is a valid 2-D array and the arguments contained within are valid
	*  @post if the arguments are valid, a number file is created following those specifications.Otherwise, the help menu is printed and no files are created
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
	*  @pre none
	*  @post prints a menus to help the user use the NumberFileGenerator
	*  @return true is the option passed in is valid. Valid options are: "-a", "-d", "-r", and "-s"
	*/
	static bool isValidOption(std::string option);
};



#endif /* NUMBERFILEDRIVER_H_ */
