/*
 * BinarySearchTreeNode.h
 *
 *  Created on: Apr 11, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_BINARYSEARCHTREENODE_H_
#define MODEL_BINARYSEARCHTREENODE_H_

#include "Node.hpp"

template <class Type>
class BinarySearchTreeNode
{
private:
	BinarySearchTreeNode<Type> * root;
	BinarySearchTreeNode<Type> * leftChild;
	BinarySearchTreeNode<Type> * rightChild;

public:
	BinarySearchTreeNode();
	c d bBinarySearchTreeNode(Type data);

	BinarySearchTreeNode<Type> * getRootPointer();
	BinarySearchTreeNode<Type> * getLeftChild();
	BinarySearchTreeNode<Type> * getRightChild();

	void setRootPointer(BinarySearchTreeNode<Type> * root);
	void setRootPointer(BinarySearchTreeNode<Type> * left);
	void setRootPointer(BinarySearchTreeNode<Type> * right);

};



#endif /* MODEL_BINARYSEARCHTREENODE_H_ */
