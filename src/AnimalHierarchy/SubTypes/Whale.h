/*
 * Whale.h
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#ifndef ANIMALHIERARCHY_SUBTYPES_WHALE_H_
#define ANIMALHIERARCHY_SUBTYPES_WHALE_H_

#include "../Mammal.h"

class Whale: public Mammal {
	private:
		const string SUBTYPE = "Whale";
	public:
		Whale(string name, int trackNum, int nurse);
		virtual ~Whale();
		string getSubType();
};

#endif /* ANIMALHIERARCHY_SUBTYPES_WHALE_H_ */
