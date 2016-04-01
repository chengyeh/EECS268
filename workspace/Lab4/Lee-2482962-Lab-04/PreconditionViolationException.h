/*
 * File Name: PreconditionViolationException.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab4
 * Description: Header file of PreconditionViolationException class. It inherits from std::runtime_error.
 * Created on: Sep 28, 2015
 *
 */

#ifndef PRECONDITIONVIOLATIONEXCEPTION_H_
#define PRECONDITIONVIOLATIONEXCEPTION_H_

#include <stdexcept>


class PreconditionViolationException : public std::runtime_error
{
	public:
	/**
	*  @pre message
	*  @post calls the constructor of std::runtime_error and pass it the message
	*  @return None
	*/
	PreconditionViolationException(const char* msg);
};


#endif /* PRECONDITIONVIOLATIONEXCEPTION_H_ */
