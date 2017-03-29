/*
 * FileController.h
 *
 *  Created on: Mar 29, 2017
 *      Author: nwhi5696
 */

#ifndef CONTROLLER_FILECONTROLLER_H_
#define CONTROLLER_FILECONTROLLER_H_

#include "../Model/DoubleList.hpp"
#include "../Model/Meme.hpp"
//#include "../Model/CrimeData.hpp"
#include <String>
#include<fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileController
{
public:
	DoubleList<Meme> memeList;

private:
	DoubleList<Meme> readMemeDataFromFileAsList(string filename);
	void writeMemeDataStats(DoubleList<int> source, string filename);

};


#endif /* CONTROLLER_FILECONTROLLER_H_ */
