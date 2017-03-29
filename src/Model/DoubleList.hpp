/*
 * DoubleList.hpp
 *
 *  Created on: Mar 3, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_DOUBLELIST_HPP_
#define MODEL_DOUBLELIST_HPP_

#include "DoublyLinkedList.hpp"

template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:

public:
	DoubleList();
	~DoubleList();
	void add(Type data);
	Type remove(int index);
	void addAtIndexFast(int index, Type value);
	void addAtIndex(int index, Type value);
	Type getFromIndex(int index);
	Type getFromIndexFast(int index);
	int indexOf(Type findMe);
	int nextIndexOf(Type item, int startpoint);
};

template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{

}

template <class Type>
DoubleList<Type> :: ~DoubleList()
{

}

template<class Type>
void DoubleList<Type> :: add(Type value)
{
	BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
	if(this->getSize() == 0)
	{
		this->setFront(addedNode);
	}
	else
	{
		this->getEnd()->setNextPointer(addedNode);
		addedNode->setPreviousPointer(this->getEnd());
	}

	this->setEnd(addedNode);
	this->setSize(this->getSize()+1);
}

template<class Type>
Type DoubleList<Type> :: remove(int index)
{
	Type derp;

	BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
	for(int spot = 0; spot < index; spot++)
	{
		nodeToTakeOut->getNextPointer();
	}

	derp = nodeToTakeOut->getNodeData();

	BiDirectionalNode<Type> * prev = nodeToTakeOut->getPreviousPointer();
	BiDirectionalNode<Type> * next = nodeToTakeOut->getNextPointer();

	prev->setNextPointer(next);
	next->setPreviousPointer(prev);

	delete nodeToTakeOut;

	this->setSize(this->getSize() - 1);
	return derp;
}

template <class Type>
Type DoubleList<Type> :: getFromIndex(int index)
{
	assert(index >= 0 && index < this->getSize());
	Type valueAtIndex;

	BiDirectionalNode<Type> * reference = this->getFront();
	for(int position = 0; position < index; position++)
	{
		reference = reference->getNextPointer();
	}
	valueAtIndex = reference->getNodeData();

	return valueAtIndex;
}

template <class Type>
Type DoubleList<Type> :: getFromIndexFast(int index)
{
	assert(index >= 0 && index < this->getSize());
	Type valueAtIndex;
	BiDirectionalNode<Type> * reference;

	if(index < this->getSize() / 2)
	{
		reference = this->getFront();
		for(int position = 0; position < index; position++)
		{
			reference = reference->getPreviousPointer();
		}
	}
	else
	{
		reference = this->getEnd();
		for(int position = this->getSize() - 1; position > index; position--)
		{
			reference = reference->getPreviousPointer();
		}
	}

	valueAtIndex = reference->getNodeData();
	return valueAtIndex;
}

template<class Type>
int DoubleList<Type> :: indexOf(Type findMe)
{
	int index = -1;

	BiDirectionalNode<Type> * searchPointer = this->getFront;

	for(int spot = 0; spot < this->getSize(); spot++)
		{
			if(findMe == searchPointer->getNodData())
				{
					return spot;
				}
			searchPointer = searchPointer->getNextPointer();
		}

	return index;
}

template <class Type>
int DoubleList<Type> :: nextIndexOf(Type value, int position)
{
	assert(position >= 0 && position < this->getSize());

	int nextIndex = -1;

	BiDirectionalNode<Type> * current = this->getFront();

	for(int index = 0; index < this->getSize(); index++)
	{
		if(index >= position)
		{
			if(current->getNodeData() == value)
				{
				return index;
				}
		}
		current = current->getNextPointer();
	}

	return nextIndex;
}



#endif /* MODEL_DOUBLELIST_HPP_ */
