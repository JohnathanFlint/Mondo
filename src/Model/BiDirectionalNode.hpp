/*
 * BiDirectionalNode.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_BIDIRECTIONALNODE_HPP_
#define MODEL_BIDIRECTIONALNODE_HPP_
template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
	Type Data;
	BiDirectionalNode<Type> * nextPointer;;
	BiDirectionalNode<Type> * previousPointer;

public:
	BiDirectionalNode();
	BiDirectionalNode(Type data)
	BiDirectionalNode(Type data, BiDirectionaNode<Type> * previous, BiDirectionalNode<Type> * next);

	Type getNodeData();
	BiDirectionalNode<Type> * getNextPointer();
	BiDirectionalNode<Type> * getPreviousPointer();

	void setNodeData(Type data);
	void setNexPointer(BiDirectionalnode<Type> * next);
	void setNextPointer(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node()
{

}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node(data)
{

}


#endif /* MODEL_BIDIRECTIONALNODE_HPP_ */
