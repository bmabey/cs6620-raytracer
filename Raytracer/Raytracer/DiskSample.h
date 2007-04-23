/*
 *  DiskSample.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/15/07.
 *
 */


#ifndef _DISKSAMPLE_H_
#define _DISKSAMPLE_H_

#include "Sample.h"
#include "Point.h"

class DiskSample: public Sample
{
public:
	DiskSample() {};
	~DiskSample() {};
	void takeSamples(vector<Point>& samples);
	void shuffle(float* samples, int num_samples);
};

#endif 