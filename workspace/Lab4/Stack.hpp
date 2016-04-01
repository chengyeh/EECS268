/*
 * File Name: Stack.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab4
 * Description:  Implementation of Stack class.
 * Created on: Sep 28, 2015
 *
 */

#include <iostream>

using namespace std;

//Initializes all the variables
template <typename T>
Stack<T>::Stack()
{
	m_top = nullptr,
	m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
}

//Check if the stack is empty
template <typename T>
bool Stack<T>::isEmpty() const
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

//Add a new entry at top of the stack
template <typename T>
void Stack<T>::push(const T newEntry)
{
	if(isEmpty())
	{
		m_top = new Node<T>();
		m_top -> setValue(newEntry);
		m_size ++;
	}
	else
	{
		Node<T>* first = new Node<T>();
		first -> setValue(newEntry);
		first -> setNext(m_top);
		m_top = first;
		first = nullptr;
		delete first;
		m_size ++;
	}
}

//Remove top of the stack
template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(!isEmpty())
	{
		Node<T>* temp = m_top;
		m_top = m_top -> getNext();
		delete temp;
		temp = nullptr;
		m_size --;
	}
	else
	{
		throw PreconditionViolationException("Exception: Pop attempted on empty stack");
	}
}

//Return the value at the top of the stack
template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(!isEmpty())
	{
		return(m_top -> getValue());
	}
	else
	{
		throw PreconditionViolationException("Exception: Peek attempted on empty stack");
	}
}

//Return value of m_size
template <typename T>
int Stack<T>::size() const
{
	return(m_size);
}

//Print the contents on the stack, if it's empty print the empty string
template <typename T>
void Stack<T>::print() const
{
	if(isEmpty())
	{
		cout << "";
	}
	else
	{
		Node<T>* temp = m_top;
		for(int i = 1; i <= this -> size(); i++)
		{
			cout << temp -> getValue() << " ";
			temp = temp -> getNext();
		}
		temp = nullptr;
		delete temp;
	}
}



