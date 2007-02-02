/*
 *  Ray.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _RAY_H_
#define _RAY_H_ 1

#include "RPoint.h"
#include "Vector.h"
class Background;
class Ray
{
public:
	Ray() { }
	Ray(RPoint p, Vector v) : o(p), d(v) { }
	Ray(const Ray& rhs) { *this = rhs; }
	void normalize() { d.normalize();}
	RPoint origin() const { return o;}
	Vector direction() const { return d;}
	RPoint pointAtParam(float t) const { return o + (t*d); }
	RPoint o;
	Vector d;
	
};

#endif
