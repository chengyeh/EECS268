/*
 * File Name: LinkedList.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab2
 * Description: Header file of LinkedList class. Used to execute all the options in the menu.
 * Created on: Sep 14, 2015
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"



class LinkedList
{
	public:
	/**
	*  @pre None
	*  @post Initializes m_front to nullptr and m_size to 0
	*  @return Initialzed variables
	*/
	LinkedList();

	/**
	*  @pre the list is not empty
	*  @post deletes all nodes in the list
	*  @return None
	*/
	~LinkedList();

	/**
	*  @pre None
	*  @post return true if the list is empty, false otherwise
	*  @return true if the list is empty
	*/
	bool isEmpty() const;

	/**
	*  @pre None
	*  @post None
	*  @return the number of elements in the list
	*/
	int  size() const;

	/**
	*  @pre value for search
	*  @post return true if value is found in the list, false otherwise
	*  @return true if the value is found
	*/
	bool search(int value) const;

	/**
	*  @pre None
	*  @post print all values in the list, if it's empty print empty string
	*  @return None
	*/
	void printList() const;

	/**
	*  @pre value to add
	*  @post add a new element to the end of the list
	*  @return None
	*/
	void addBack(int value);

	/**
	*  @pre value to add
	*  @post add a new element to the front of the list
	*  @return None
	*/
	void addFront(int value);

	/**
	*  @pre None
	*  @post one element is removed from the back of the list
	*  @return true if the back element was removed, false if the list is empty
	*/
	bool removeBack();

	/**
	*  @pre None
	*  @post one element is removed from the front of the list
	*  @return true if the front element was removed, false if the list is empty
	*/
	bool removeFront();

	private:
	Node* m_front;

	int m_size;

};



#endif /* LINKEDLIST_H_ */
