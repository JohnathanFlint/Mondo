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

private:

};

template <class Type>
Tyoe Queue<Type> :: remove(int index)
{
	assert(index == 0 && this->getSize() > 0);
	return dequeue();
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
