/*
 *  Box.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */


#ifndef _BOX_H_
#define _BOX_H_ 1

#include "Primitive.h"
#include "Point.h"
#include "Vector.h"


class Box : public Primitive
{
public:
	Box() { }
	Box(Material* m, Point min, Point max) : mMin(min), mMax(max)	{ material = m; }
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
private:		
	Point mMin;
	Point mMax;
	
};

#endif