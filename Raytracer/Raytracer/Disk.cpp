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

Disk::Disk(Material* m, Point c, Vector n, float r) : mCenter(c), mNormal(n), mRadius2(r*r) 
	{ 
		material = m; 
		mNormal.normalize();
		mNormalInverse = -mNormal;
		Point min(mCenter.x() - r, mCenter.y() - r, mCenter.z() - r);
		Point max(mCenter.x() + r, mCenter.y() + r, mCenter.z() + r);
		boundingBox = BoundingBox(min, max);
	}

bool Disk::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	float t = dot( mNormalInverse, (ray.o - mCenter) ) / dot( mNormal, ray.d );
	Point P = ray.pointAtParam(t);
	Vector D = P - mCenter;
	return (dot(D, D) < mRadius2) ? hit.hit(t, this, material) : false; 	
}