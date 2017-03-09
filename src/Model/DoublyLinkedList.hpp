/*
 * DoublyLinkedList.hpp
 *
 *  Created on: Mar 9, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_DOUBLYLINKEDLIST_HPP_
#define MODEL_DOUBLYLINKEDLIST_HPP_

#include "BiDirectionalNode.hpp"

template <class Type>
class DoublyLinkedList
{
private:
    BiDirectionalNode<Type> * front;
    BiDirectionalNode<Type> * end;
    int size;
public:
    virtual void add(Type value) = 0;
    virtual Type remove(int index) = 0;
    DoublyLinkedList();
    virtual ~DoublyLinkedList();

    int getSize() const;
    BiDirectionalNode<Type> * getFront() const;
    BiDirectionalNode<Type> * getEnd() const;

    void setFront(BiDirectionalNode<Type> * front);
    void setSize(int updated);
    void setEnd(BiDirectionalNode<Type> * end);
};


template <class Type>
DoublyLinkedList<Type> :: DoublyLinkedList()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}

template <class Type>
DoublyLinkedList<Type> :: ~DoublyLinkedList()
{
    //Implemented only to avoid errors.
    //Just like a Java interface method.
}

template <class Type>
int DoublyLinkedList<Type> :: getSize() const
{
    return this->size;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getFront() const
{
    return this->front;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getEnd() const
{
    return this->end;
}

template <class Type>
void DoublyLinkedList<Type> :: setSize(int size)
{
    this->size = size;
}

template <class Type>
void DoublyLinkedList<Type> :: setFront(BiDirectionalNode<Type> * front)
{
    this->front = front;
}

template <class Type>
void DoublyLinkedList<Type> :: setEnd(BiDirectionalNode<Type> * end)
{
    this->end = end;
}
#endif /* DoublyLinkedList_h */











