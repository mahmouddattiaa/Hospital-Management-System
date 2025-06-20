/**
 * @file LinkedQueue.h
 * @brief Implementation of a queue using a linked list
 *
 * This file implements the queue abstract data type using a linked list.
 * The queue is implemented as a chain of linked nodes with two pointers:
 * - frontPtr: points to the front of the queue 
 * - backPtr: points to the back of the queue
 */

/*

				The Node: item of type T and a "next" pointer
					------------- 
					| item| next | --->
					-------------
General Queue case:

                 frontPtr																backPtr
					\											   						/		
					 \											  					   /		
					------------- 	  ------------- 	  ------------- 	  ------------- 	  	  
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------	  
		
Empty Case:

                 frontptr	 backptr
						\	 /				
						 \	/				
					---- NULL ------


Single Node Case:
                 frontPtr	 backPtr
					\		/	
					 \	   /			
					----------- 	
					|item| next| -->NULL
					-----------	

*/

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

/**
 * @class Node
 * @brief Node class for the linked queue
 * 
 * Each node contains an item of type T and a pointer to the next node
 */
template <typename T>
class Node
{
private:
	T item;           // A data item
	Node<T>* next;    // Pointer to next node
	
public:
	// Constructors
	Node();
	Node(const T& r_Item);    
	Node(const T& r_Item, Node<T>* nextNodePtr);
	
	// Setters
	void setItem(const T& r_Item);
	void setNext(Node<T>* nextNodePtr);
	
	// Getters
	T getItem() const;
	Node<T>* getNext() const;
}; // end Node

// Node implementation
template <typename T>
Node<T>::Node() 
{
	next = nullptr;
} 

template <typename T>
Node<T>::Node(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
} 

template <typename T>
Node<T>::Node(const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}

template <typename T>
void Node<T>::setItem(const T& r_Item)
{
	item = r_Item;
} 

template <typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template <typename T>
T Node<T>::getItem() const
{
	return item;
} 

template <typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
} 

/**
 * @class LinkedQueue
 * @brief Queue implementation using linked list
 *
 * Supports basic queue operations: enqueue, dequeue, peek,
 * as well as additional operations for searching and deletion
 */
template <typename T>
class LinkedQueue
{
private:
	Node<T>* backPtr;     // Pointer to the back of the queue
	Node<T>* frontPtr;    // Pointer to the front of the queue
	int count;            // Number of elements in the queue
	
public:
	// Constructors and destructor
	LinkedQueue();    
	~LinkedQueue();
	LinkedQueue(const LinkedQueue<T>& LQ);  // Copy constructor
	
	// Basic queue operations
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peek(T& frntEntry) const;
	
	// Additional operations
	bool searchanddelete(T& x);  // Search for an item and delete it
	T search(T& x);              // Search for an item and return it
	int getcount();              // Get the number of items in the queue
};

/************************* Implementation *************************/

/**
 * @brief Default constructor
 * Initializes an empty queue
 */
template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	count = 0;
}

/**
 * @brief Checks if the queue is empty
 * @return true if the queue is empty, false otherwise
 */
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/**
 * @brief Get the count of elements in the queue
 * @return Number of elements in the queue
 */
template <typename T>
int LinkedQueue<T>::getcount()
{
	return count;
}

/**
 * @brief Adds a new item to the back of the queue
 * @param newEntry The item to be added
 * @return true if item was added successfully, false otherwise
 */
template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	
	// Queue is empty
	if (isEmpty())
		frontPtr = newNodePtr; // The queue now has only one node
	else
		backPtr->setNext(newNodePtr); // Link the new node to the queue's back
	
	backPtr = newNodePtr; // New node is the back of the queue
	count++;
	return true;
}

/**
 * @brief Removes the front item from the queue
 * @param frntEntry A reference to receive the dequeued item
 * @return true if item was dequeued successfully, false if queue is empty
 */
template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;
		
	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	
	// Queue is now empty
	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;
		
	delete nodeToDeletePtr;
	count--;
	return true;
}

/**
 * @brief Retrieves the front item without removing it
 * @param frntEntry A reference to receive the front item
 * @return true if item was retrieved successfully, false if queue is empty
 */
template <typename T>
bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;
		
	frntEntry = frontPtr->getItem();
	return true;
}

/**
 * @brief Search for and delete an item from the queue
 * @param x The item to search for and delete
 * @return true if item was found and deleted, false otherwise
 */
template <typename T>
bool LinkedQueue<T>::searchanddelete(T& x)
{
	if (isEmpty()) {
		return false;
	}
	
	// Handle case where target is at front
	if (frontPtr->getItem() == x) {
		T temp;
		dequeue(temp);
		return true;
	}
	
	// Search through the queue
	Node<T>* currentptr = frontPtr;
	Node<T>* previousptr = nullptr;
	while (currentptr != nullptr && currentptr->getItem() != x) {
		previousptr = currentptr;
		currentptr = currentptr->getNext();
	}
	
	// Item found
	if (currentptr != nullptr) {
		previousptr->setNext(currentptr->getNext());
		if (currentptr == backPtr) {
			backPtr = previousptr;
		}
		delete currentptr;
		count--;
		return true;
	}
	// Item not found
	return false;
}

/**
 * @brief Search for an item in the queue
 * @param x The item to search for
 * @return The found item or default value if not found
 */
template <typename T>
T LinkedQueue<T>::search(T& x)
{
	if (isEmpty()) {
		return T(); // Return default value
	}
	
	if (frontPtr->getItem() == x) {
		return frontPtr->getItem();
	}
	
	Node<T>* currentptr = frontPtr;
	while (currentptr != nullptr) {
		if (currentptr->getItem() == x) {
			return currentptr->getItem();
		}
		currentptr = currentptr->getNext();
	}
	
	return T(); // Return default value if not found
}

/**
 * @brief Copy constructor
 * @param LQ The queue to copy from
 */
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	frontPtr = nullptr;
	backPtr = nullptr;
	count = 0;
	
	// If the original queue is empty, nothing to copy
	if (LQ.frontPtr == nullptr)
		return;
		
	// Copy nodes one by one from the original queue
	Node<T>* origPtr = LQ.frontPtr;
	while (origPtr != nullptr) {
		enqueue(origPtr->getItem());
		origPtr = origPtr->getNext();
	}
}

/**
 * @brief Destructor
 * Deallocates all nodes in the queue
 */
template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	T temp;
	while (dequeue(temp)); // Dequeue until queue is empty
}

#endif // LINKED_QUEUE_

