/*
 * File Name: DoubleLinkedList.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab3
 * Description:  Implementation of DoubleLinkedList class.
 * Created on: Sep 25, 2015
 *
 */

#include <iostream>
using namespace std;

//Initializes all the variables
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

//Check if the list is empty
template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

//Return value of m_size
template <typename T>
int DoubleLinkedList<T>::size() const
{
	return(m_size);
}

//Add a new element in the front of the list
template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	if(isEmpty())
	{
		m_front = new Node<T>();
		m_front -> setValue(value);
		m_back = m_front;
		m_size ++;
	}
	else
	{
		Node<T>* first = new Node<T>();
		first -> setValue(value);
		first -> setNext(m_front);
		m_front -> setPrev(first);
		m_front = first;
		first = nullptr;
		delete first;
		m_size ++;
	}
}

//Add a new element in the end of the list
template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	if(isEmpty())
	{
		m_front = new Node<T>();
		m_front -> setValue(value);
		m_back = m_front;
		m_size ++;
	}
	else
	{
		Node<T>* last = new Node<T>();
		last -> setValue(value);
		last -> setPrev(m_back);
		m_back -> setNext(last);
		m_back = last;
		last = nullptr;
		delete last;
		m_size ++;
	}
}

//Remove an element from the back of the list
template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		if(m_back -> getPrev() != nullptr )
		{
			Node<T>* last = nullptr;
			last = m_back;
			m_back = m_back -> getPrev();
			m_back -> setNext(nullptr);
			last -> setPrev(nullptr);
			delete last;
			last = nullptr;
			m_size --;
			return(true);
		}
		else
		{
			m_front = nullptr;
			delete m_back;
			m_back = nullptr;
			m_size --;
			return(true);
		}
	}
}

//Remove an element from the front of the list
template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		if(m_front -> getNext() != nullptr )
		{
			Node<T>* first = nullptr;
			first = m_front;
			m_front = m_front -> getNext();
			m_front -> setPrev(nullptr);
			first -> setNext(nullptr);
			delete first;
			first = nullptr;
			m_size --;
			return(true);
		}
		else
		{
			m_back = nullptr;
			delete m_front;
			m_front = nullptr;
			m_size --;
			return(true);
		}
	}
}

//Remove the node containing the passed value
template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
	Node<T>* temp = find(value);

	if(isEmpty())
	{
		return(false);
	}

	if(temp == nullptr)
	{
		return(false);
	}
	else
	{
		if(temp -> getPrev() == nullptr)
		{
			removeFront();
			return(true);
		}
		else if(temp -> getNext() == nullptr)
		{
			removeBack();
			return(true);
		}
		else if(temp -> getPrev() != nullptr && temp -> getNext() != nullptr)
		{
			Node<T>* before = nullptr;
			Node<T>* after = nullptr;
			before = temp -> getPrev();
			after = temp -> getNext();
			before -> setNext(after);
			after -> setPrev(before);
			delete temp;
			before = nullptr;
			after = nullptr;
			m_size --;
			return(true);
		}
	}
}

//Add a new element ahead of an existing element
template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
	Node<T>* temp = find(listValue);
	if(temp != nullptr)
	{
		if(temp -> getPrev() == nullptr)
		{
			pushFront(newValue);
		}
		else if(temp -> getNext() == nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode -> setValue(newValue);
			newNode -> setNext(temp);
			newNode -> setPrev(temp -> getPrev());
			(temp ->getPrev()) -> setNext(newNode);
			temp -> setPrev(newNode);
			newNode = nullptr;
			m_size ++;
		}
		else if(temp -> getPrev() != nullptr && temp -> getNext() != nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode -> setValue(newValue);
			newNode -> setNext(temp);
			newNode -> setPrev(temp -> getPrev());
			(temp -> getPrev()) -> setNext(newNode);
			temp -> setPrev(newNode);
			newNode = nullptr;
			m_size ++;
		}
	}
	else
	{
		throw (std::runtime_error("The value given isn't in the list. Insert failed."));
	}
}

//Add a new element behind an existing element
template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
	Node<T>* temp = find(listValue);
	if(temp != nullptr)
	{
		if(temp -> getNext() == nullptr)
		{
				pushBack(newValue);
		}
		else if(temp -> getPrev() == nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode -> setValue(newValue);
			newNode -> setNext(temp -> getNext());
			newNode -> setPrev(temp);
			(temp -> getNext()) -> setPrev(newNode);
			temp -> setNext(newNode);
			newNode = nullptr;
			m_size ++;
		}
		else if(temp -> getPrev() != nullptr && temp -> getNext() != nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode -> setValue(newValue);
			newNode -> setNext(temp -> getNext());
			newNode -> setPrev(temp);
			(temp -> getNext()) -> setPrev(newNode);
			temp -> setNext(newNode);
			newNode = nullptr;
			m_size ++;
		}
	}
	else
	{
		throw (std::runtime_error("The value given isn't in the list. Insert failed."));
	}
}

//Return a pointer to the node that contains the value if it's found in the list, otherwise return nullptr
template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
	if(isEmpty())
	{
		return(nullptr);
	}
	else
	{
		Node<T>* temp = m_front;

		for(int i = 1; i <= this -> size(); i++)
		{
			if(temp -> getValue() == value)
			{
				return(temp);
			}
			else
			{
				temp = temp -> getNext();
			}
		}
	}

	return(nullptr);
}

//Print the elements in the list, if it's empty print the empty string
template <typename T>
void DoubleLinkedList<T>::printList() const
{
	if(isEmpty())
	{
		cout << "";
	}
	else
	{
		Node<T>* temp = m_front;
		for(int i = 1; i <= this -> size(); i++)
		{
			cout << temp -> getValue() << " ";
			temp = temp -> getNext();
		}
		temp = nullptr;
		delete temp;
	}
}
