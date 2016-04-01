/*
 * File Name: Node.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab8
 * Description: Header file of Node class.
 * Created on: Nov 06, 2015
 *
 */

#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node
{
private:
	Node<T>* m_left;

	Node<T>* m_right;

	T m_value;

public:
        /**
	*  @pre None
	*  @post Sets m_left and m_right to nullptr
	*  @return Initialzed variables
	*/
	Node();

        /**
	*  @pre A valid Node<T>&
	*  @post Create a deep copy of the other node, meaning it also creates copies of any nodes being pointed to by other
	*  @return None
	*/
	Node(const Node<T>& other);

        /**
	*  @pre None 
	*  @post None
	*  @return m_value
	*/
	T getValue() const;

        /**
	*  @pre None
	*  @post None
	*  @return m_left
	*/
	Node<T>* getLeft() const;

        /**
	*  @pre None
	*  @post None
	*  @return m_right
	*/
	Node<T>* getRight() const;

        /**
	*  @pre A valid User input value
	*  @post sets m_value to value
	*  @return None
	*/
	void setValue(T value);

        /**
	*  @pre A left Node pointer
	*  @post sets m_left to left
	*  @return None
	*/
	void setLeft(Node<T>* left);

        /**
	*  @pre A riht Node pointer
	*  @post sets m_right = right
	*  @return None
	*/
	void setRight(Node<T>* right);
};

#include "Node.hpp"


#endif /* NODE_H_ */
