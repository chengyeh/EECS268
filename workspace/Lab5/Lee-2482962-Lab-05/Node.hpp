/*
 * File Name: Node.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description:  Implementation of Node class.
 * Created on: Oct 16, 2015
 *
 */

//Initializes all the variables
template <typename T>
Node<T>::Node()
{
	m_next = nullptr;
	m_value = T();
}

//Set value of m_value
template <typename T>
void Node<T>::setValue(T val)
{
	m_value = val;
}

//Return m_value
template <typename T>
T Node<T>::getValue() const
{
	return(m_value);
}

//Set value of m_next
template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}

//Return m_next
template <typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next);
}


