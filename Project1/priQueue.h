#pragma once


template < typename T>
class priNode
{
private :
	T item;		// A data item
	int pri;
    //priority of the item
	priNode<T>* next; // Pointer to next node
public :
	priNode(const T& r_Item, int PRI)
	{
		setItem(r_Item, PRI);
		next = nullptr;
	}
	void setItem(const T& r_Item, int PRI)
	{
		item = r_Item;
		pri = PRI;
	}
	void setNext(priNode<T>* nextNodePtr)
	{		next = nextNodePtr; 	}
	
	T getItem(int& PRI) const
	{
		PRI = pri;
		return item;
	}
	
	priNode<T>* getNext() const 
	{		return next;	}
	
	int getPri() const
	{		return pri; 	}
}; // end Node

//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
    int count;
public:
    priQueue() : head(nullptr) ,count(0){}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    //insert the new node in its correct position according to its priority
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
    T& searchanddelete(T& x,int& pri) {
        if (isEmpty()) {
            return false;
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
            return;
        }
    }

    int getcount() {
        return count;
    }
    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
