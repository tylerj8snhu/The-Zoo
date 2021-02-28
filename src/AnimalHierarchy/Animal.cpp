/*
 * Animal.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: 1891467_snhu
 */

#include "Animal.h"

Animal::Animal() {
	this->name = "";
	this->trackNum = 0;
}

Animal::Animal(string name, int trackNum) {
	this->name = name;
	this->trackNum = trackNum;
}
Animal::~Animal() {
	// TODO Auto-generated destructor stub
}

int Animal::getTrackNum(){
	return this->trackNum;
}

string Animal::getName(){
	return this->name;
}

string Animal::getType(){
	return "";
}

string Animal::getSubType(){
	return "";
}
