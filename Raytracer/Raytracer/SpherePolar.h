/*
 *  SpherePolar.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/12/07.
 *
 */

#ifndef _SPHEREPOLAR_H_
#define _SPHEREPOLAR_H_ 1

#include "Primitive.h"
#include "Vector.h"
class Point;


class SpherePolar : public Primitive
{
public:
	SpherePolar() { }
	SpherePolar(Material* m, Point c, float r, const Vector& z, const Vector& x);
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
private:		
	Point mCenter;
	float mRadius;
	float mRadius2;
	Vector mX;
	Vector mY;
	Vector mZ;

	
};

#endif