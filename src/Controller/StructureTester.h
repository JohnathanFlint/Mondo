/*
 * StructureTester.h
 *
 *  Created on: Apr 17, 2017
 *      Author: nwhi5696
 */

#ifndef CONTROLLER_STRUCTURETESTER_H_
#define CONTROLLER_STRUCTURETESTER_H_

#include "../Model/BinarySearchTree.h"

namespace std
{

class StructureTester
{
public:
	StructureTester();
	virtual ~StructureTester();
	void testBinarySearchTreeOperations();
	void testBinarySearchData();
	void testAVLTreeOperations();
	void testAVLData();
};

}

#endif /* CONTROLLER_STRUCTURETESTER_H_ */
