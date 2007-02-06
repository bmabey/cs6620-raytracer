/*
 *  Disk.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */

#include "Disk.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"

bool Disk::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	float t = dot( mNormalInverse, (ray.o - mCenter) ) / dot( mNormal, ray.d );
	Point P = ray.pointAtParam(t);
	Vector D = P - mCenter;
	return (dot(D, D) < mRadius2) ? hit.hit(t, this, material) : false; 	
}