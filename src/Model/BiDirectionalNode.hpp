/*
 * BiDirectionalNode.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_BIDIRECTIONALNODE_HPP_
#define MODEL_BIDIRECTIONALNODE_HPP_

#include "../Model/Node.hpp"

template <class Type>
class BiDirectionalNode : Node<Type>
{
	private:
	Type Data;
	BiDirectionalNode<Type> * nextPointer;;
	BiDirectionalNode<Type> * previousPointer;

public:
	BiDirectionalNode();
	BiDirectionalNode(Type data);
	BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);

	Type getNodeData();
	BiDirectionalNode<Type> * getNextPointer();
	BiDirectionalNode<Type> * getPreviousPointer();

	void setNodeData(Type data);
	void setNextPointer(BiDirectionalNode<Type> * next);
	void setPreviousPointer(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>()
{
	this->previousPointer = nullptr;
	this->nextPointer = nullptr;

}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node<Type>(data)
{
	this->previousPointer = nullptr;
	this->nextPointer = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) : Node<Type>(data, next)
{
this->previousPointer = previous;
this->nextPointer = next;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getPreviousPointer()
{
	return this->previousPointer;
}

template <class Type>
void BiDirectionalNode<Type> :: setNextPointer(BiDirectionalNode<Type> * next)
{
	this->nextPointer = next;
}

template<class Type>
void BiDirectionalNode<Type> :: setPreviousPointer(BiDirectionalNode<Type> * previous)
{
	this->previous = previous;
}


#endif /* MODEL_BIDIRECTIONALNODE_HPP_ */
