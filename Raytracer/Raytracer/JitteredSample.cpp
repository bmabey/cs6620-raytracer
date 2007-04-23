/*
 *  JitteredSample.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#include "JitteredSample.h"

void JitteredSample::takeSamples(vector<Point>& samples)
{
	int num_samples = samples.size();
	int sqrt_samples = (int)(sqrt(num_samples));
	for(int i = 0; i < sqrt_samples; i++)
	{
		for(int j = 0; j < sqrt_samples; j++)
		{
			float x = ((double)i + drand48()) / (double)sqrt_samples;
			float y = ((double)j + drand48()) / (double)sqrt_samples;
			samples[i*sqrt_samples + j].setX(x);
			samples[i*sqrt_samples + j].setY(y);
		}
	}
}