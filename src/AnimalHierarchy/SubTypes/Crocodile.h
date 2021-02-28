/*
 * Crocodile.h
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#ifndef ANIMALHIERARCHY_SUBTYPES_CROCODILE_H_
#define ANIMALHIERARCHY_SUBTYPES_CROCODILE_H_

#include "../Oviparous.h"

class Crocodile: public Oviparous {
	private:
		const string SUBTYPE = "Crocodile";
	public:
		Crocodile(string name, int trackNum, int numOfEggs);
		virtual ~Crocodile();
		string getSubType();
};

#endif /* ANIMALHIERARCHY_SUBTYPES_CROCODILE_H_ */
