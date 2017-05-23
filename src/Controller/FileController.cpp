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
			cout << currentCSVLine << endl;
		}
		dataFile.close();
	}
	else
	{
		cerr << "No File" << endl;
	}

	return dataSource;
}

void FileController :: writeMemeDataStats(DoubleList<Meme> dataSource, string filename)
{
	ofstream saveFile(filename);

	if(saveFile.is_open())
	{
		saveFile << "These are the contents of the list" << endl;
		for(int index = 0; index < dataSource.getSize(); index++)
		{
			saveFile << "Meme Title: " << dataSource.getFromIndex(index).getTitle() << endl;
		}
	}
	else
	{
		cerr << "File unavailabel" << endl;
	}
	saveFile.close();
}

AVLTree<CrimeData> FileController :: readCrimeDataToAVLTree(string filename)

{

    AVLTree<CrimeData> crimeData;



    string currentCSVLine;

    int rowCount = 0;



    ifstream dataFile(filename);



    if(dataFile.is_open())

    {

        while(!dataFile.eof())

        {

            getline(dataFile, currentCSVLine, '\r');



            //Exclude first row headers

            if (rowCount != 0)

            {

                CrimeData rowData(currentCSVLine);

                crimeData.insert(rowData);

            }

            rowCount++;

        }

        dataFile.close();

    }

    else

    {

        cerr << "NO FILE" << endl;

    }



    return crimeData;

}

BinarySearchTree<CrimeData> FileController :: readCrimeDataToBinarySearchTree(string filename)

{

    BinarySearchTree<CrimeData> crimeData;



    string currentCSVLine;

    int rowCount = 0;



    ifstream dataFile(filename);



    if(dataFile.is_open())

    {

        while(!dataFile.eof())

        {

            getline(dataFile, currentCSVLine, '\r');



            //Exclude first row headers

            if (rowCount != 0)

            {

                CrimeData rowData(currentCSVLine);

                crimeData.insert(rowData);

            }

            rowCount++;

        }

        dataFile.close();

    }

    else

    {

        cerr << "NO FILE" << endl;

    }





    return crimeData;

}



