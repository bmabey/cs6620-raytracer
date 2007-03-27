/*
 *  TentFilter.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#ifndef _TENTFILTER_H_
#define _TENTFILTER_H_

#include "Filter.h"


class TentFilter : public Filter
{
public:
	TentFilter() { }
	~TentFilter() { }
	void filterSamples(vector<Point>& samples);

 	
	
};

#endif 