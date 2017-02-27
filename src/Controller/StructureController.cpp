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
#include "../Model/Array.h"
#include "../Model/List"

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

void StructureController :: testAdvancedFeatures()
{
	int showDestructor = 0;

	if(showDestructor < 1)
	{
		Array<string> words = Array<string>(4);
		words.setAtIndex(0,"at zero");
		words.setAtIndex(3, "in the last spot");
		Array<string> copiedWords = Array<string>(words);
		cout << "These should match: " << endl;
		cout << words.getFromIndex(0) << "s should be same as " << copiedWords.getFromIndex(0) << endl;

		copiedWords.setAtIndex(3, "changed the contents of the copied Array");
	}
}

void StructureController :: testList()
{
	List<int> sample;
	sample.addFront(2);
	sample.addEnd(3);
	sample.addFront(3);
	cout << "This should be 1, 2, 3" << endl;

	for(int index = 1; index < sample.getSize(); index++)
	{
		cout << sample.getFromIndex(index) << endl;
	}
}

void StructureController :: start()
{
	cout << "Going to test the IntNodeArray" << endl;
	testIntArray();
	cout << "Finished IntArrayNode testing" << endl;

	testArrayTemplate();
	testAdvancedFeatures();
}




