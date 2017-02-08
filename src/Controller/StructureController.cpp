/*
 * StructureController.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: nwhi5696
 */

#include "StructureController.h"
#include <iostream>
#include "../Model/IntNodeArray.h"


using namespace std;

StructureController::StructureController()
{

}

void StructureController :: testIntArray()
{
	cout << "Creating an IntNodeArray" << endl;
	IntNodeArray temp = IntNodeArray(3);

	for(int spot = 0; spot < 3; spot++)
	{
		cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}
}

void StructureController :: start()
{
	cout << "Going to test the IntNodeArray" << endl;
	testIntArray();
	cout << "Finished IntArrayNode testing" << endl;
}


