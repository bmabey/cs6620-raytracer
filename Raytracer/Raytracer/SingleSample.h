/*
 *  SingleSample.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#ifndef _SINGLESAMPLE_H_
#define _SINGLESAMPLE_H_

#include "Sample.h"

class SingleSample : public Sample
{
public:
	SingleSample() { }
	~SingleSample() { }
	void takeSamples(vector<Point>& samples) const;
 	
	
};

#endif 