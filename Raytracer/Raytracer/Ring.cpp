/*
 *  Ring.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */

#include "Ring.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"

bool Ring::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	float t = dot( mNormalInverse, (ray.o - mCenter) ) / dot( mNormal, ray.d );
	Point P = ray.pointAtParam(t);
	Vector D = P - mCenter;
	float d = dot (D, D);
	return (d < mOuterRadius2 && d > mInnerRadius2) ? hit.hit(t, this, material) : false; 	
}
