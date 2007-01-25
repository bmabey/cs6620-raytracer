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
	
	Point o;
	Vector d;
	
};

#endif
