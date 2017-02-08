/*
 * IntNodeArray.h
 *
 *  Created on: Feb 8, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_INTNODEARRAY_H_
#define MODEL_INTNODEARRAY_H_

#include "IntNode.hpp"

class IntNodeArray
{

private:
	IntNode * head;
	int size;
public:
	IntNodeArray(int bigness);
	int getSize();
	int getFromIndex(int index);
	void setAtIndex(int index, int value);

};

#endif /* MODEL_INTNODEARRAY_H_ */
