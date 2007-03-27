/*
 *  BoxFilter.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#ifndef _BOXFILTER_H_
#define _BOXFILTER_H_

#include "Filter.h"


class BoxFilter : public Filter
{
public:
	BoxFilter() { }
	~BoxFilter() { }
	void filterSamples(vector<Point>& samples);

 	
	
};

#endif 