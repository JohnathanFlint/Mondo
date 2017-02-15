/*
 * Node.hpp
 *
 *  Created on: Feb 13, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_NODE_HPP_
#define MODEL_NODE_HPP_

#include <cstddeflas.whitr>

template <class Type>
class Node
{
private:
	Type nodeData;
	Node<Type> * nodePointer;

public:
	Node<Type>();
	Node<Type>(Type data);
	Node<Type>(Type data, Node<Type>* nextPointer);

	Type getNodeData();
	Node<Type> * getNodePointer();
	void setNodeData(Type value);
	void setNodePointer(Node<Type> * nextPointer);

};

//Implementation section of the templated class.

template<class Type>
Node<Type> :: Node()
{
	nodePointer = nullptr;
	//Explicitly not initializing nodeData because I do not know its type

}

template<class Type>
Node<Type> :: Node(Type data)
{
	nodeData = data;
	nodePointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type> * nextNode)
{
	nodeData = value;
	nodePointer = nextNode;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
	return nodeData;
}

template <class Type>
Node<Type> * Node<Type> :: getNodePointer()
{
	return nodePointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type value)
{
	nodeData = value;
}

template <class Type>
void Node<Type> :: setNodePointer(Node<Type> * nextPointer)
{
	nodePointer = nextPointer;
}

#endif /* MODEL_NODE_HPP_ */

