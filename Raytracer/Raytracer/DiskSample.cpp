/*
 *  DiskSample.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/22/07.
 *
 */

#include "DiskSample.h"

void DiskSample::takeSamples(vector<Point>& samples)
{
	int num_samples = samples.size();
	
	float r2[num_samples];
	float theta[num_samples];
	
	for(int i = 0; i < num_samples; i++)
	{
		r2[i] = ((double)i + drand48()) / (double)num_samples;
		theta[i] = ((2*M_PI)*((double)i + drand48())) / (double)num_samples;
	}

	shuffle(r2, num_samples);
	shuffle(theta, num_samples);

	for(int i = 0; i < num_samples; i++)
	{
		samples[i].setX(sqrt(r2[i])*sin(theta[i]));
		samples[i].setY(sqrt(r2[i])*cos(theta[i]));
	}
}

void DiskSample::shuffle(float* samples, int num_samples)
{
	for(int i = num_samples - 2; i >= 0; i--)
	{
		int target = int(drand48() * (double)i);
		float temp = samples[i+1];
		samples[i+1] = samples[target];
		samples[target] = temp;
	}	
}
