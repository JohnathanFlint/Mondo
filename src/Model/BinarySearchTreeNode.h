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
	BinarySearchTreeNode(Type data);

	BinarySearchTreeNode<Type> * getRootPointer();
	BinarySearchTreeNode<Type> * getLeftChild();
	BinarySearchTreeNode<Type> * getRightChild();

	void setRootPointer(BinarySearchTreeNode<Type> * root);
	void setRootPointer(BinarySearchTreeNode<Type> * left);
	void setRootPointer(BinarySearchTreeNode<Type> * right);

};

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode()
{
		this->root = nullptr;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode(Type data) : Node<Type>(data)
{
	this->root = nullptr;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRootPointer()
{
	return this->root;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getLeftChild()
{
	return this->leftChild;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRightChild()
{
	return this->rightChild;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type> * root)
{
	this->root = root;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type> * leftChild)
{
	this->leftChild = leftChild;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type> * rightChild)
{
	this->root = rightChild;
}

#endif /* MODEL_BINARYSEARCHTREENODE_H_ */
