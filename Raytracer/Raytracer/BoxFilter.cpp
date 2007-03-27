/*
 *  BoxFilter.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#include "BoxFilter.h"

void BoxFilter::filterSamples(vector<Point>& samples)
{
	int num_samples = samples.size();
	for(int i = num_samples - 2; i >=0; i--)
	{
		samples[i].setX(samples[i].x() - 0.5);
		samples[i].setY(samples[i].y() - 0.5);
	}
}