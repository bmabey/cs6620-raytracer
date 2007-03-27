/*
 *  SingleSample.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#include "SingleSample.h"


void SingleSample::takeSamples(vector<Point>& samples) const
{
	int num_samples = samples.size();
	for(int i = 0; i< num_samples; i++)
	{
		samples[i].setX(0.5);
		samples[i].setY(0.5);
	}
}