/*
 * File Name: Node.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab8
 * Description: Implementation of Node class.
 * Created on: Nov 06, 2015
 *
 */

template <typename T>
Node<T>::Node()
{
	m_left = nullptr;
	m_right = nullptr;

}

template <typename T>
Node<T>::Node(const Node<T>& other)
{
	m_value = other.getValue();
	m_left = nullptr;
	m_right = nullptr;

	if(other.getLeft() != nullptr)
	{
		m_left = new Node(*(other.getLeft()));
	}

	if(other.getRight() != nullptr)
	{
		m_right = new Node(*(other.getRight()));
	}
}

template <typename T>
T Node<T>::getValue() const
{
	return(m_value);
}

template <typename T>
Node<T>* Node<T>::getLeft() const
{
	return(m_left);
}

template <typename T>
Node<T>* Node<T>::getRight() const
{
	return(m_right);
}

template <typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left)
{
	m_left = left;
}

template <typename T>
void Node<T>::setRight(Node<T>* right)
{
	m_right = right;
}
