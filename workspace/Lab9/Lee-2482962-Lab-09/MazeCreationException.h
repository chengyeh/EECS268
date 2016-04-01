/*
 * File Name: MazeCreationException.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Header file of MazeCreationException class. It inherits from std::runtime_error.
 * Created on: Nov 13, 2015
 *
 */

#ifndef MAZECREATIONEXCEPTION_H_
#define MAZECREATIONEXCEPTION_H_

#include <stdexcept>

class MazeCreationException : public std::runtime_error
{
public:

	/**
	* @pre Message
    * @post Creates an exception with the message
    * @return None
    */
    MazeCreationException(const char* message);
};



#endif /* MAZECREATIONEXCEPTION_H_ */
