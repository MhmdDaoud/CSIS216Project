/*-- LinkedListWithDummy.h ---------------------------------------------------

  This header file defines a LinkedListWithDummy data type.
  Basic operations:
	constructor:  		Constructs a list with a dummy node
	empty:        		Checks if a list is empty
	insert:         	Modifies a list by adding a value at a defined position
	dataAtPosition:     Retrieves data from the list; leaves list unchanged
	delete:          	Modifies a list by removing a value at the defined position
	display:      		Displays all the list elements

  Class Invariant:
	1. The list elements (if any) are stored in Nodes.
	2. mySize >= 0.

------------------------------------------------------------------------------*/
#ifndef LINKEDLISTWITHDUMMY_H
#define LINKEDLISTWITHDUMMY_H

#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

template <typename ElementType>
class LinkedListWithDummy
{
public:
	/******** Function Members ********/
	/***** Class constructor *****/
	LinkedListWithDummy();
	/*----------------------------------------------------------------------
	 Construct a LinkedListWithDummy object.

	 Precondition:  None
	 Postcondition: A LinkedListWithDummy object with a dummy has been constructed;
	 mySize is 0 and myFirst is g (dummy node).
	-----------------------------------------------------------------------*/

	/***** Copy constructor *****/
	LinkedListWithDummy(const LinkedListWithDummy &);
	/*------------------------------------------------------------------------
	 Copy Constructor
	 Precondition: original is the list to be copied and is received as
	 a const reference parameter.
	 Postcondition: A copy of original has been constructed.
	------------------------------------------------------------------------*/

	/***** Destructor *****/
	~LinkedListWithDummy();
	/*-----------------------------------------------------------------------
	 Class destructor

	 Precondition: None
	 Postcondition: The linked list with dummy has been deallocated.
	------------------------------------------------------------------------*/

	bool isEmpty() const;
	/*------------------------------------------------------------------------
	 Check if list is empty.
	 Precondition: None
	 Postcondition: Returns true if list is empty and false otherwise.
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

	void insertAtEnd(const ElementType &);
	/*----------------------------------------------------------------------
	 Insert a value into the list at the end.

	 Precondition:  value is the value to be inserted.
	 Postcondition: value has been inserted into the list at the last legal
	 position.
	-----------------------------------------------------------------------*/

	bool removeAtPosition(int);
	/*----------------------------------------------------------------------
	 Delete a value at a specific position in the list.

	 Precondition:  list must not be empty. 0 <= pos <= mySize.
	 Postcondition: Returns true if the value at the desired position was
	 deleted sucessfully, false otherwise.
	-----------------------------------------------------------------------*/

	ElementType &getDataAtPosition(int) const;
	/*-----------------------------------------------------------------------
	 Retrieve data at a position in the list.

	 Precondition:  list is not empty.
	 Postcondition: returns a const reference to the value if found,
	 garbage otherwise.
	-----------------------------------------------------------------------*/

	LinkedListWithDummy &operator=(const LinkedListWithDummy &);
	/*----------------------------------------------------------------------
	 Assign a copy of a LinkedListWithDummy object to the current object.

	 Precondition: none
	 Postcondition: A copy of rhs has been assigned to this object.
	 A const reference to this list is returned.
	-----------------------------------------------------------------------*/

protected:
	class Node
	{ // Node class used to store list data
	public:
		ElementType data;
		Node *next;

		Node(const ElementType &n) : data(n), next(NULL) {}
	};

	typedef Node *NodePtr;
	NodePtr myFirst; // Pointer to the first node in the list
	int mySize;		 // Current size of the list
};

/*------------------------------------------------------------------------
   Implementation of the list member functions
-------------------------------------------------------------------------*/

//--- Definition of constructor
template <typename ElementType>
LinkedListWithDummy<ElementType>::LinkedListWithDummy()
{
	ElementType g;
	myFirst = new Node(g);
	mySize = 0;
}

//-- Definition of copy constructor
template <typename ElementType>
LinkedListWithDummy<ElementType>::LinkedListWithDummy(const LinkedListWithDummy &orig)
{
	ElementType g;
	myFirst = new Node(g);
	mySize = 0;
	if (!orig.isEmpty())
	{
		NodePtr origP = orig.myFirst->next;
		while (origP != NULL)
		{
			insertAtEnd(origP->data);
			origP = origP->next;
		}
	}
}

//--- Definition of class destructor
template <typename ElementType>
LinkedListWithDummy<ElementType>::~LinkedListWithDummy()
{
	while (myFirst != NULL)
	{
		Node *temp = myFirst->next;
		delete myFirst;
		myFirst = temp;
	}
}

//--- Definition of empty operation
template <typename ElementType>
bool LinkedListWithDummy<ElementType>::isEmpty() const
{
	return mySize == 0;
}

//--- Definition of size operation
template <typename ElementType>
int LinkedListWithDummy<ElementType>::size() const
{
	return mySize;
}

//--- Definition of display()
template <typename ElementType>
void LinkedListWithDummy<ElementType>::display(ostream &out) const
{
	if (!isEmpty())
	{
		NodePtr p = myFirst->next;
		while (p != NULL)
		{
			out << p->data;
			p = p->next;
		}
	}
	else
	{
		out << "Empty List.";
	}
}

//--- Definition of getDataAtPosition()
template <typename ElementType>
ElementType &LinkedListWithDummy<ElementType>::getDataAtPosition(int pos) const
{
	if (pos >= 0 && pos < mySize)
	{
		if (!isEmpty())
		{
			NodePtr p = myFirst;
			while (pos > 0)
			{
				p = p->next;
				pos--;
			}
			return p->next->data;
		}
	}
	ElementType g;
	return g;
}

//--- Definition of overloaded assignment operator
template <typename ElementType>
LinkedListWithDummy<ElementType> &LinkedListWithDummy<ElementType>::operator=(const LinkedListWithDummy &rhs)
{
	if (this != &rhs)
	{
		this->~LinkedListWithDummy();
		ElementType g;
		myFirst = new Node(g);
		mySize = 0;
		if (!rhs.isEmpty())
		{
			NodePtr rhsP = rhs.myFirst->next;
			while (rhsP != NULL)
			{
				insertAtEnd(rhsP->data);
				rhsP = rhsP->next;
			}
		}
	}
	return *this;
}

//--- Definition of removeAtPosition()
template <typename ElementType>
bool LinkedListWithDummy<ElementType>::removeAtPosition(int pos)
{
	if (pos < 0 || pos >= mySize)
	{
		return false;
	}
	if (isEmpty())
	{
		return false;
	}
	NodePtr p = myFirst;
	while (pos > 0)
	{
		p = p->next;
		pos--;
	}

	NodePtr temp = p->next;
	p->next = p->next->next;
	delete temp;
	mySize--;
	return true;
}

//--- Definition of insertAtEnd()
template <typename ElementType>
void LinkedListWithDummy<ElementType>::insertAtEnd(const ElementType &data)
{
	NodePtr newPtr = new Node(data);
	NodePtr current = myFirst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newPtr;
	mySize++;
}

/*------------------------------------------------------------------------
	Implementation of non-member functions
-------------------------------------------------------------------------*/

//--- Definition of overloaded output operator
template <typename ElementType>
ostream &operator<<(ostream &out, const LinkedListWithDummy<ElementType> &ref)
{
	ref.display(out);
	return out;
}

#endif
