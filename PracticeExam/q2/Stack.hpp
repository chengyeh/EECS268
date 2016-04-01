/** 	@file Stack.hpp
*	@author John Gibbons
*	@date 2014.02.02
*/


template <typename T> 
Stack<T>::Stack()
{
	m_top = nullptr;
	m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
}

template <typename T>	
void Stack<T>::printStack() const
{


        if(isEmpty())
        {
            std::cout << "";
        }
        else
        {
              Node<T>* temp = m_top;
              for(int i=1; i<= this->size(); i++)
              {
                  std::cout << temp -> getValue() << " ";
                  temp = temp -> getNext();
            }
        }

}


template <typename T>
T Stack<T>::findMax() const throw(std::runtime_error)
{
	if(this->m_top == nullptr)
	{
		throw( std::runtime_error("Stack empty"));
	}
	else
	{
		Node<T>* temp = this->m_top;
		T max = temp->getValue();
		while(temp != nullptr)
		{
			if(max < temp->getValue())
			{
				max = temp->getValue();
			}
			temp = temp->getNext();
		}

		return(max);
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return(m_size==0);
}

template <typename T> 
void Stack<T>::push(T value)
{
	Node<T>* temp = m_top;
	m_top = new Node<T>(value);
	m_top->setNext(temp);
	m_size++;
}

template <typename T>
T Stack<T>::peek() const throw (std::runtime_error)
{
	if(nullptr == m_top)
	{
		throw(std::runtime_error("Peek attempted on empty stack"));
	}
	else
	{
		return(m_top->getValue());
	}
}

template <typename T>
void Stack<T>::popUntil(T value)
{
    while(!isEmpty() && value != peek())
    {
        pop();
    }
}


template <typename T>
T Stack<T>::pop()
{
	Node<T>* tempPtr;
	T temp;

	temp = m_top->getValue();
	tempPtr = m_top->getNext();


	delete m_top;
	m_size--;

	m_top = tempPtr;

	return(temp);
}

template <typename T>
int Stack<T>::size() const
{
	return(m_size);
}
