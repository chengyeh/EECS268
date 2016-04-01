/*
 * File Name: BSTI.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab8
 * Description: Header file of BSTI class. This is an interface class for a binary search tree.
 * Created on: Nov 06, 2015
 *
 */
#ifndef BSTI_H_
#define BSTI_H_

#include <vector>

enum Order
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
};

template <typename T>
class BSTI
{
public:

        /**
	*  @pre A BSTI exists
	*  @post Deletes the entire tree
	*  @return None
	*/
	virtual ~BSTI(){};

        /**
	*  @pre  this is in a valid state
	*  @post Creates a deep copy of this
	*  @return a pointer to a deep copy of this
	*/
	virtual BSTI<T>* clone() = 0;

        /**
	*  @pre None
	*  @post None
	*  @return  true if no nodes in the tree, otherwise returns false
	*/
	virtual bool isEmpty() const = 0;

        /**
	*  @pre value is a valid T
	*  @post a new Node<T> is created an inserted into the tree based
	*  @return false if the value couldn't be added (i.e. duplicate values not allowed)
	*/
	virtual bool add(T value) = 0;

        /**
	*  @pre The type T is comparable by the == operator
	*  @post search if the value is in the subtree
	*  @return  true if the value is in the tree, false otherwise
	*/
	virtual bool search(T value) const = 0;

        /**
	*  @pre None
	*  @post the contents of the tree are printed to the console in the specified order
	*  @return None
	*/
	virtual void printTree(Order order) const = 0;

        /**
	*  @pre Order is a valid Order
	*  @post Calls private method, treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec)
	*  @return  a vector with the contents of the tree in the specified order is returned
	*/
	virtual std::vector<T> treeToVector(Order order) const = 0;
};


#endif /* BSTI_H_ */
