/*
 * File Name: BinarySearchTree.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab8
 * Description: Header file of BinarySearchTree class.
 * Created on: Nov 06, 2015
 *
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>

#include "BSTI.h"
#include "Node.h"


template <typename T>
class BinarySearchTree : public BSTI<T>
{
public:
        /**
	*  @pre None
	*  @post Sets m_root to nullptr
	*  @return Initialzed variables
	*/
	BinarySearchTree();

        /**
	*  @pre A valid BST reference
	*  @post Creates a deep copy of the other BST
	*  @return None
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);

        /**
	*  @pre If the tree is not empty
	*  @post Calls private method, deleteTree(Node<T>* subTree) and passes in m_root as the starting point for deletion
	*  @return None
	*/
	~BinarySearchTree();

        /**
	*  @pre None
	*  @post Creates a deep copy of this
	*  @return A pointer to a deep copy of this
	*/
	BSTI<T>* clone();

        /**
	*  @pre None
	*  @post None
	*  @return True if no nodes in the tree, otherwise returns false
	*/
	bool isEmpty() const;

        /**
	*  @pre A valid value
	*  @post Calls a private method of the same name and adds the value to the tree
	*  @return True if add operation was successful, oherwise returns false
	*/
	bool add(T value);

        /**
	*  @pre The type T is comparable by the == operator
	*  @post Calls private method, search(T value, Node<T>* subtree) and passes in value and m_root
	*  @return True if the value is in the tree, false otherwise
	*/
	bool search(T value) const;

        /**
	*  @pre The contents of the tree are printed to the console in the specified order
	*  @post Calls private method, printTree(Node<T>* subtree, Order order) and passes in m_root and order
	*  @return None
	*/
	void printTree(Order order) const;

        /**
	*  @pre A valid order
	*  @post Calls private method, treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) and passes in m_root, order, and vector
	*  @return A vector with the contents of the tree in the specified order is returned
	*/
	std::vector<T> treeToVector(Order order) const;

private:
    
	Node<T>* m_root;

        /**
	*  @pre a valid value and subtree
	*  @post adds the value to the correct branch (left or right) of the subtree
	*  @return true if add operation was successful
	*/
	bool add(T value, Node<T>* subtree);

        /**
	*  @pre a valid subtree
	*  @post deletes the left subtree, right subtree, and root node of the subtree passed in
	*  @return none
	*/
	void deleteTree(Node<T>* subTree);

        /**
	*  @pre a valid value and subtree
	*  @post search if the value is in the subtree
	*  @return  true if the value is in the tree, false otherwise
	*/
	bool search(T value, Node<T>* subtree) const;

        /**
	*  @pre a valid subtree and order
	*  @post prints the tree in PRE_ORDER or IN_ORDER or POST_ORDER using the subtree and the "order"
	*  @return none
	*/
	void printTree(Node<T>* subtree, Order order) const;

        /**
	*  @pre a valid subtree and order
	*  @post recursive helper function to load the vector, vec, in the specified order
	*  @return none
	*/
	void treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const;
};

#include "BinarySearchTree.hpp"

#endif /* BINARYSEARCHTREE_H_ */
