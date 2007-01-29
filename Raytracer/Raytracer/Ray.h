/*
 *  Ray.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _RAY_H_
#define _RAY_H_ 1

#include "Point.h"
#include "Vector.h"
class Ray
{
public:
	Ray() { }
	Ray(Point p, Vector v) { o = p; d = v; }
	Ray(const Ray& rhs) { *this = rhs; }
	void normalize() { d.normalize();}
	Point origin() const { return o;}
	Vector direction() const { return d;}
	Point pointAtParam(float t) const { return o + (t*d); }
	Point o;
	Vector d;
	
};

#endif
