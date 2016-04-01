/*
 * File Name: LinkedList.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab2
 * Description:  Implementation of LinkedList class.
 * Created on: Sep 14, 2015
 *
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

//Initializes all the variables
LinkedList::LinkedList()
{
	m_front = nullptr;
	m_size = 0;
}

LinkedList::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

//Check if the list is empty
bool LinkedList::isEmpty() const
{
	if(m_front == nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

//Return value of m_size
int LinkedList::size() const
{
	return(m_size);
}

//Return true if the value is found in the list, otherwise return false
bool LinkedList::search(int value) const
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		Node* last = m_front;

		for(int i = 1; i <= this -> size(); i++)
		{
			if(last -> getValue() == value)
			{
					return(true);
			}
			else
			{
					last = last -> getNext();
			}

	    }
	}

	return(false);
}

//Print the elements in the list, if it's empty print the empty string
void LinkedList::printList() const
{
	if(isEmpty())
	{
		cout << "";
	}
	else
	{
		Node* temp = m_front;

		for(int i = 1; i <= this -> size(); i++)
		{
			cout << temp -> getValue() << " ";
			temp = temp -> getNext();
		}
		temp = nullptr;
		delete temp;
	}
}

//Add a new element in the front of the list
void LinkedList::addFront(int value)
{
	Node* first = nullptr;

	if(isEmpty())
	{
		m_front = new Node();
		m_front -> setValue(value);
		m_size ++;
	}
	else
	{
		first = new Node();
		first -> setValue(value);
		first -> setNext(m_front);
		m_front = first;
		first = nullptr;
		delete first;
		m_size ++;
	}

}

//Add a new element in the end of the list
void LinkedList::addBack(int value)
{
	Node* temp = nullptr;
	Node* last = nullptr;

	if(isEmpty())
	{
		m_front = new Node();
		m_front -> setValue(value);
		m_size ++;
	}
	else
	{
		last = m_front;
		while(last -> getNext() != nullptr)
		{
			last = last -> getNext();
		}
		temp = new Node;
		temp -> setValue(value);
		last -> setNext(temp);
		temp = nullptr;
		delete temp;
		m_size ++;
	}
}

//Remove an element front the back of the list
bool LinkedList::removeBack()
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		Node* last = nullptr;
		Node* secondToLast = nullptr;
		last = m_front;

		if(last -> getNext() == nullptr)
		{
			m_front = nullptr;
			delete last;
			m_size --;
			return(true);
		}

		while(last -> getNext() != nullptr)
		{
			secondToLast = last;
			last = last -> getNext();
		}
		secondToLast -> setNext(nullptr);
		delete last;
		m_size --;
		return(true);
	}
}

//Remove an element from the front of the list
bool LinkedList::removeFront()
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		Node* temp = nullptr;
		temp = m_front -> getNext();
		delete m_front;
		m_front = temp;
		temp = nullptr;
		delete temp;
		m_size --;
		return(true);
	}
}


