/*
 * Array.h
 *
 *  Created on: Feb 15, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_ARRAY_H_
#define MODEL_ARRAY_H_\

#include <assert.h>
#include "Node.hpp"

namespace std {

template <class Type>

class Array
{
public:
	Array<Type>();
	Array<Type>(int size);
	int getSize();
	Type getFromIndex(int index);
	void setAtIndex(int index, Type value);

private:
	Node<Type> * front;
	int size;

};

//Implementation Section

template <class Type>
Array<Type> :: Array()
{
	//Do not use! Implemented only for compilation
}

template <class Type>
Array<Type> :: Array(int size)
{
	assert(size > 0);
	this->size = size;

	this->front = new Node<Type>();

	for(int index = 1; index < size; index++)
	{
		Node<Type> * currentNode = new Node<Type>();
		currentNode->setNodePointer(front);
		front = currentNode;
	}
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
	{
		assert(index >= 0 && index < size);
		Type value;

		Node<Type> * current = front;

		for(int position = 0; position < index; position++)
		{
			current = current->getNodePointer();
		}

		value = current->getNodeData();
		return value;
	}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
		{
			assert(index >- 0 && index < size);
			Node<Type> * current = front;

			for(int position = 0; position < index; position++)
			{
				current = current->getNodePointer();
			}

			current->setNodeData(value);
		}

template <class Type>
int Array<Type> :: getSize()
{
	return size;
}

} /* namespace std */

#endif /* MODEL_ARRAY_H_ */
