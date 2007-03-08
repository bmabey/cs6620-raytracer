/*
 *  BoundingBox.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/6/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "BoundingBox.h"
#include "HitRecord.h"
#include "RenderContext.h"
#include <algorithm>
using std::max;
using std::min;

bool BoundingBox::intersect(float& tnear, float& tfar, const Ray& ray) const
{	
	float txMin, txMax, tyMin, tyMax, tzMin, tzMax;
	
	if (ray.d.x() >= 0) 
	{
		txMin = (Min.x() - ray.o.x()) / ray.d.x();
		txMax = (Max.x() - ray.o.x()) / ray.d.x();
	}
	else 
	{
		txMin = (Max.x() - ray.o.x()) / ray.d.x();
		txMax = (Min.x() - ray.o.x()) / ray.d.x();
	}
	
	if (ray.d.y() >= 0) 
	{
		tyMin = (Min.y() - ray.o.y()) / ray.d.y();
		
		tyMax = (Max.y() - ray.o.y()) / ray.d.y();
	}
	else 
	{
		tyMin = (Max.y() - ray.o.y()) / ray.d.y();
		tyMax = (Min.y() - ray.o.y()) / ray.d.y();
	}
	
	if ((txMin > tyMax) || (tyMin > txMax))
		return false;
	if (tyMin > txMin)
		txMin = tyMin;
	if (tyMax < txMax)
		txMax = tyMax;
	
	if (ray.d.z() >= 0) 
	{
		tzMin = (Min.z() - ray.o.z()) / ray.d.z();
		tzMax = (Max.z() - ray.o.z()) / ray.d.z();
	}
	else 
	{
		tzMin = (Max.z() - ray.o.z()) / ray.d.z();
		tzMax = (Min.z() - ray.o.z()) / ray.d.z();
	}
	
	if ( (txMin > tzMax) || (tzMin > txMax) ) return false;
	if (tzMin > txMin)
		txMin = tzMin;
	if (tzMax < txMax)
		txMax = tzMax;
	
	if((txMin < 100000.0) && (txMax > .001))
	{
		tnear = (txMin < 0) ? 0 : txMin;
		tfar = txMax;
		return true;
	}
	
	return false;
	
}




