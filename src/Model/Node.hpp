/*
 * Node.hpp
 *
 *  Created on: Feb 13, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_NODE_HPP_
#define MODEL_NODE_HPP_

template <class Type>
class Node
{
private:
	Type nodeData;
	Node<Type>* nodePointer;

public:
	Node<Type>();
	Node<Type>(Type data);
	Node<Type>(Type data, Node<Type>* nextPointer);

	Type getNodeData();
	Node<Type> * getNodePointer();
	void setNodeData(Type value);
	void setNodePointer(Node<Type> * nextPointer);

};



#endif /* MODEL_NODE_HPP_ */
