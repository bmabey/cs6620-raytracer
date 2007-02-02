/*
 *  Sphere.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#include "Sphere.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"

bool Sphere::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	Vector o_minus_c = ray.o - mCenter;
	double a = dot(ray.d, ray.d);
	double b = 2.0 * dot(ray.d, o_minus_c);
	double c = dot(o_minus_c, o_minus_c) - (mRadius2);
	
	double disc = b*b - 4.0*a*c;
	
	//Does it intersect?
	if (disc > 0)
	{
		disc = sqrt(disc);
		double t = (-b - disc) / (2.0*a);
		//Early termination
		if (hit.hit(t, this, material)) return true;
		t = ( -b + disc) / (2.0*a);
		return (hit.hit(t, this, material));	
	}
	return false;
	
	
}

void Sphere::getNormal(Vector& N, const HitRecord& record, const RPoint& pos) const
{
	N = pos - mCenter;
	N.normalize();
}
