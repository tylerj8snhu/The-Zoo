/*
 * Oviparous.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: 1891467_snhu
 */

#include "Oviparous.h"

Oviparous::Oviparous()
: Animal(){
	this->numOfEggs = 0;
}

Oviparous::Oviparous(string name, int trackNum, int numOfEggs)
	: Animal(name, trackNum) {
	this->numOfEggs = numOfEggs;
}

Oviparous::~Oviparous() {
	// TODO Auto-generated destructor stub
}

string Oviparous::getType() {
	return this->TYPE;
}

int Oviparous::getEggs() {
	return this->numOfEggs;
}
int Oviparous::getNurse() {
	return 0;
}



