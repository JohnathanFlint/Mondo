/*
 * Stack.hpp
 *
 *  Created on: Mar 3, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_STACK_HPP_
#define MODEL_STACK_HPP_

#include "../Model/DoublyLinkedList.hpp"

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:

public:
	Stack();
	~Stack();
	void add(Type value);
	Type remove(int index);
	Type pop();
	Type peek();
	void push(Type data);
};

template<class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{

}


template<class Type>
Stack<Type> :: ~Stack()
{
	BiDirectionalNode<Type> * remove = this->getFront();

	while(this->getFront() != nullptr)
	{
		this->setFront(this->getFront()->getNextPointer());
		delete remove;
		remove = this->getFront();
	}
}
//the add method only adds to the end on a stack.
template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
	push(valueToAdd);
}
/*
adds the supplied value to the end of the stack.
Set new object to point to end.
Increases size by 1.
Change the end pointer to show the new end of the stack
*/
template <class Type>
void Stack<Type> :: push(Type addedThing)
{
	BiDirectionalNode<Type> * addToStack = new BiDirectionalNode<Type>(addedThing);

	if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
	{
		this->setFront(addToStack);
	}
	else
	{
		this->getEnd()->setNextPointer(addToStack);
		addToStack->setPreviousPointer(this->getEnd());
	}

	this->setEnd(addToStack);
	this->setSize(this->getSize() + 1);
}

template <class Type>
Type Stack<Type> :: remove(int index)
{
	assert(index == this->getSize() - 1 && this->getSize() >0);
	return pop();
}

template <class Type>
Type Stack<Type> :: peek()
{
	assert(this->getSize() > 0);
	return this->getEnd()->getNodeData();
}

template <class Type>
Type Stack<Type> :: pop()
{
	assert(this->getSize() > 0);
	Type removed = this->getEnd()->getNodeData();

	BiDirectionalNode<Type> * update = this->getEnd();
	update = update->getPreviousPointer();

	if(update != nullptr)
	{
		update->setNextPointer(nullptr);
	}

	delete this->getEnd();

	this->setEnd(update);

	this->setSize(this->getSize() - 1);

	return removed;
}

/*
 Adds the supplied object to the stack to the end.
 Set new object to point to end.

 Adjusts the end pointer to reflect the new end of the stack.
 Increases the size by 1.
*/




#endif /* MODEL_STACK_HPP_ */
