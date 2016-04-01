/*
 * File Name: BinarySearchTree.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab8
 * Description: Implementation of BinarySearchTree class.
 * Created on: Nov 06, 2015
 *
 */

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	m_root = new Node<T>(*(other.m_root));
}


template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if(!isEmpty())
	{
		deleteTree(m_root);
		m_root = nullptr;
	}
}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
	if(isEmpty())
	{
		BSTI<T>* clonePtr = new BinarySearchTree<T>();
		return(clonePtr);
	}
	else
	{
		BSTI<T>* clonePtr = new BinarySearchTree<T>(*(this));
		return(clonePtr);
	}
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	if(m_root == nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}

}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
	if(add(value, m_root))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template <typename T>
bool BinarySearchTree<T>::search(T value) const
{
	return(search(value, m_root));
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
	printTree(m_root, order);
}

template <typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const
{
	std::vector<T> vector = {};
	if(isEmpty())
	{
		return(vector);
	}
	else
	{
		treeToVector(m_root, order, vector);
		int i;
		while(i < vector.size())
		{
			std::cout << vector[i];
			i++;
		}
		return(vector);
	}
}

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	if(m_root == nullptr)
	{
		m_root = new Node<T>();
		m_root -> setValue(value);
		return(true);
	}
	else if(value < subtree -> getValue())
	{
		if(subtree -> getLeft() == nullptr)
		{
			Node<T>* temp = new Node<T>();
			temp -> setValue(value);
			subtree -> setLeft(temp);
			temp = nullptr;
			return(true);
		}
		else
		{
			return(add(value, subtree -> getLeft()));
		}
	}
	else if(value > subtree -> getValue())
	{
		if(subtree -> getRight() == nullptr)
		{
			Node<T>* temp = new Node<T>();
			temp -> setValue(value);
			subtree -> setRight(temp);
			temp = nullptr;
			return(true);
		}
		else
		{
			return(add(value, subtree -> getRight()));
		}
	}
	else
	{
		return(false);
	}
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
	if(subTree != nullptr)
	{
		if(subTree -> getLeft() != nullptr)
		{
			deleteTree(subTree -> getLeft());
		}
		if(subTree -> getRight() != nullptr)
		{
			deleteTree(subTree -> getRight());
		}

		delete subTree;
	}
}

template<typename T>
bool  BinarySearchTree<T>::search(T value, Node<T>* subtree) const
{
	if(subtree != nullptr)
	{
		if(value == subtree -> getValue())
		{
			return(true);
		}
		else if(value < (subtree -> getValue()))
		{
			return(search(value, subtree->getLeft()));
		}
		else if (value > (subtree -> getValue()))
		{
			return(search(value, subtree -> getRight()));
		}
	}
	else
	{
		return(false);
	}
}

template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{
	if(order == PRE_ORDER)
	{
		 if(subtree != nullptr)
		 {
			 std::cout << subtree -> getValue() << " ";
			 printTree(subtree -> getLeft(), order);
			 printTree(subtree -> getRight(), order);
		 }
	}
	if(order == IN_ORDER)
	{
		if(subtree != nullptr)
		{
			printTree(subtree -> getLeft(), order);
			std::cout << subtree -> getValue() << " ";
			printTree(subtree -> getRight(), order);
		}
	}
	if(order == POST_ORDER)
	{
		if(subtree != nullptr)
		{
			printTree(subtree -> getLeft(), order);
			printTree(subtree -> getRight(), order);
			std::cout << subtree -> getValue() << " ";
		}
	}
}

template<typename T>
void BinarySearchTree<T>::treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const
{
	if(order == PRE_ORDER)
	{
		if(subtree != nullptr)
		{
			vec.push_back(subtree -> getValue());
			treeToVector(subtree -> getLeft(), order, vec);
			treeToVector(subtree -> getRight(), order, vec);
		}
	}
	if(order == IN_ORDER)
	{
		if(subtree != nullptr)
		{
			treeToVector(subtree -> getLeft(), order, vec);
			vec.push_back(subtree -> getValue());
			treeToVector(subtree -> getRight(), order, vec);
		}
	}
	if(order == POST_ORDER)
	{
		if(subtree != nullptr)
		{
			treeToVector(subtree -> getLeft(), order, vec);
			treeToVector(subtree -> getRight(), order, vec);
			vec.push_back(subtree -> getValue());
		}
	}
}

