/*
 * StructureController.h
 *
 *  Created on: Feb 8, 2017
 *      Author: nwhi5696
 */

#ifndef CONTROLLER_STRUCTURECONTROLLER_H_
#define CONTROLLER_STRUCTURECONTROLLER_H_

#include"../Model/Node.hpp"
#include"../Model/Array.h"
#include "../Model/Timer.hpp"
#include "../Model/IntNodeArray.h"
#include "../Model/List"
#include "../Model/DoubleList.hpp"
#include "../Model/Stack.hpp"
#include "../Model/Queue.hpp"
#include "../Model/Meme.hpp"
#include <string>


using namespace std;

class StructureController
{
private:
	Node<int> numberNode;
	Node<string> wordNode;
	Array<int> numberArray;

	void testIntArray();
	void testNodeTypes();
	void testArrayTemplate();
	void testAdvancedFeatures();
	void testList();
	void testListTiming();
	void testMemeQueue();
	void testNumberStack();

public:
	StructureController();
	void start();
};

#endif /* CONTROLLER_STRUCTURECONTROLLER_H_ */
