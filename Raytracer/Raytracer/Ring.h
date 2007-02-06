/*
 *  Ring.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */

#ifndef _RING_H_
#define _RING_H_ 1

#include "Primitive.h"
#include "Point.h"
#include "Vector.h"


class Ring : public Primitive
{
public:
	Ring() { }
	Ring(Material* m, Point c, Vector n, float inner, float outer) : mCenter(c), mNormal(n), mInnerRadius2(inner*inner), mOuterRadius2(outer*outer) 
	{ 
		material = m; 
		mNormal.normalize();
		mNormalInverse = -mNormal;
	}
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const { N = mNormal; }
private:		
	Point mCenter;
	Vector mNormal;
	Vector mNormalInverse;
	float mInnerRadius2;
	float mOuterRadius2;
	
};

#endif