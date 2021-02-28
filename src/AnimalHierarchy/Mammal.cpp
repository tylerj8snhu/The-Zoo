/*
 * Mammal.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: 1891467_snhu
 */

#include "Mammal.h"

Mammal::Mammal()
: Animal(){
	this->nurse = 0;
}

Mammal::Mammal(string name, int trackNum, int nurse)
: Animal(name, trackNum){
	this->nurse = nurse;
}

Mammal::~Mammal() {
	// TODO Auto-generated destructor stub
}
string Mammal::getType() {
	return this->TYPE;
}

int Mammal::getEggs() {
	return 0;
}
int Mammal::getNurse() {
	return this->nurse;
}
