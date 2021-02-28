/*
 * Oviparous.h
 *
 *  Created on: Feb 25, 2021
 *      Author: 1891467_snhu
 */

#ifndef OVIPAROUS_H
#define OVIPAROUS_H

#include "Animal.h"

class Oviparous: public Animal {
private:
	const string TYPE = "Oviparous";
	int numOfEggs;
public:
	Oviparous();
	Oviparous(string name, int taackNum, int numOfEggs);
	virtual ~Oviparous();
	string getType();
	int getEggs();
	int getNurse();
	virtual string getSubType() = 0;
};

#endif /* OVIPAROUS_H */
