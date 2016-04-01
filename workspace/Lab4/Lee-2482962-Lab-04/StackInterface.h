/*
 * File Name: StackInterface.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab4
 * Description: Base class for the Stack class. Has all the methods Stack class needs.
 * Created on: Sep 28, 2015
 *
 */

#ifndef STACKINTERFACE_H_
#define STACKINTERFACE_H_

#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{
	public:
	virtual ~StackInterface() {};

	/**
	*  @pre None
	*  @post return true if the stack is empty, false otherwise
	*  @return true or false
	*/
	virtual bool isEmpty() const = 0;

	/**
	*  @pre value of some type, T
	*  @post puts a new entry at the top of the stack and increases m_size by 1
	*  @return None
	*/
	virtual void push(const T newEntry) = 0;

	/**
	*  @pre None
	*  @post top of the stack is removed and decreases m_size by 1. Throw PreconditionViolationException if the stack is empty.
	*  @return None
	*/
	virtual void pop() throw(PreconditionViolationException) = 0;

	/**
	*  @pre None
	*  @post returns the content at the top of the stack. Throw PreconditionViolationException if the stack is empty.
	*  @return the value at the top of the stack
	*/
	virtual T peek() const throw(PreconditionViolationException) = 0;

	/**
	*  @pre None
	*  @post None
	*  @return the size of the stack
	*/
	virtual int size() const = 0;

	/**
	*  @pre None
	*  @post prints the contents of the stack or prints the empty string if it is empty
	*  @return None
	*/
	virtual void print() const = 0;
};



#endif /* STACKINTERFACE_H_ */
