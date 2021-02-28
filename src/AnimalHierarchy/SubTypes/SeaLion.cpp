/*
 * SeaLion.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#include "SeaLion.h"

SeaLion::SeaLion(string name, int trackNum, int nurse)
	: Mammal(name, trackNum, nurse){
	// TODO Auto-generated constructor stub

}

SeaLion::~SeaLion() {
	// TODO Auto-generated destructor stub
}

string SeaLion::getSubType() {
	return this->SUBTYPE;
}
