/*
 * Meme.hppnonnnnnnjhvgcjfxxfdxdxhdhfdhfdzxhhdzxhdzfhdzxfdxfdxfdxzhfdxzhfdxzfdzfdszszdfzdszsdzzzzzzzzzzzzzzzzzzzzzzzzzzzzzdfhdzhjteedzjhtezd
 *
 *  Created on: Mar 13, 2017
 *      Author: nwhi5696
 */

#ifndef MODEL_MEME_HPP_
#define MODEL_MEME_HPP_

#include <string>

using namespace std;

class Meme
{
private:
	string title;
	int dankness;
	double hipsterQuotient;
	bool mainstream;

public:
	Meme();
	Meme(string title);
	int getDankness();
	double getHipsterQuotient();
	bool isMainstream();
	string getTitle();
	void setTitle(string title);
	void setDankness(int dank);
	void setHipsterQuotient(double hipsterQuotient);
	void setMainstream(bool mainstream);
	bool operator > ( Meme & compared);
	bool operator == ( Meme & compared);
	bool operator < ( Meme & compared);
};



#endif /* MODEL_MEME_HPP_ */
