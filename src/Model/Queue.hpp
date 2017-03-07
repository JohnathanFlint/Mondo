/*
 * Queue
 *
 *  Created on: Mar 3, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_QUEUE_HPP_
#define MODEL_QUEUE_HPP_

#include "DoublyLinkedList"

template <class Type>
class Queue : public DoublyLinkedList<Type>
{
public:
	Queue();
	~Queue();
	void add(Type data);
	Type remove(int index);
	void enqueue(Type Data);
	Type dequeue();
	Type peek();

private:

};

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList<Type>()
{

}

/*
 destructor as list, array, stack... since it is a linear data structure.
 */
template<class Type>
Queue<Type> :: ~Queue()
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
void Queue<Type> :: add(Type value)
{
	enqueue(value);
}

template <class Type>
Type Queue<Type> :: remove(int index)
{
	assert(index == 0 && this->getSize() > 0);
	return dequeue();
}

/*
 1. create a node pointer
 2. if size == 0, adjust front to point to the new node
 3. else, set new node to ends next, connect new nodes to previous end
 4. move end to the new node
 5. adjust size + 1
 */
template <class Type>
void Queue<Type> :: enqueue(Type data)
{
	BiDirectionalNode<Type> * added = new BiDirectionalNode<Type>(insertedValue);

	if(this->getSize == 0 || this->getFront() == nullptr || this-getEnd() == nullptr)
	{
		this->setFront(added);
	}
	else
	{
		this->getEnd()->setNextPointer(added);
		added->setPreviousPointer(this->getEnd());
	}

	this->setEnd(added);
	this->setSize(this->getSize() + 1);
}

/*
 1. Assert size is valid.
 2. Get data from front node.
 3. if size == 1, set end to nullptr
 4. else, move front to fronts next
 5. Set fronts previous to nullptr
 6. delete old front node
 7. adjust size down 1
 8. return old value
 */
template <class Type>
Type Queue<Type> :: dequeue()
{
	assert(this->getSize() > 0);

	Type removedValue = this->getFront()->getNodeData();
	BiDirectionalNode<Type> * removeMe = this->getFront();

	if(this->getSize() == 1)
	{
		this->setEnd(nullptr);
		tyhis->setFront(nullptr);
	}
	else
	{
		this->setFront(removeMe->getNextPointer());
	}
	this->setFront()->setPreviousPointer(nullptr);

	delete removeMe;
	this->setSize(this->getSize() - 1);

	return removedValue
}

template <class Type>
Type Queue<Type> :: peak()
{
	assert(this->getSize() > 0);

	return this-getFront()->getNodeData();
}



#endif /* MODEL_QUEUE_HPP_ */
