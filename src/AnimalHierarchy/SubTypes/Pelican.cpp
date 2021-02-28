/*
 * Pelican.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#include "Pelican.h"

Pelican::Pelican(string name, int trackNum, int numOfEggs)
	: Oviparous(name, trackNum, numOfEggs){
	// TODO Auto-generated constructor stub

}

Pelican::~Pelican() {
	// TODO Auto-generated destructor stub
}

string Pelican::getSubType() {
	return this->SUBTYPE;
}
