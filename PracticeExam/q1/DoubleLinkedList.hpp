/**
*	@file DoubleLinkedList.hpp
*	@date 2014.02.23
*	Updated: 2014.09.30
*	@author John Gibbons
*/

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
	Node<T>* temp = m_front;
	Node<T>* next = nullptr;	

	while(temp != nullptr)
	{
		next = temp->getNext();
		delete temp;
		m_size--;		
		temp = next;
	}
}

template <typename T>
int DoubleLinkedList<T>::size()
{
	return(m_size);
}


template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return(m_size == 0);
}



template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp = new Node<T>();
	temp->setValue(value);

	if(m_size == 0)
	{
		m_front = temp;
		m_back = temp;
		temp->setPrevious(nullptr);
		temp->setNext(nullptr);
	}
	else
	{
		temp->setPrevious(nullptr);
		temp->setNext(m_front);
		m_front->setPrevious(temp);	
		m_front = temp;
	}	
	
	m_size++;
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T value) throw (std::runtime_error)
{
	Node<T>* temp = find(listValue);
	if(temp != nullptr)
	{
		if(temp -> getPrevious() == nullptr)
		{
			pushFront(value);
		}
		else if(temp -> getNext() == nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode -> setValue(value);
			newNode -> setPrevious(temp -> getPrevious());
			newNode -> setNext(temp);
			(temp -> getPrevious()) -> setNext(newNode);
			temp -> setPrevious(newNode);
			newNode = nullptr;
			m_size++;
		}
		else if(temp -> getPrevious() != nullptr && temp -> getNext() != nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode -> setValue(value);
			newNode -> setPrevious(temp -> getPrevious());
			newNode -> setNext(temp);
			(temp -> getPrevious()) -> setNext(newNode);
			temp -> setPrevious(newNode);
			newNode = nullptr;
			m_size++;
		}
	}
	else
	{
		throw std::runtime_error("The value cannot be inserted.");
	}
}



template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value)
{
	Node<T>* temp = m_front;

	while(temp != nullptr)
	{
		if(temp->getValue() == value)
		{
			return(temp);
		}
		else
		{
			temp = temp->getNext();
		}
	}
	
	return(nullptr);
}


template <typename T>
void DoubleLinkedList<T>::printList() const
{
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		std::cout << temp->getValue();
		if(temp->getNext() != nullptr)
		{
			std::cout << " ";
		}

		temp = temp->getNext();
	}
}


template <typename T>
void DoubleLinkedList<T>::printReverse() const
{

        if(isEmpty())
        {
//            std::cout << " ";
        }
        else
        {
            Node<T>* temp = m_back;
            for(int i=1; i<= this -> size(); i++)
            {
                std::cout << temp->getValue() << " ";
                temp = temp->getPrevious();
            }

        }

}

	
