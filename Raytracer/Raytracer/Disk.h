/*
 *  Disk.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */

#ifndef _DISK_H_
#define _DISK_H_ 1

#include "Primitive.h"
#include "Point.h"
#include "Vector.h"


class Disk : public Primitive
{
public:
	Disk() { }
	Disk(Material* m, Point c, Vector n, float r);
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const { N = mNormal; }
private:		
	Point mCenter;
	Vector mNormal;
	Vector mNormalInverse;
	float mRadius2;
	
};

#endif