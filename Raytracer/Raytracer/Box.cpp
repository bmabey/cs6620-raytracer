/*
 *  Box.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "Box.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"
#include <stdlib.h>


bool Box::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	bool hasHit = false;
	float tmMin, tmMax, tymMin, tymMax, tzmMin, tzmMax;
	
	if (ray.d.x() >= 0) 
	{
		tmMin = (mMin.x() - ray.o.x()) / ray.d.x();
		tmMax = (mMax.x() - ray.o.x()) / ray.d.x();
	}
	else 
	{
		tmMin = (mMax.x() - ray.o.x()) / ray.d.x();
		tmMax = (mMin.x() - ray.o.x()) / ray.d.x();
	}

	if (ray.d.y() >= 0) 
	{
		tymMin = (mMin.y() - ray.o.y()) / ray.d.y();
		tymMax = (mMax.y() - ray.o.y()) / ray.d.y();
	}
	else 
	{
		tymMin = (mMax.y() - ray.o.y()) / ray.d.y();
		tymMax = (mMin.y() - ray.o.y()) / ray.d.y();
	}

	if ((tmMin > tymMax) || (tymMin > tmMax))
		return false;
	if (tymMin > tmMin)
		tmMin = tymMin;
	if (tymMax < tmMax)
		tmMax = tymMax;

	if (ray.d.z() >= 0) 
	{
		tzmMin = (mMin.z() - ray.o.z()) / ray.d.z();
		tzmMax = (mMax.z() - ray.o.z()) / ray.d.z();
	}
	else 
	{
		tzmMin = (mMax.z() - ray.o.z()) / ray.d.z();
		tzmMax = (mMin.z() - ray.o.z()) / ray.d.z();
	}

	if ( (tmMin > tzmMax) || (tzmMin > tmMax) )
		return false;
	if (tzmMin > tmMin)
		tmMin = tzmMin;
	if (tzmMax < tmMax)
		tmMax = tzmMax;
	
	if(hit.hit(tmMin, this, material))
	{
		hasHit = true;
	}
	
	if(hit.hit(tmMax, this, material))
	{
		hasHit = true;
	}

	return hasHit;
	
	
}

void Box::getNormal(Vector& N, const HitRecord& record, const Point& pos) const
{
	float epsilon = .001;
	
	if(abs(mMin.x() - pos.x()) < epsilon)
		N = Vector(-1, 0, 0);
	else if(abs(mMax.x() - pos.x()) < epsilon)
		N = Vector(1, 0, 0);
	else if(abs(mMin.y() - pos.y()) < epsilon)
		N = Vector(0, -1, 0);
	else if(abs(mMax.y() - pos.y()) < epsilon)
		N = Vector(0, 1, 0);
	else if(abs(mMin.z() - pos.z()) < epsilon)
		N = Vector(0, 0, -1);
	else 
		N = Vector(0, 0, 1);
}

