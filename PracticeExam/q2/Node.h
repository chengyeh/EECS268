/**
*	@file Node.h
*	@author John Gibbons
*	@date 2014.02.02
*	Updated 2015.11.11
*/

#ifndef NODE_H
#define NODE_H

template <typename T> 
class Node
{
	public:
	/**
	*   @pre none
	*   @post Node is created with the value, t, stored inside
	*   @return an empty stack
	*/
	Node(T value);

	/**
	*   @pre prev is a valid pointer
	*   @post m_previous is set to prev
	*   @return none
	*/
	void setNext(Node<T>* next);

	/**
	*   @pre none
	*   @post none
	*   @return pointer to another Node or nullptr
	*/
	Node<T>* getNext() const;


	/**
	*   @pre val is a valid T
	*   @post m_value is set to val
	*   @return none
	*/
	void setValue(T value);


	/**
	*   @pre none
	*   @post none
	*   @return m_value
	*/
	T getValue() const;

	private:
	Node<T>* m_next;
	T m_value;	

};

#include "Node.hpp"

#endif
