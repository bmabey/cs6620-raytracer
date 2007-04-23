/*
 *  Sample.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/26/07.
 *
 */
 
#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "Point.h"
#include <vector>

using namespace std;

class Sample
{
public:
	Sample() { }
	virtual ~Sample() { }
	virtual void takeSamples(vector<Point>& samples) = 0;
 	
	
};

#endif 