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
class DoubleList : public DoublyLinkedLiust<Type>
{
private:

public:
	doubleList();
	~DoubleList();
	void add(Type data);
	Type remove(int index);
	void addAtIndexFast(int index, Type value);
	void addAtIndex(int index, Type value);
	Type getFomrIndex(int index);
	Type getFromIndexFast(int index);
};

template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{

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
		for(int position = this->getSize() - 1; postion > index; position--)
		{
			reference = reference->getPreviousPointer();
		}
	}

	valueAtIndex = reference->getNodeData();
	return valueAtIndex;
}



#endif /* MODEL_DOUBLELIST_HPP_ */
