/*
 * Animal.h
 *
 *  Created on: Feb 25, 2021
 *      Author: 1891467_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
using namespace std;


class Animal {
	private:
		string name;
		int trackNum;
	public:
		Animal();
		Animal(string name, int trackNum);
		virtual ~Animal();
		int getTrackNum();
		string getName();
		virtual string getType() = 0;
		virtual string getSubType() = 0;
		virtual int getEggs() = 0;
		virtual int getNurse() = 0;


};

#endif /* ANIMAL_H_ */


