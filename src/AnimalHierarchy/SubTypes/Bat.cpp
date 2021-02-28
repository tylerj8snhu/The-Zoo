/*
 * Bat.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#include "Bat.h"

Bat::Bat(string name, int trackNum, int nurse)
	: Mammal(name, trackNum, nurse){

}

Bat::~Bat() {
}

string Bat::getSubType() {
	return this->SUBTYPE;
}


