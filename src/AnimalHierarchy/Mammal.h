/*
 * Mammal.h
 *
 *  Created on: Feb 25, 2021
 *      Author: 1891467_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

class Mammal: public Animal {
private:
	const string TYPE = "Mammal";
	int nurse;
public:
	Mammal();
	Mammal(string name, int trackNum, int nurse);
	virtual ~Mammal();
	string getType();
	int getEggs();
	int getNurse();
	virtual string getSubType() = 0;
};

#endif /* MAMMAL_H_ */
