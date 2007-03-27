/*
 *  JitteredSample.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#ifndef _JITTEREDSAMPLE_H_
#define _JITTEREDSAMPLE_H_

#include "Sample.h"



class JitteredSample : public Sample
{
public:
	JitteredSample() { }
	~JitteredSample() { }
	void takeSamples(vector<Point>& samples) const;
 	
	
};

#endif 