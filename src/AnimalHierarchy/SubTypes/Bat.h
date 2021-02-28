/*
 * Bat.h
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#ifndef ANIMALHIERARCHY_SUBTYPES_BAT_H_
#define ANIMALHIERARCHY_SUBTYPES_BAT_H_

#include "../Mammal.h"

class Bat: public Mammal {
	private:
		const string SUBTYPE = "Bat";
	public:
		Bat(string name, int trackNum, int nurse);
		virtual ~Bat();
		string getSubType();
};

#endif /* ANIMALHIERARCHY_SUBTYPES_BAT_H_ */
