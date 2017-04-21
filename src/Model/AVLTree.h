/*
 * AVLTree.h
 *
 *  Created on: Apr 19, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_AVLTREE_H_
#define MODEL_AVLTREE_H_

#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

template<class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
	BinarySearchTreeNode<Type> * leftRotation(BinarySearchTreeNode<Type> * parent);
	BinarySearchTreeNode<Type> * rightRotation(BinarySearchTreeNode<Type> * parent);
	BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
	BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);

	BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent);

	BinarySearchTreeNode<Type> * insertedNode(BinarySearchTreeNode<Type> * parent, Type value);
	BinarySearchTreeNode<Type> * removenode(BinarySearchTreeNode<Type> * parent, Type value);

	int heightDifference(BinarySearchTreeNode<Type> * parent);

public:
	AVLTree();
	~AVLTree();

	void insert(Type toInsert);
	void remove(Type value);

};

// A negative value means the right is greater than the left
template <class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeNode<Type> * node)
{
	int balance;
	int leftHeight = calculateHeight(node->getLeftChild());
	int rightHeight = calculateHeight(node->getRightChild());
	balance = leftHeight - rightHeight;
	return balance;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation(BinarySearchTreeNode<Type> * parent)
{
	BinarySearchTreeNode<Type> * changedNode;
	changedNode = parent->getLeftChild();

	parent->setLeftChild(changedNode->getRightChild());
	changedNode->setRightChild(parent);

	return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation(BinarySearchTreeNode<Type> * parent)
{
	BinarySearchTreeNode<Type> * changedNode;;
	changedNode = parent->getRightChild();

	parent->setRightChild(changedNode->getLeftChild());

	changedNode->setLeftChild(parent);

	return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinarySearchTreeNode<Type> * parent)
{
	BinarySearchTreeNode<Type> * changedNode;
	changedNode = parent->getRightChild();

	parent->setRightChild(leftRotation(changedNode));

	return rightRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinarySearchTreeNode<Type> * parent)
{
	BinarySearchTreeNode<Type> * changedNode;
	changedNode = parent->getLeftChild();

	parent->setLeftChild(rightRotation(changedNode));

	return leftRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinarySearchTreeNode<Type> * parent)
{
	int balanceFactor = heightDifference(parent);

	if(balanceFactor > 1)
	{
		if(heightDifference(parent->getLeftChild()) > 0)
		{
			parent = leftRotation(parent);
		}
		else
		{
			parent = leftRightRotation(parent);
		}
	}
	else if(balanceFactor < -1)
	{
		if(heightDifference(parent->getRightChild()) > 0)
		{
			parent  rightLeftRotation(parent);
		}
		else
		{
			parent = rightRotation(parent);
		}
	}

	return parent;
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
	this->root = nullptr;
}

template <class Type>
AVLTree<Type> :: ~AVLTree() : BinarySearchTree<Type>()
{
	delete this->getRoot();
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: removeNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{

}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: insertNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{
	if(parent == nullptr)
	{
		parent = new BnarySearchTreeNode<Type>(inserted);
		return parent;
	}
	else if(inserted < parent->getNodeData())
	{
		parent->setLeftChild(insertedNode(parent->getLeftChild(), inserted));
		parent = balanceSubtree(parent);
	}
	else if(inserted > parent->getNodeData())
	{
		parent->setRightChild(insertedNode(parent->getRightChild(), inserted));
		parent = balanceSubTree(parent);
	}

	return parent;

}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
	insertNode(this->getRoot(), item);
}

#endif /* MODEL_AVLTREE_H_ */
