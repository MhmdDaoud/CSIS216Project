#ifndef LIST
#define LIST

#include <iostream>
#include <cassert>

using namespace std;

template <typename ElementType>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &);
    ~DoublyLinkedList();
    DoublyLinkedList &operator=(const DoublyLinkedList &);

    bool isEmpty() const;
    void insertAtBeginning(const ElementType &);
    void insertAtEnd(const ElementType &);
    bool insertAtPosition(const ElementType &, int);
    void removeAtBeginning();
    void removeAtEnd();
    bool removeAtPosition(int);
    void display(ostream &) const;
    int size() const;
    bool contains(const ElementType &) const;
    int search(const ElementType &) const;
    ElementType getDataAtPosition(int pos) const;

protected:
    class DNode
    {
    public:
        DNode *next;
        DNode *prev;
        ElementType value;
        DNode(const ElementType &);
    };
    DNode *myFirst;
    int mySize;
};

//implementation

template <typename ElementType>
ElementType DoublyLinkedList<ElementType>::getDataAtPosition(int pos) const
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
template <typename ElementType>
DoublyLinkedList<ElementType>::DNode::DNode(const ElementType &value)
{
    this->value = value;
    next = NULL;
    prev = NULL;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList()
{
    myFirst = NULL;
    mySize = 0;
}

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

template <typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList()
{
    while (mySize > 0)
    {
        removeAtBeginning();
        mySize--;
    }
}

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

template <typename ElementType>
bool DoublyLinkedList<ElementType>::isEmpty() const
{
    return myFirst == NULL;
}

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

template <typename ElementType>
int DoublyLinkedList<ElementType>::size() const
{
    return mySize;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::removeAtBeginning()
{
    assert(!isEmpty());
    DNode *p = myFirst->next;
    delete myFirst;
    myFirst = p;
    mySize--;
}

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

template <typename ElementType>
ostream &operator<<(ostream &out, const DoublyLinkedList<ElementType> &ref)
{
    ref.display(out);
    return out;
}

#endif