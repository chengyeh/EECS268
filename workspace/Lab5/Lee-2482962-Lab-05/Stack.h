/*
 * File Name: Stack.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Header file of Stack class. Used to execute all the options in the menu.
 * Created on: Oct 16, 2015
 *
 */

#ifndef STACK_H_
#define STACK_H_

#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"

template <typename T>
class Stack : public StackInterface<T>
{
	private:
	Node<T>* m_top;
	int m_size;

	public:
	/**
	*  @pre None
	*  @post Initializes m_top to nullptr and m_size to 0
	*  @return Initialzed variables
	*/
	Stack();

	/**
	*  @pre the list is not empty
	*  @post deallocates all nodes
	*  @return None
	*/
	~Stack();

	/**
	*  @pre None
	*  @post return true if the stack is empty, false otherwise
	*  @return true or false
	*/
	bool isEmpty() const;

	/**
	*  @pre value of some type, T
	*  @post puts a new entry at the top of the stack and increases m_size by 1
	*  @return None
	*/
	void push(const T newEntry);

	/**
	*  @pre None
	*  @post top of the stack is removed and decreases m_size by 1. Throw PreconditionViolationException if the stack is empty.
	*  @return None
	*/
	void pop() throw(PreconditionViolationException);

	/**
	*  @pre None
	*  @post returns the content at the top of the stack. Throw PreconditionViolationException if the stack is empty.
	*  @return the value at the top of the stack
	*/
	T peek() const throw(PreconditionViolationException);

	/**
	*  @pre None
	*  @post None
	*  @return the size of the stack
	*/
	int size() const;

	/**
	*  @pre None
	*  @post prints the contents of the stack or prints the empty string if it is empty
	*  @return None
	*/
	void print() const;
};


#include "Stack.hpp"

#endif /* STACK_H_ */
