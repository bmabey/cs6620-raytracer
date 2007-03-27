/*
 *  CubicSplineFilter.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *  Based from Realistic Ray Tracing, 2ed. by Peter Shirler and Keith Morley
 */


#ifndef _CUBICSPLINEFILTER_H_
#define _CUBICSPLINEFILTER_H_

#include "Filter.h"


class CubicSplineFilter : public Filter
{
public:
	CubicSplineFilter() { }
	~CubicSplineFilter() { }
	void filterSamples(vector<Point>& samples);
private:
	float solve(float r);
	float cubicFilter(float x);

 	
	
};

#endif 