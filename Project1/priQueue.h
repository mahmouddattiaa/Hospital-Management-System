/**
 * @file priQueue.h
 * @brief Implementation of a priority queue using a sorted linked list
 * 
 * This file implements a priority queue where elements are ordered by priority.
 * The element with highest priority is at the front of the queue.
 */

#pragma once

/**
 * @class priNode
 * @brief Node class for priority queue
 * 
 * Each node contains an item of type T, a priority value, and a pointer to the next node
 */
template <typename T>
class priNode
{
private:
	T item;		// A data item
	int pri;
    //priority of the item
	priNode<T>* next; // Pointer to next node
public :
	/**
	 * @brief Constructor
	 * @param r_Item The data to store in the node
	 * @param PRI The priority of the data
	 */
	priNode(const T& r_Item, int PRI)
	{
		setItem(r_Item, PRI);
		next = nullptr;
	}
	/**
	 * @brief Set the item and its priority
	 * @param r_Item The data to store
	 * @param PRI The priority value
	 */
	void setItem(const T& r_Item, int PRI)
	{
		item = r_Item;
		pri = PRI;
	}
	/**
	 * @brief Set the next node pointer
	 * @param nextNodePtr Pointer to the next node
	 */
	void setNext(priNode<T>* nextNodePtr)
	{		next = nextNodePtr; 	}
	
	/**
	 * @brief Get the item and its priority
	 * @param PRI Reference to store the priority value
	 * @return The data item
	 */
	T getItem(int& PRI) const
	{
		PRI = pri;
		return item;
	}
	
	/**
	 * @brief Get the next node
	 * @return Pointer to the next node
	 */
	priNode<T>* getNext() const 
	{		return next;	}
	
	/**
	 * @brief Get the priority value
	 * @return The priority value
	 */
	int getPri() const
	{		return pri; 	}
}; // end Node

/**
 * @class priQueue
 * @brief Priority queue implementation using a sorted linked list
 * 
 * The queue is maintained in descending order of priority,
 * with the highest priority element at the front of the queue.
 */
template <typename T>
class priQueue
{
    priNode<T>* head;
    int count;
public:
    /**
     * @brief Constructor
     * Initialize an empty priority queue
     */
    priQueue() : head(nullptr) ,count(0){}

    /**
     * @brief Destructor
     * Deallocate all nodes in the queue
     */
    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    /**
     * @brief Add an element to the priority queue
     * 
     * Inserts the new node in its correct position according to its priority.
     * Higher priority values are placed closer to the front.
     * 
     * @param data The data to be inserted
     * @param priority The priority value of the data
     */
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {
            
            newNode->setNext(head);
            head = newNode;
            count++;
            return;
        }
       
        priNode<T>* current = head;        
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext( current->getNext());
        current->setNext( newNode);        
        count++;
    }

    /**
     * @brief Remove and return the highest priority element
     * 
     * @param topEntry Reference to store the dequeued data
     * @param pri Reference to store the priority of the dequeued data
     * @return true if dequeue was successful, false if queue is empty
     */
    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
      
    }
    /**
     * @brief Search for and delete an element with matching data and priority
     * 
     * @param x The data to search for
     * @param pri The priority to match
     * @return The deleted element or default value if not found
     */
    T searchanddelete(T& x,int& pri) {
        if (isEmpty()) {
            return T(); // Return default value
        }
        if (head->getItem() == x&&head->getPri()==pri) {
            T temp;
            int y;
            dequeue(temp,y);
            return temp;
        }
        priNode<T>* currentptr = head;
        priNode<T>* previousptr = nullptr;
        while (currentptr != nullptr && currentptr->getItem() != x||currentptr->getPri()!=pri) {
            previousptr = currentptr;
            currentptr = currentptr->getNext();
        }
        if (currentptr != nullptr) {
            previousptr->setNext(currentptr->getNext());
            priNode<T>* deletednode = currentptr;
            delete currentptr;
            count--;
            return deletednode;

        }
        else {
            return T(); // Return default value
        }
    }

    /**
     * @brief Get the number of elements in the queue
     * @return Element count
     */
    int getcount() {
        return count;
    }
    /**
     * @brief View the highest priority element without removing it
     * 
     * @param topEntry Reference to store the front data
     * @param pri Reference to store the priority of the front data
     * @return true if peek was successful, false if queue is empty
     */
    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    /**
     * @brief Check if the queue is empty
     * @return true if empty, false otherwise
     */
    bool isEmpty() const {
        return head == nullptr;
    }
};
