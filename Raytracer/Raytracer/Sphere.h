/*
 *  Sphere.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _SPHERE_H_
#define _SPHERE_H_ 1

#include "Point.h"
#include "Ray.h"

class Sphere
{
public:
	Sphere() { }
	Sphere(Point c, float r) : center(c), radius(r) { }
	
	Point center;
	float radius;
	
	bool intersects(const Ray& ray);
	
};

#endif