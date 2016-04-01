/*
 * File Name: Node.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab4
 * Description: Header file of Node class. Used to set and get the value of a Node and its pointers.
 * Created on: Sep 28, 2015
 *
 */

#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node
{
	private:
	T m_value;
	Node<T>* m_next;

	public:
	/**
	*  @pre None
	*  @post Initializes m_value to T() and m_next to nullptr
	*  @return Initialzed variables
	*/
	Node();

	/**
	*  @pre User input value
	*  @post sets m_value to val
	*  @return None
	*/
	void setValue(T val);

	/**
	*  @pre None
	*  @post None
	*  @return m_value
	*/
	T getValue() const;

	/**
	*  @pre the next Node pointer
	*  @post sets m_next to the next pointer
	*  @return None
	*/
	void setNext(Node<T>* next);

	/**
	*  @pre None
	*  @post None
	*  @return m_next
	*/
	Node<T>* getNext() const;
};

#include "Node.hpp"



#endif /* NODE_H_ */
