/*
 * Tree.h
 *
 *  Created on: Apr 11, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_TREE_H_
#define MODEL_TREE_H_

#include <assert.h>

template <class Type>
class Tree
{
private:
	int height;
	int size;
	bool complete;
	bool balanced;

public:
	Tree();
	virtual ~Tree();
	virtual void printToFile() = 0;
	virtual void inOrderTraversal() = 0;
	virtual void postOrderTraversal() = 0;
	virtual void preOrderTraversal() =  0;

	int getHeight() const;
	int getSize() const;
	bool isComplete() const;
	bool isBalanced() const;

	void setHeight(int height);
	void setSize(int size);
	void setComplete(bool complet);
	void setBalanced(bool balanced);

};

template <class Type>
Tree <Type> :: Tree()
{
	height = 0;
	size = 0;
	balanced = false;
	complete = false;
}


template <class Type>
int Tree<Type> :: getHeight() const
{
	return this->height;
}

template <class Type>
int Tree<Type> :: getSize() const
{
	return this->size;
}

template <class Type>
bool Tree<Type> :: isComplete() const
{
	return this->complete;
}

template <class Type>
bool Tree<Type> :: isBalanced() const
{
	return this->balanced;
}

template <class Type>
void Tree<Type> :: setSize(int size)
{
	this->size = size;
}

template <class Type>
void Tree<Type> :: setHeight(int height)
{
	this->height = height;
}

template <class Type>
void Tree<Type> :: setComplete(bool complete)
{
	this->complete = complete;
}

template <class Type>
void Tree<Type> :: setBalanced(bool balanced)
{
	this->balanced = balanced;
}

#endif /* MODEL_TREE_H_ */
