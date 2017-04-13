/*
 * BinarySearchTree.h
 *
 *  Created on: Apr 11, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_BINARYSEARCHTREE_H_
#define MODEL_BINARYSEARCHTREE_H_

#include "Tree.h"
#include "BinarySearchTreeNode.h"

template <class Type>
class BinarySearchTree : public Tree<Type>
{
private:
	BinarySearchTreeNode<TYpe> * root;
	int calculateSize(BinarySearchTreeNode<Type> * root);
	void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
	void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
	void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);

	void removeNode(BinarySearchTreeNode<Type> * root);

public:
	BinarySearchTree();
	~BinarySearchTree();

	BinarySearchTreeNode<Type> * getRoot();
	void setRoot(BinarySearchTreeNode<Type> * root);

	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

	void printToFile();

	bool contains(Type value);
	void insert(Type toBeInserted);
	void remove(Type value);

};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
	this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
	this->root = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
	return this->root;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
	this->root = root;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{

}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{

}
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{

}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
	return -99;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{

}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{

}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{

}

template <class Type>
void BinarySearchTree<Type> :: insert(Type toBeInserted)
{
	BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
	BinarySearchTreeNode<Type> * previous = nullptr;
	BinarySearchTreeNode<Type> * current = root;

	if(current == nullptr)
	{
		root = insertMe;
	}
	else
	{
		while(current !=nullptr)
		{
			previous = current;
			if(toBeInserted < current->getNodeData())
			{
				current = current->getLeftChild();
			}
			else if(toBeInserted > current->getNodeData())
			{
				current = current->getRightChild();
			}
			else
			{
				cerr << "Item exists already - Exiting" << endl;
				delete insertMe;
				return;
			}
		}

		if(previous->getNodeData() > toBeInserted)
		{
			previous->setLeftChild(insertMe);
		}
		else
		{
			previous->setRightChild(insertMe);
		}
		insertMe->setRoot(previous);
	}
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type toFind)
{
	BinarySearchTreeNode<Type> * current = root;

	if(current == nullptr)
	{
		return false;
	}
	else
	{
		while(current != nullptr)
		{
			if(toFind == current->getNodeData())
			{
				return true;
			}
			else if(toFind < current->getNodeData())
			{
				current = current->getLeftChild();
			}
			else

			{
				current = current->getRightChild();
			}
			return false;
		}
	}
}

#endif /* MODEL_BINARYSEARCHTREE_H_ */
