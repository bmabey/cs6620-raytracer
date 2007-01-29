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

void Sphere::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	Vector o_minus_c = ray.o - center;
	double a = dot(ray.d, ray.d);
	double b = 2.0 * dot(ray.d, o_minus_c);
	double c = dot(o_minus_c, o_minus_c) - (radius*radius);
	
	double disc = b*b - 4.0*a*c;
	
	//Does it intersect?
	if (disc > 0)
	{
		disc = sqrt(disc);
		double t = (-b - disc) / (2.0*a);
		hit.hit(t, this, material);
		t = ( -b + disc) / (2.0*a);
		hit.hit(t, this, material);	
	}
}

void Sphere::getNormal(Vector& N, const HitRecord& record, const Point& pos) const
{
	
}
