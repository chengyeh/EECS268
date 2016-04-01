/*
 * File Name: Node.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab2
 * Description: Header file of Node class. Used to set and get the value of Node and its pointer.
 * Created on: Sep 14, 2015
 *
 */

#ifndef NODE_H_
#define NODE_H_

class Node
{
	public:
	/**
	*  @pre None
	*  @post Initializes m_value to zero and m_next to nullptr
	*  @return Initialzed variables
	*/
	Node();

	/**
	*  @pre User input value
	*  @post sets m_value to val
	*  @return None
	*/
	void setValue(int val);

	/**
	*  @pre None
	*  @post None
	*  @return m_value
	*/
	int getValue() const;

	/**
	*  @pre the next Node pointer
	*  @post sets m_next to prve
	*  @return None
	*/
	void setNext(Node* prve);

	/**
	*  @pre None
	*  @post None
	*  @return m_next
	*/
	Node* getNext() const;

	private:
	int m_value;

	Node* m_next;
};





#endif /* NODE_H_ */
