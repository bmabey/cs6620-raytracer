/*
 *  Filter.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/26/07.
 *
 */


#ifndef _FILTER_H_
#define _FILTER_H_

#include "Point.h"
#include <vector>

using namespace std;

class Filter
{
public:
	Filter() { }
	virtual ~Filter() { }
	virtual void filterSamples(vector<Point>& samples) = 0; 

 	
	
};

#endif 