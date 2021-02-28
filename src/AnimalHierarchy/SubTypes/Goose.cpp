/*
 * Goose.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#include "Goose.h"

Goose::Goose(string name, int trackNum, int numOfEggs)
	: Oviparous(name, trackNum, numOfEggs){
	// TODO Auto-generated constructor stub

}

Goose::~Goose() {
	// TODO Auto-generated destructor stub
}

string Goose::getSubType() {
	return this->SUBTYPE;
}
