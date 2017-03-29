/*
 * FileController.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: nwhi5696
 */

#include "FileController.h"

using namespace std;

/*
 filename is an absolute path
 */

DoubleList<Meme> FileController :: readMemeDataFromFileAsList(string filename)
{
	DoubleList<Meme> dataSource;
	string currentCSVLine;
	int rowCount = 0;

	ifstream dataFile(filename);

	if(dataFile.is_open())
	{
		while(!dataFile.eof())
		{
			getline(dataFile, currentCSVLine, '\r');
			stringstream parseCSV(currentCSVLine);

			string title, tempHipster, tempDank, tempMainstream;
			//Matching data types from structures
			double quotient;
			int dankness;
			bool isCommon;

			getline(parseCSV, title, ',');
			getline(parseCSV, tempHipster, ',');
			getline(parseCSV, tempDank, ',');
			getline(parseCSV, tempMainstream, ',');

			if (rowCount != 0)
			{
				quotient =stod(tempHipster);
				dankness = stoi(tempDank);
				isCommon = stoi(tempMainstream);

				Meme temp(title);
				temp.setHipsterQuotient(quotient);
				temp.setDankness(dankness);
				temp.setMainstream(isCommon);

				dataSource.add(temp);
			}
//			rowCount++;
			//remove this line
			cout << currentCSVLine << endl
		}
		dataFile.close();
	}
	else
	{
		cerr << "No File" << endl;
	}

	return dataSource;
}

