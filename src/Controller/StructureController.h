/*
 * StructureController.h
 *
 *  Created on: Feb 8, 2017
 *      Author: nwhi5696
 */

#ifndef CONTROLLER_STRUCTURECONTROLLER_H_
#define CONTROLLER_STRUCTURECONTROLLER_H_

#include"../Model/Node.hpp"
#include <string>

using namespace std;

class StructureController {
private:
	Node<int> numberNode;
	Node<string> wordNode;
	void testIntArray();
	void testNodeTypes();

public:
	StructureController();
	void start();
};

#endif /* CONTROLLER_STRUCTURECONTROLLER_H_ */
