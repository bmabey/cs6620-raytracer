/*
 *  CubicSplineFilter.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/27/07.
 *
 */

#include "CubicSplineFilter.h"

float CubicSplineFilter::solve(float r)
{
	float u = r;
	for(int i = 0; i < 5; i++)
	{
		u = (11.0 * r + u * u * (6.0 + u * (8.0 - 9.0 * u))) / (4.0 + 12.0 * u * (1.0 + u * (1.0 - u)));
		return u;
	}
}

float CubicSplineFilter::cubicFilter(float x)
{
	if(x < 1.0 / 24.0)
		return pow(24 * x, 0.25) - 2.0;
	else if(x < 0.5)
		return solve(24.0 * (x - 1.0 / 24.0) / 11.0) - 1.0;
	else if( x < 23.0 / 24.0)
		return 1.0 - solve(24.0 * (23.0 / 24.0 - x) / 11.0);
	else
		return 2 - pow(24.0 * (1.0 - x), 0.25);
}

void CubicSplineFilter::filterSamples(vector<Point>& samples) 
{
	int num_samples = samples.size();
	for(int i = num_samples - 2; i >=0; i--)
	{		
		samples[i].setX(cubicFilter(samples[i].x()));
		samples[i].setY(cubicFilter(samples[i].y()));
	}
}

