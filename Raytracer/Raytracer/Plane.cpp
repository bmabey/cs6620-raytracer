/*
 *  Plane.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/29/07.
 *
 */

#include "Plane.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"
#include "Vector.h"
#include "Point.h"
#include "Ray.h"

bool Plane::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	float t = dot( mNormalInv, ray.o - mPoint ) / dot( mNormal, ray.d );
	return hit.hit(t, this, material);	
}
