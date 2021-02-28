/*
 * Whale.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#include "Whale.h"

Whale::Whale(string name, int trackNum, int nurse)
	: Mammal(name, trackNum, nurse){
	// TODO Auto-generated constructor stub

}

Whale::~Whale() {
	// TODO Auto-generated destructor stub
}

string Whale::getSubType() {
	return this->SUBTYPE;
}
