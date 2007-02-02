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
#include "RPoint.h"


class Sphere : public Primitive
{
public:
	Sphere() { }
	Sphere(Material* m, RPoint c, float r) : mCenter(c), mRadius(r), mRadius2(r*r) { material = m;}
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const RPoint& pos) const;
private:		
	RPoint mCenter;
	float mRadius;
	float mRadius2;

	
};

#endif