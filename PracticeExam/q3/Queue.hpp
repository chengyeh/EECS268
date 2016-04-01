/**
*	@file Queue.hpp
*	@author John Gibbons
*	@date 2014.04.02
*/

template <typename T>
Queue<T>::Queue() : m_size(0), m_front(nullptr), m_back(nullptr)
{ }


template <typename T>
Queue<T>::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const 
{
	return (m_size==0);
}


template <typename T>
void Queue<T>::enqueue(T newEntry)
{
	if(m_front == nullptr)
	{
		m_front = new Node<T>(newEntry);
		m_back = m_front;
	}
	else
	{
		Node<T>* temp = new Node<T>(newEntry);
		m_back->setNext(temp);			
		m_back = temp;
	}
	
	m_size++;
}

template <typename T>
T Queue<T>::dequeue() throw(std::runtime_error)
{
	Node<T>* tempPtr;
	T temp;

	if(!isEmpty())
	{
		if(m_front -> getNext() == nullptr)
		{
			temp = m_front -> getValue();
			m_back = nullptr;
			delete m_front;
			m_front = nullptr;
			m_size--;
			return(temp);
		}
		else
		{
			tempPtr = m_front -> getNext();
			temp = m_front -> getValue();
			delete m_front;
			m_front = tempPtr;
			tempPtr = nullptr;
			m_size--;
			return(temp);
		}
	}
	else
	{
		throw std::runtime_error("cant do it");
	}
}

template <typename T>
void Queue<T>::backOfTheLine() throw (std::runtime_error)
{
	Node<T>* tempPtr;
	T temp;

	if(!isEmpty())
	{
		if(m_front -> getNext() == nullptr)
		{
			temp = m_front -> getValue();
			m_back = nullptr;
			delete m_front;
			m_front = nullptr;
			m_size--;
			enqueue(temp);
		}
		else
		{
			temp = m_front -> getValue();
                        dequeue();
			enqueue(temp);
		}
	}
	else
	{
		throw std::runtime_error("Queue empty");
	}
}

template <typename T>
T Queue<T>::peekFront() const throw(std::runtime_error)
{
	if(m_size > 0)
	{
		return(m_front->getValue());
	}
	else
	{
		throw( std::runtime_error("Peak attempted on empty queue") );
	}
}

template <typename T>
int Queue<T>::size() const
{
	return(m_size);
}


template <typename T>
void Queue<T>::print() const
{	
	Node<T>* tempPtr = m_front;
	while(tempPtr != nullptr)
	{
		std::cout << tempPtr -> getValue();
		if(tempPtr -> getNext() != nullptr)
		{
			std::cout << " ";
		}
		tempPtr = tempPtr -> getNext();
	}
}
