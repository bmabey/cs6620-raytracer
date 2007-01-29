/*
 *  Sphere.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _SPHERE_H_
#define _SPHERE_H_ 1

#include "Primitive.h"
#include "Point.h"
#include "Ray.h"

class Sphere : public Primitive
{
public:
	Sphere() { }
	Sphere(Point c, float r) : center(c), radius(r) { }
	void intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
		
	Point center;
	float radius;

	
};

#endif