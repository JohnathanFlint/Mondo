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
		insertMe->setRootPointer(previous);
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

template <class Type>
void BinarySearchTree<Type> :: remove(Type dieDieDie)
{
	if(root == nullptr)
	{
		cout << "Empty tree removal is impossible" << endl;
	}
	else
	{
		BinarySearchTreeNode<Type> * current = root;
		BinarySearchTreeNode<Type> * previous = nullptr;
		bool hasFound = false;

		while(current != nullptr && !hasFound)
		{
			if(current->getNodeData() == dieDieDie)
			{
				hasFound = true;
			}
			else
			{
				previous = current;
				if(dieDieDie < current->getNodeData())
				{
					current = current->getLeftChild();
				}
				else
				{
					current = current->getRightChild();
				}
			}
		}

		if(current == nullptr)
		{
			cerr << "Item not found removal unsuccessful" << endl;
		}
		else if(hasFound)
		{
			if(current == root)
			{
				removeNode(root);
			}
			else if(dieDieDie < previous->getNodeData())
			{
				removeNode(previous->getLeftChild());
			}
			else
			{
				removeNode(previous->getRightChild());
			}

		}
	}
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinarySearchTreeNode<Type> * & dieDie)
{
	BinarySearchTreeNode<Type> * current;
	BinarySearchTreeNod<Type> * previous;
	BinarySearchTreeNode<Type> * temp;

	previous = dieDie->getRootPointer();

	//Leaf with no child
	if(dieDie->getRightChild() == nullptr && dieDie->getLeftChild() == nullptr)
	{
		temp = dieDie;
		dieDie = nullptr;

		if(previous != nullptr && dieDie->getNodeData() < previous->getNodeData())
		{
			previous->setLeftChild(dieDie);
		}
		else if(previous != nullptr && dieDie->getNodeData() > previous->getNodeData())
		{
			previous->setRightChild(dieDie)
		}

		delete temp;
	}

	//has only left child
	else if(dieDie->getRightChild() == nullptr)
	{
		temp = dieDie;
		dieDie = dieDie->getLeftChild();

		if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
		{
			previous->setLeftChild(dieDie);
		}
		else if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
		{
			previous->setRightChild(dieDie);
		}

		dieDie->setRootPointer(previous);

		delete temp;
	}

	//has only right child
	else if(dieDie->getLeftChild() == nullptr)
	{
		temp = dieDie;
		dieDie = dieDie->getRightChild();

		if(previous != nullptr && dieDie->getNodeData() < previous->getNodeData())
		{
			previous->setLeftChild(dieDie);
		}
		else if(previous != nullptr && dieDie->getNodeData() > previous->getNodeData())
		{
			previous->setRightChild(dieDie);
		}

		dieDie->setRootPointer(previous);
		delete temp;
	}

	//has both children
	else
	{
		current = dieDie->getLeftChild();
		previous = nullptr;

		while(current->getRightChild() != nullptr)
		{
			previous = current;
			current = current->getRightChild();
		}

		dieDie->setNodeData(current->getNodeData());

		if(previous == nullptr)
		{
			dieDie->setLeftChild(current->getLeftChild());
			current->getLeftChild()->setRoot(dieDie);
		}
		else
		{
			previous->setRightChild(current->getLeftChild());
			current->getLeftChild()->detRootPointer(previous);
		}

		delete current;
	}
}

#endif /* MODEL_BINARYSEARCHTREE_H_ */
