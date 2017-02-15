/*
 * StructureController.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: nwhi5696
 */

#include "StructureController.h"
#include <iostream>
#include "../Model/IntNodeArray.h"
#include "../Model/Timer.hpp"


using namespace std;

StructureController::StructureController()
{
	wordNode = Node<string>();
	numberNode = Node<int>();
	numberArray = Array<int>(1);
}

void StructureController :: testNodeTypes()
{
	cout << "Here is a string node" << endl;
	cout << wordNode.getNodeData() << endl;
	cout << "Here is an uninitialized int node" << endl;
	cout << numberNode.getNodeData() << endl;
}

void StructureController :: testArrayTemplate()
{
	cout << "Array Template" << endl;
	Timer arrayTimer;
	arrayTimer.startTimer();
	int test [9];
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();
	arrayTimer.resetTimer();

	arrayTimer.startTimer();
	numberArray = Array<int>(9);
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();

}

void StructureController :: testIntArray()
{
	cout << "Creating an IntNodeArray" << endl;
	IntNodeArray temp = IntNodeArray(3);

	for(int spot = 0; spot < 3; spot++)
	{
		cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}

	for(int spot = 0; spot < 3; spot++)
	{
		temp.setAtIndex(spot, spot);
	}

	for(int spot = 0; spot < temp.getSize(); spot ++)
	{
		cout << temp.getFromIndex(spot) <<" is at " << spot << endl;
	}
}

void StructureController :: start()
{
	cout << "Going to test the IntNodeArray" << endl;
	testIntArray();
	cout << "Finished IntArrayNode testing" << endl;

	testArrayTemplate();
}


