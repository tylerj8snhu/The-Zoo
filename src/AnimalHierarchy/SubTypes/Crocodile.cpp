/*
 * Crocodile.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#include "Crocodile.h"

Crocodile::Crocodile(string name, int trackNum, int numOfEggs)
	: Oviparous(name, trackNum, numOfEggs){
	// TODO Auto-generated constructor stub

}

Crocodile::~Crocodile() {
	// TODO Auto-generated destructor stub
}

string Crocodile::getSubType() {
	return this->SUBTYPE;
}
