/*-- DoublyLinkedList.h ---------------------------------------------------

  This header file defines a DoublyLinkedList data type.
  Basic operations:
	constructor:  		Constructs an empty list
	empty:        		Checks if a list is empty
	insert:         	Modifies a list by adding a value at a defined position
	dataAtPosition:     Retrieves data from the list; leaves list unchanged
	delete:          	Modifies a list by removing a value at the defined position
	display:      		Displays all the list elements

  Class Invariant:
	1. The list elements (if any) are stored in Nodes.
	2. mySize >= 0.

---------------------------------------------------------------------------*/
#ifndef LIST
#define LIST

#include <iostream>
#include <cassert>

using namespace std;

template <typename ElementType>
class DoublyLinkedList
{
public:
	/******** Function Members ********/
	/***** Class constructor *****/
	DoublyLinkedList();
	/*----------------------------------------------------------------------
	 Construct a DoublyLinkedList object.

	 Precondition:  None
	 Postcondition: An empty DoublyLinkedList object has been constructed;
	 mySize is 0 and myFirst is NULL.
	-----------------------------------------------------------------------*/

	/***** Copy constructor *****/
	DoublyLinkedList(const DoublyLinkedList &);
	/*------------------------------------------------------------------------
	 Copy Constructor
	 Precondition: original is the list to be copied and is received as
	 a const reference parameter.
	 Postcondition: A copy of original has been constructed.
	------------------------------------------------------------------------*/

	/***** Destructor *****/
	~DoublyLinkedList();
	/*-----------------------------------------------------------------------
	 Class destructor

	 Precondition: None
	 Postcondition: The doubly linked list has been deallocated.
	------------------------------------------------------------------------*/

	/***** Assignment *****/
	DoublyLinkedList &operator=(const DoublyLinkedList &);
	/*----------------------------------------------------------------------
	 Assign a copy of a DoublyLinkedList object to the current object.

	 Precondition: none
	 Postcondition: A copy of rhs has been assigned to this object.
	 A const reference to this list is returned.
	-----------------------------------------------------------------------*/

	bool isEmpty() const;
	/*------------------------------------------------------------------------
	 Check if list is empty.
	 Precondition: None
	 Postcondition: Returns true if list is empty and false otherwise.
	-----------------------------------------------------------------------*/

	void insertAtBeginning(const ElementType &);
	/*----------------------------------------------------------------------
	 Insert a value into the list at the beginning.

	 Precondition:  value is the value to be inserted.
	 Postcondition: value has been inserted into the list at the first legal
	 position.
	-----------------------------------------------------------------------*/

	void insertAtEnd(const ElementType &);
	/*----------------------------------------------------------------------
	 Insert a value into the list at the end.

	 Precondition:  value is the value to be inserted.
	 Postcondition: value has been inserted into the list at the last legal
	 position.
	-----------------------------------------------------------------------*/

	bool insertAtPosition(const ElementType &, int);
	/*----------------------------------------------------------------------
	 Insert a value into the list at a given position.

	 Precondition:  value is the value to be inserted; the position satisfies
		 0 <= pos <= mySize.
	 Postcondition: returns true if value has been inserted successfully
	 at the desired position, fasle otherwise.
	-----------------------------------------------------------------------*/

	void removeAtBeginning();
	/*----------------------------------------------------------------------
	 Delete a value at the beginning of the list.

	 Precondition:  list must not be empty.
	 Postcondition: the first value in the list has been deleted.
	-----------------------------------------------------------------------*/

	void removeAtEnd();
	/*----------------------------------------------------------------------
	 Delete a value at the end of the list.

	 Precondition:  list must not be empty.
	 Postcondition: the last value in the list has been deleted.
	-----------------------------------------------------------------------*/

	bool removeAtPosition(int);
	/*----------------------------------------------------------------------
	 Delete a value at a specific position in the list.

	 Precondition:  list must not be empty. 0 <= pos <= mySize.
	 Postcondition: Returns true if the value at the desired position was
	 deleted sucessfully, false otherwise.
	-----------------------------------------------------------------------*/

	void display(ostream &) const;
	/*-----------------------------------------------------------------------
	 Display values stored in the list.

	 Precondition:  ostream out is open.
	 Postcondition: List's contents, from beginning to end, have been
	 output to out.
	-----------------------------------------------------------------------*/

