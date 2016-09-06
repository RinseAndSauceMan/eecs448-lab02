/**
*	@modified by pDreger 
*	@date 08/30/16
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	// Reset size at zero	
	int sizeOf = 0;
	
	bool isEmptyList = false;
	
	// Points to the head of the linked list.
	Node<T>* curPtr = m_front;
	
	// Check if empty list
	isEmptyList = isEmpty();
	if (isEmptyList != true)
	{
		// Marches the curPtr through the list till it hits the end (nullptr)
		while (curPtr != nullptr) 
		{
			// Advances the ptr down the list
			curPtr = curPtr->getNext();
			// Updates the size
			sizeOf++;
		}
	}
	else // an empty list, and do not have to do anything with it
	{}
	
	return(sizeOf);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	// Upper bound of what needs to be searched
	int linkedListSize = m_size;

	// MARCHES through the linked list
	for (int curPos = 0; curPos < linkedListSize; curPos++)
	{
		// COMPARING gotten values to sought value 
		if (temp->getValue() == value)
		{			
			isFound = true;
			// When value matches, break the loop early
			break;
		}
		else
		{}
	}	

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	// Can only remove from an non-empty list 
	if(!isEmpty())
	{
		// Get the size of the list
		int twoFromLast = size();

		// Attaches the trailing pointer to the front of the list
		secondintoLast = m_front;
		// For loop a bit more efficient than while if size is easily gotten
		for(int i = 0; i < twoFromLast; i++)
		{
			// MARCHES through the list
			secondintoLast = secondintoLast->getNext();
		}
		// Attaches the last node pointer to the last link in the chain
		lastNode = secondintoLast->getNext();
		
		// DESTROY the data being pointed to in the last node		
		delete lastNode;
		lastNode = nullptr;
		
		// ENDS the list
		secondintoLast->setNext(nullptr);
		// SHRINK the size
		m_size--;
		// ANNOUNCES back has been removed
		isRemoved = true;
	}
	else
	{
		// Could state can't remove the back of an empty list,
		// or throw an error
	}
	
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
