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
	Box(Material* m, Point min, Point max) : mMin(min), mMax(max)	{ material = m; boundingBox = BoundingBox(min, max); }
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	bool intersect(float& tnear, float& tfar, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
//	Point min(){ return Point( min( mMin.x(),mMax.x()), min( mMin.y(),mMax.y()) ) );}
//	Point max(){ return Point( max( mMin.x(),mMax.x()), max( mMin.y(),mMax.y()) ) );}
private:		
	Point mMin;
	Point mMax;
	
};

#endif