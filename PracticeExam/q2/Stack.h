/** 	@file Stack.h
*	@author John Gibbons
*	@date 2014.02.02
*       Update: 2014.09.10
*		-Throwing of std::runtime_error added to pop() and peek()
*/


#ifndef Stack_H
#define Stack_H

#include <stdexcept>
#include "Node.h"

template <typename T> 
class Stack
{	
	public:

	/** @pre none
	*   @post creates an empty stack capable of storing Node<T>
	*   @return an empty stack
	*/
	Stack();

	/** @pre none
	*   @post deletes the entire stack
	*/
	~Stack();

	/**
	*   @pre Type T is overloaded for <<
	*   @post The stack is printed to the console
	*   @return none
	*/
	void printStack() const;

	/**
	*   @pre The type T works with the < operator
	*   @post none
	*   @return the largest value in the stack
	*   @throws An exception if the stack is empty when called, otherwise returns the maximum value in the stack
	*/
	T findMax() const throw (std::runtime_error);

	/** @pre none
	*   @post none
	*   @return returns true if size == 0, false otherwise
	*/
	bool isEmpty() const;

	/** @pre value is a valid T
	*   @post the value is put into a Node and put at the top of the stack
	*/
	void push(T value);


	/** @pre the stack is not empty
	*   @post none
	*   @return value, T, from top of stack. 
	*   @throws std::runtime_error when a peek is performed on an empty stack
	*/
	T peek() const throw (std::runtime_error);

	/** @pre none
	*   @post The stack is empty or the top of the stack is the value given
	*   @return none
	*/
	void popUntil(T value);

	/** @pre none
	*   @post none
	*   @return returns the value of size
	*/
	int size() const;
	
	T pop();
	private:
	/** @pre the stack is not empty
	*   @post the top of the stack is removed and its value returned
	*   @return the value, T, from the top of the stack
	*/


	Node<T>* m_top;
	int m_size;	
};

#include "Stack.hpp"

#endif

