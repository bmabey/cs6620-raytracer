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


class Sphere : public Primitive
{
public:
	Sphere() { }
	Sphere(Material* m, Point c, float r) : mCenter(c), mRadius(r), mRadius2(r*r) { material = m;}
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
private:		
	Point mCenter;
	float mRadius;
	float mRadius2;

	
};

#endif