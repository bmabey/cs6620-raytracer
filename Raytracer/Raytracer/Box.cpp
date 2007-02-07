/*
 *  Box.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
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
	float txMin, txMax, tymMin, tymMax, tzmMin, tzmMax;
	
	if (ray.d.x() >= 0) 
	{
		txMin = (mMin.x() - ray.o.x()) / ray.d.x();
		txMax = (mMax.x() - ray.o.x()) / ray.d.x();
	}
	else 
	{
		txMin = (mMax.x() - ray.o.x()) / ray.d.x();
		txMax = (mMin.x() - ray.o.x()) / ray.d.x();
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

	if ((txMin > tymMax) || (tymMin > txMax))
		return false;
	if (tymMin > txMin)
		txMin = tymMin;
	if (tymMax < txMax)
		txMax = tymMax;

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

	if ( (txMin > tzmMax) || (tzmMin > txMax) ) return false;
	if (tzmMin > txMin) 
		txMin = tzmMin;
	if (tzmMax < txMax) 
		txMax = tzmMax;
	
	hasHit = (hit.hit(txMin, this, material)) || hasHit;
	hasHit = (hit.hit(txMax, this, material)) || hasHit;

	return hasHit;
	
	
}

void Box::getNormal(Vector& N, const HitRecord& record, const Point& pos) const
{
	float epsilon = .001f;
	
	if(fabs(mMin.x() - pos.x()) < epsilon)
		N = Vector(-1, 0, 0);
	else if(fabs(mMax.x() - pos.x()) < epsilon)
		N = Vector(1, 0, 0);
	else if(fabs(mMin.y() - pos.y()) < epsilon)
		N = Vector(0, -1, 0);
	else if(fabs(mMax.y() - pos.y()) < epsilon)
		N = Vector(0, 1, 0);
	else if(fabs(mMin.z() - pos.z()) < epsilon)
		N = Vector(0, 0, -1);
	else 
		N = Vector(0, 0, 1);
	
}

