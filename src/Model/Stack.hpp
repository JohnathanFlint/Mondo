/*
 * Stack.hpp
 *
 *  Created on: Mar 3, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_STACK_HPP_
#define MODEL_STACK_HPP_

#include "DoubleLinkedList.hpp"

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:

public:
	Stack();
	~Stack();
	void add(Type value);
	Type ramove(int index);
	Type pop();
	Type peek();
	void push(Type data);
};
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
	BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);

	if(this->size == 0 || this->front == nullptr || or this->end == nullptr)
	{
		this->front = addToStack;
		this->end = addToStack;
	}
	else
	{
		this->end->setNextPointer(addToStack);
		addToStack->setPreviousPointer(this->end);
	}

	this->end = addToStack;
	this->size++;
}



#endif /* MODEL_STACK_HPP_ */