	int size() const;
	/*-----------------------------------------------------------------------
	 Size of the list.

	 Precondition:  none.
	 Postcondition: returns the number of elements in the list.
	-----------------------------------------------------------------------*/

	bool contains(const ElementType &) const;
	/*-----------------------------------------------------------------------
	 Check if a value exists in the list.

	 Precondition:  list is not empty.
	 Postcondition: returns true if the value was found, false otherwise.
	-----------------------------------------------------------------------*/

	int search(const ElementType &) const;
	/*-----------------------------------------------------------------------
	 Search for a value in the list.

	 Precondition:  list is not empty.
	 Postcondition: returns the index of value if found, -1 otherwise..
	-----------------------------------------------------------------------*/

	ElementType &getDataAtPosition(int pos) const;
	/*-----------------------------------------------------------------------
	 Retrieve data at a position in the list.

	 Precondition:  list is not empty.
	 Postcondition: returns a const reference to the value if found,
	 garbage otherwise.
	-----------------------------------------------------------------------*/

protected:
	/******** Data Members ********/
	class DNode
	{ // Node class used to store list data
	public:
		DNode *next;
		DNode *prev;
		ElementType value;
		DNode(const ElementType &);
	};

	DNode *myFirst; // Pointer to the first node in the list
	int mySize;		// Current size of the list
};					//--- end of DoublyLinkedList class

/*------------------------------------------------------------------------
   Implementation of the list member functions
-------------------------------------------------------------------------*/

//--- Definition of class constructor
template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList()
{
	myFirst = NULL;
	mySize = 0;
}

//--- Definition of class copy constructor
template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList<ElementType> &orig)
{
	myFirst = NULL;
	mySize = 0;
	if (this != &orig)
	{
		if (!orig.isEmpty())
		{
			DNode *origPtr = orig.myFirst;
			while (origPtr != NULL)
			{
				insertAtEnd(origPtr->value);
				origPtr = origPtr->next;
			}
		}
	}
}

//--- Definition of DNode class constructor
template <typename ElementType>
DoublyLinkedList<ElementType>::DNode::DNode(const ElementType &value)
{
	this->value = value;
	next = NULL;
	prev = NULL;
}

//--- Definition of class destructor
template <typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList()
{
	while (mySize > 0)
	{
		removeAtBeginning();
		mySize--;
	}
}

//--- Definition of overloaded assignment operator
template <typename ElementType>
DoublyLinkedList<ElementType> &DoublyLinkedList<ElementType>::operator=(const DoublyLinkedList<ElementType> &rhs)
{
	if (this != &rhs)
	{
		this->~DoublyLinkedList();
		myFirst = NULL;
		mySize = 0;
		if (!rhs.isEmpty())
		{
			DNode *rhsPtr = rhs.myFirst;
			while (rhsPtr != NULL)
			{
				insertAtEnd(rhsPtr->value);
				rhsPtr = rhsPtr->next;
			}
		}
	}
	return *(this);
}

//--- Definition of empty operation
template <typename ElementType>
bool DoublyLinkedList<ElementType>::isEmpty() const
{
	return myFirst == NULL;
}

//--- Definition of insertAtBeginning()
template <typename ElementType>
void DoublyLinkedList<ElementType>::insertAtBeginning(const ElementType &value)
{
	DNode *newNodePtr = new (nothrow) DNode(value);
	assert(newNodePtr != NULL);
	if (isEmpty())
	{
		myFirst = newNodePtr;
	}
	else
	{
		newNodePtr->next = myFirst;
		myFirst->prev = newNodePtr;
		myFirst = newNodePtr;
	}
	mySize++;
}

//--- Definition of insertAtEnd()
template <typename ElementType>
void DoublyLinkedList<ElementType>::insertAtEnd(const ElementType &value)
{

	if (isEmpty())
	{
		insertAtBeginning(value);
	}
	else
	{
		DNode *newNodePtr = new (nothrow) DNode(value);
		assert(newNodePtr != NULL);
		DNode *p = myFirst;
		while (p != NULL)
		{
			if (p->next == NULL)
			{
				break;
			}
			p = p->next;
		}
		p->next = newNodePtr;
		newNodePtr->prev = p;
		mySize++;
	}
}

