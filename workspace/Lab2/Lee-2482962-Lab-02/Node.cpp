/*
 * File Name: Node.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab2
 * Description:  Implementation of Node class.
 * Created on: Sep 14, 2015
 *
 */

#include "Node.h"

//Initializes all the variables
Node::Node()
{
	m_value = 0;
	m_next = nullptr;
}

//Set value of m_value
void Node::setValue(int val)
{
	m_value = val;
}

//Return m_value
int Node::getValue() const
{
	return(m_value);
}

//Set value of m_next
void Node::setNext(Node* prev)
{
	m_next = prev;
}

//Return m_next
Node* Node::getNext() const
{
	return(m_next);
}
