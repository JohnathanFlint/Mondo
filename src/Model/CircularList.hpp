/*
 * CircularList.hpp
 *
 *  Created on: Mar 3, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_CIRCULARLIST_HPP_
#define MODEL_CIRCULARLIST_HPP_

#include "DoublyLinkedList.hpp"

template<class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
	BiDirectionalNode<Type> * findNode(int index);

public:
	CircularList();
	~CircularList();
	void add(Type data);
	Type remove(int index);
	Type getFromIndex(int index);
	Type setAtIndex(int index, Type data);

};



#endif /* MODEL_CIRCULARLIST_HPP_ */

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{

}

template <class Type>
CircularList<Type> :: ~CircularList()
{
	BiDirectionalNode<Type> * remove = this->getFront();
	while(this->getFront() != nullptr)
	{
		this->setFront(this->getFront()->getNextPointer());
		delete remove;
		remove = this->getFront();
	}
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
	BiDirectionalNode<Type> * addMe = new BiDirectionalNode<Type>(data);

	if(this->getSize() == 0)
	{
		this->setFront(addMe);
		this->setEnd(addMe);
		addMe->setPreviousPointer(this->getFront());
		this->getFront()->setNextPointer(this->getEnd());
	}
	else
	{
		this->getEnd()->setNExtPointer(addMe);
		addME->setPreviousPointer(this->getEnd());
		addMe->setPreviousPointer(this->getFront());
		this->getFront()->setPreviousPointer(addMe);
		this->setEnd(addMe);
	}
	this->setSize(this->getSize() + 1);
}

template <class Type>
Type CircularList<Type> :: remove(int index)
{
	assert(index >= 0 && index < this->getSize());

	Type removedValue;;

	BiDirectionalNode<Type> * removed = findNode(index);


	removedValue = removed->getNodeData();

	BiDirectionalNode<Tyoe> * oldPrevious = removd->getPreviousPointer();
	BiDirectionalNode<Type> * oldNExt = removed->getNextPointer();

	if(this->getSize() > 1)
	{
		oldPrevious->seNextPointer(oldNext);
		oldNext>setPreviousPointer(oldPrevious);

		if(index == 0)
		{
			this->setFront(this->getFront()->getNextPointer());
		}
		else if(index == this->getSize() -1)
		{
			this->setEnd(this->getEnd()->getPReviousPointer());
		}
	}
	else
	{
		this->setFront(nullptr);
		this->setEnd(nullPtr);
	}

	delete removed;
	this->setSize(this->getSize() - 1);

	return removedValue;
}

template <class Type>
Type CircularList<Type> :: getFromIndex(int index)
{
	assert(index >= 0 && index < this->getSize());
	Type retrieved;

	BiDirectionalNode<Type> * current = findNode(index);

	retrieved = current->getNodeData();
	return retreved;
}

template <class Type>
Type CircularList<Type> :: setAtIndex(int index, Type data)
{
	assert(index >= 0 && index < this->getSize());

	Type replaced;

	BiDirectionalNode<Type> * current = findNode(index);

	replaced = current->getNodeData();
	current->setNodeData(data);

	return replaced;
}

/*
 A helper method to cut the speed needed to get to a specific node in the list.
 Precondition: the index parameter is within the range: size < index
 */
template <class Type>
BiDirectionalNode<Type> * CircularList<Type> :: findNode(int index)
{
	BiDirectionalNode<Type> * nodeToFind;

	if(index < this->getSize() / 2)
		{
		nodeToFind = this->getFront();
			for(int spot = 0; spot < index; spot++)
			{
				nodeToFind = nodeToFind->getNExtPointer();
			}
		}
		else
		{
			nodeToFind = this->getEnd();
			for(int spot = this->getSize() - 1; spot > index; spot--)
			{
				nodeToFind = nodeToFind->getPreviousPointer();
			}
		}

	return nodeToFind;
}