//--- Definition of insertAtPosition()
template <typename ElementType>
bool DoublyLinkedList<ElementType>::insertAtPosition(const ElementType &value, int position)
{
	if (position < 0 || position > mySize)
	{
		return false;
	}
	if (position == 0)
	{
		insertAtBeginning(value);
		return true;
	}
	if (isEmpty())
	{
		return false;
	}
	DNode *newNodePtr = new (nothrow) DNode(value);
	if (newNodePtr == NULL)
	{
		return false;
	}
	DNode *p = myFirst;
	while (position > 1)
	{
		p = p->next;
		position--;
	}
	newNodePtr->next = p->next;
	newNodePtr->prev = p;
	if (p->next == NULL)
	{
		insertAtEnd(value);
		return true;
	}
	p->next->prev = newNodePtr;
	p->next = newNodePtr;
	mySize++;
	return true;
}

//--- Definition of removeAtBeginning()
template <typename ElementType>
void DoublyLinkedList<ElementType>::removeAtBeginning()
{
	assert(!isEmpty());
	DNode *p = myFirst->next;
	delete myFirst;
	myFirst = p;
	mySize--;
}

//--- Definition of removeAtEnd()
template <typename ElementType>
void DoublyLinkedList<ElementType>::removeAtEnd()
{
	assert(!isEmpty());
	DNode *p = myFirst;
	if (p->next == NULL)
	{
		removeAtBeginning();
	}
	else
	{
		while (p != NULL)
		{
			if (p->next->next == NULL)
			{
				break;
			}
			p = p->next;
		}

		delete p->next;
		p->next = NULL;
		mySize--;
	}
}

//--- Definition of removeAtPosition()
template <typename ElementType>
bool DoublyLinkedList<ElementType>::removeAtPosition(int position)
{
	if (position < 0 || position >= mySize)
	{
		return false;
	}
	if (position == 0)
	{
		removeAtBeginning();
		return true;
	}
	if (isEmpty())
	{
		return false;
	}
	DNode *p = myFirst;
	while (position > 1)
	{
		p = p->next;
		position--;
	}

	if (p->next->next == NULL)
	{
		removeAtEnd();
		return true;
	}
	DNode *tmp = p->next;
	p->next = tmp->next;
	p->next->prev = p;
	mySize--;
	delete tmp;
	return true;
}

//--- Definition of size() operation
template <typename ElementType>
int DoublyLinkedList<ElementType>::size() const
{
	return mySize;
}

//--- Definition of getDataAtPosition()
template <typename ElementType>
ElementType &DoublyLinkedList<ElementType>::getDataAtPosition(int pos) const
{
	if (!isEmpty())
	{
		if (pos >= 0 && pos < mySize)
		{
			DNode *p = myFirst;
			while (pos > 0)
			{
				p = p->next;
				pos--;
			}
			return p->value;
		}
	}
	ElementType g;
	return g;
}

//--- Definition of search operation
template <typename ElementType>
int DoublyLinkedList<ElementType>::search(const ElementType &toSearchFor) const
{
	if (!isEmpty())
	{
		int counter = 0;
		while (counter < mySize)
		{
			ElementType curr = getDataAtPosition(counter);
			if (curr == toSearchFor)
			{
				return counter;
			}
			counter++;
		}
	}
	return -1;
}

//--- Definition of display()
template <typename ElementType>
void DoublyLinkedList<ElementType>::display(ostream &out) const
{
	if (!isEmpty())
	{
		DNode *p = myFirst;
		while (p != NULL)
		{
			out << p->value;
			p = p->next;
		}
	}
	else
	{
		out << "Empty List.";
	}
}

//--- Definition of contains()
template <typename ElementType>
bool DoublyLinkedList<ElementType>::contains(const ElementType &obj) const
{
	if (!isEmpty())
	{
		int resultPos = search(obj);
		return resultPos != -1;
	}

	return false;
}

/*------------------------------------------------------------------------
	Implementation of non-member functions
-------------------------------------------------------------------------*/

//-- Definition of overloaded output operator
template <typename ElementType>
ostream &operator<<(ostream &out, const DoublyLinkedList<ElementType> &ref)
{
	ref.display(out);
	return out;
}

#endif
