/*
 * File Name: DoubleLinkedList.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab3
 * Description: Header file of DoubleLinkedList class. Used to execute all the options in the menu.
 * Created on: Sep 25, 2015
 *
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include "Node.h"

template <typename T>
class DoubleLinkedList
{
	private:
	Node<T>* m_front;

	Node<T>* m_back;

	int m_size;

	public:
	/**
	*  @pre None
	*  @post Initializes m_front and m_back to nullptr and m_size to 0
	*  @return Initialzed variables
	*/
	DoubleLinkedList();

	/**
	*  @pre the list is not empty
	*  @post deallocates all nodes
	*  @return None
	*/
	~DoubleLinkedList();

	/**
	*  @pre None
	*  @post return true if the list is empty, false otherwise
	*  @return true or false
	*/
	bool isEmpty() const;

	/**
	*  @pre None
	*  @post None
	*  @return the number of elements in the list
	*/
	int size() const;

	/**
	*  @pre value of some type, T
	*  @post puts a node at the front of the list and increases m_size by 1
	*  @return None
	*/
	void pushFront(T value);

	/**
	*  @pre value of some type, T
	*  @post puts a node at the end of the list and increases m_size by 1
	*  @return None
	*/
	void pushBack(T value);

	/**
	*  @pre None
	*  @post one element is removed from the back of the list and decreases m_size by 1
	*  @return true if the back element was removed, false if the list is empty.
	*/
	bool removeBack();

	/**
	*  @pre None
	*  @post one element is removed from the front of the list and decreases m_size by 1
	*  @return true if the front element was removed, false if the list is empty
	*/
	bool removeFront();

	/**
	*  @pre value of some type, T
	*  @post deletes the node containing the passed value and decreases m_size by 1
	*  @return true if the node was removed, false otherwise
	*/
	bool remove(T value);

	/**
	*  @pre two values of some type, T
	*  @post if listValue is in the list a node is created, newValue is placed ahead of it and m_size increases by 1. If listValue is not found in the list, throw runtime_error
	*  @return None
	*/
	void insertAhead(T listValue, T newValue) throw (std::runtime_error);

	/**
	*  @pre two values of some type, T
	*  @post if listValue is in the list a node is created, newValue is placed behind it and m_size increases by 1. If listValue is not found in the list, throw runtime_error
	*  @return None
	*/
	void insertBehind(T listValue, T newValue) throw (std::runtime_error);

	/**
	*  @pre value of some type, T
	*  @post returns a pointer to the first node in the list (from front to back) that contains the value or nullptr if not found
	*  @return q pointer or nullptr
	*/
	Node<T>* find(T value) const;

	/**
	*  @pre None
	*  @post prints all values in the list, if it's empty print empty string
	*  @return None
	*/
	void printList() const;
};

#include "DoubleLinkedList.hpp"

#endif /* DOUBLELINKEDLIST_H_ */
