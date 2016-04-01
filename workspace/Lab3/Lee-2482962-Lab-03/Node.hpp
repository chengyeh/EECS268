/*
 * File Name: Node.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab3
 * Description:  Implementation of Node class.
 * Created on: Sep 21, 2015
 *
 */

//Initializes all the variables
template <typename T>
Node<T>::Node()
{
	m_next = nullptr;
	m_previous = nullptr;
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

//Set value of m_previous
template <typename T>
void Node<T>::setPrev(Node<T>* prev)
{
	m_previous = prev;
}

//Return m_previous
template <typename T>
Node<T>* Node<T>::getPrev() const
{
	return(m_previous);
}

