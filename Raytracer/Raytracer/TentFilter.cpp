/*
 *  TentFilter.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#include "TentFilter.h"


void TentFilter::filterSamples(vector<Point>& samples)
{
	int num_samples = samples.size();
	for(int i = 0; i < num_samples; i++)
	{
		float x = samples[i].x();
		float y = samples[i].y();
		
		if(x < 0.5)
			samples[i].setX(sqrt(2.0 * x) - 1.0);
		else
			samples[i].setX(1.0 - sqrt(2.0 - 2.0 * x));
		
		if(y < 0.5)
			samples[i].setY(sqrt(2.0 * y) - 1.0);
		else
			samples[i].setY(1.0 - sqrt(2.0 - 2.0 * y));
	}
}