/*
 * Goose.h
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include "../Oviparous.h"

class Goose: public Oviparous {
	private:
		const string SUBTYPE = "Goose";
	public:
		Goose(string name, int trackNum, int numOfEggs);
		virtual ~Goose();
		string getSubType();
};

#endif /* GOOSE_H_ */
