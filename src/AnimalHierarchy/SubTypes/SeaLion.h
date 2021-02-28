/*
 * SeaLion.h
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#ifndef ANIMALHIERARCHY_SUBTYPES_SEALION_H_
#define ANIMALHIERARCHY_SUBTYPES_SEALION_H_

#include "../Mammal.h"

class SeaLion: public Mammal {
	private:
		const string SUBTYPE = "Sea Lion";
	public:
		SeaLion(string name, int trackNum, int nurse);
		virtual ~SeaLion();
		string getSubType();
};

#endif /* ANIMALHIERARCHY_SUBTYPES_SEALION_H_ */
