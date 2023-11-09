#ifndef LINKEDLISTWITHDUMMY_H
#define LINKEDLISTWITHDUMMY_H

#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

template<typename ElementType>
class LinkedListWithDummy {
public:
    LinkedListWithDummy();

    ~LinkedListWithDummy();

    LinkedListWithDummy(const LinkedListWithDummy &);

    bool isEmpty() const;

    void display(ostream &) const;

    int size() const;

    void insertAtEnd(const ElementType &);

    bool removeAtPosition(int);

    ElementType getDataAtPosition(int) const;

    LinkedListWithDummy &operator=(const LinkedListWithDummy &);

protected:
    class Node {
    public:
        ElementType data;
        Node *next;

        Node(const ElementType &n) : data(n), next(NULL) {}
    };

    typedef Node *NodePtr;
    NodePtr myFirst;
    int mySize;
};

//implementation

template<typename ElementType>
LinkedListWithDummy<ElementType>::LinkedListWithDummy() {
    ElementType g;
    myFirst = new Node(g);
    mySize = 0;
}

template<typename ElementType>
LinkedListWithDummy<ElementType>::~LinkedListWithDummy() {
    while (myFirst != NULL) {
        Node *temp = myFirst->next;
        delete myFirst;
        myFirst = temp;
    }
}

template<typename ElementType>
LinkedListWithDummy<ElementType>::LinkedListWithDummy(const LinkedListWithDummy &orig) {
    ElementType g;
    myFirst = new Node(g);
    mySize = 0;
    if (!orig.isEmpty()) {
        NodePtr origP = orig.myFirst->next;
        while (origP != NULL) {
            insertAtEnd(origP->data);
            origP = origP->next;
        }
    }
}

template<typename ElementType>
bool LinkedListWithDummy<ElementType>::isEmpty() const {
    return myFirst->next == NULL;
}

template<typename ElementType>
int LinkedListWithDummy<ElementType>::size() const {
    return mySize;
}

template<typename ElementType>
void LinkedListWithDummy<ElementType>::display(ostream &out) const {
    if (!isEmpty()) {
        NodePtr p = myFirst->next;
        while (p != NULL) {
            out << p->data;
            p = p->next;
        }
    } else {
        out << "Empty List.";
    }
};

template<typename ElementType>
ElementType LinkedListWithDummy<ElementType>::getDataAtPosition(int pos) const {
    if (pos >= 0 && pos < mySize) {
        if (!isEmpty()) {
            NodePtr p = myFirst;
            while (pos > 0) {
                p = p->next;
                pos--;
            }
            return p->next->data;
        }
    }
    ElementType g;
    return g;
}

template<typename ElementType>
LinkedListWithDummy<ElementType> &LinkedListWithDummy<ElementType>::operator=(const LinkedListWithDummy &rhs) {
    if (this != &rhs) {
        this->~LinkedListWithDummy();
        ElementType g;
        myFirst = new Node(g);
        mySize = 0;
        if (!rhs.isEmpty()) {
            NodePtr rhsP = rhs.myFirst->next;
            while (rhsP != NULL) {
                insertAtEnd(rhsP->data);
                rhsP = rhsP->next;
            }
        }
    }
    return *this;
}

template<typename ElementType>
bool LinkedListWithDummy<ElementType>::removeAtPosition(int pos) {
    if (pos < 0 || pos >= mySize) {
        return false;
    }
    if (isEmpty()) {
        return false;
    }
    NodePtr p = myFirst;
    while (pos > 0) {
        p = p->next;
        pos--;
    }

    NodePtr temp = p->next;
    p->next = p->next->next;
    delete temp;
    mySize--;
    return true;
}

template<typename ElementType>
void LinkedListWithDummy<ElementType>::insertAtEnd(const ElementType &data) {
    NodePtr newNode = new Node(data);
    NodePtr current = myFirst;
    while (current != NULL) {
        if (current->next == NULL)
            break;
        current = current->next;
    }
    current->next = newNode;
    mySize++;
}

template<typename ElementType>
ostream &operator<<(ostream &out, const LinkedListWithDummy<ElementType> &ref) {
    ref.display(out);
    return out;
}

#endif
