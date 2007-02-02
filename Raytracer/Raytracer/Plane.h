/*
 *  Plane.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/29/07.
 *
 */

#ifndef _PLANE_H_
#define _PLANE_H_ 1

#include "Primitive.h"
#include "Point.h"
#include "Vector.h"

class Plane : public Primitive
{
public:
	Plane() { }
	Plane(Material* m, Vector N, Point c) : mPoint(c), mNormal(N) 
	{ mNormal.normalize(); 
		mNormalInv = -mNormal;
		material = m; }
		
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const { N = mNormal;}
private:		
	Point mPoint;
	Vector mNormal;
	Vector mNormalInv;

	
};

#endif