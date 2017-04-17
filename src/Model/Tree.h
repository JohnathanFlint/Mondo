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
public:
	//Traversals
	virtual void printToFile() = 0;
	virtual void inOrderTraversal() = 0;
	virtual void postOrderTraversal() = 0;
	virtual void preOrderTraversal() =  0;
	//Information Methods
	virtual int getHeight() = 0;
	virtual int getSize() = 0;
	virtual bool isComplete() = 0;
	virtual bool isBalanced() = 0;
	//Data Methods
	virtual bool contains(Type value) = 0;
	virtual void insert(Type toInsert) = 0;
	virtual void remove(Type value) = 0;

};


#endif /* MODEL_TREE_H_ */
