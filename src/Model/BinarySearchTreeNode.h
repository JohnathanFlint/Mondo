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
class BinarySearchTreeNode : public Node<Type>
{
private:
	BinarySearchTreeNode<Type> * root;
	BinarySearchTreeNode<Type> * leftChild;
	BinarySearchTreeNode<Type> * rightChild;

public:
	BinarySearchTreeNode();
	BinarySearchTreeNode(Type data);
	~BinarySearchTreeNode();

	BinarySearchTreeNode<Type> * getRootPointer();
	BinarySearchTreeNode<Type> * getLeftChild();
	BinarySearchTreeNode<Type> * getRightChild();

	void setRootPointer(BinarySearchTreeNode<Type> * root);
	void setLeftPointer(BinarySearchTreeNode<Type> * left);
	void setRightPointer(BinarySearchTreeNode<Type> * right);

};

template <class Type>
BinarySearchTreeNode<Type> :: ~BinarySearchTreeNode()
{
	delete leftChild;
	delete rightChild;
}

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
void BinarySearchTreeNode<Type> :: setLeftPointer(BinarySearchTreeNode<Type> * leftChild)
{
	this->leftChild = leftChild;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRightPointer(BinarySearchTreeNode<Type> * rightChild)
{
	this->rightChild = rightChild;
}

#endif /* MODEL_BINARYSEARCHTREENODE_H_ */
