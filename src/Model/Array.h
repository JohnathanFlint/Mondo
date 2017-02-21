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
# include <iostream>

namespace std {

template <class Type>

class Array
{
public:
	//constructors
	Array<Type>();
	Array<Type>(int size);

	//destructor
	~Array<Type>();

	//copy constructor
	Array<Type>(const Array<Type> & toBeCopied);
	//assignment operator overload


	//Methods
	int getSize() const;
	Node<Type> * getFront() const;
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
			assert(index >= 0 && index < size);
			Node<Type> * current = front;

			for(int position = 0; position < index; position++)
			{
				current = current->getNodePointer();
			}

			current->setNodeData(value);
		}

template <class Type>
int Array<Type> :: getSize() const
{
	return size;
}

template <class Type>
Node<Type> * Array<Type> :: getFront() const
{
	return front;
}

template <class Type>
Array<Type> :: ~Array()
{
	int count = size;
	Node<Type> * remove = front;
	while (front != nullptr)
	{
		//move to next node in array
		front = front->getNodePointer();
		cout << "Moving to the next node. At: " << count << endl;
		// delete the front pointer
		delete remove;
		cout << "Deleting the old front pointer." << endl;
		//move delete to the new front
		remove = front;
		cout << "Moving to new front pointer." << endl;
		count--;
		cout << "Front is at: " << front << "count is: " << count << endl;
	}
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
	this->size = toBeCopied.getSize();

	//build data structure
	this->front = new Node<Type>();
	for(int index = 1; index < size; index++)
	{
		Node<Type> * temp = new Node<Type>();
		temp->setNodePointer(front);
		front = temp;
	}

	Node<Type> * copyTemp = toBeCopied.getFront();
	Node<Type> * updated = this->front;
	for(int index = 0; index < size; index++)
	{
		updated->setNodeData(copyTemp->getNodeData());
		updated = updated->getNodePointer();
		copyTemp = copyTemp->getNodePointer();
	}

}

} /* namespace std */

#endif /* MODEL_ARRAY_H_ */
