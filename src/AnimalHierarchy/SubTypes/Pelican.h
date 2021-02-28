/*
 * Pelican.h
 *
 *  Created on: Feb 27, 2021
 *      Author: 1891467_snhu
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include "../Oviparous.h"

class Pelican: public Oviparous {
	private:
		const string SUBTYPE = "Pelican";
	public:
		Pelican(string name, int trackNum, int numOfEggs);
		virtual ~Pelican();
		string getSubType();
};

#endif /* PELICAN_H_ */
