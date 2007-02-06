/*
 *  Triangle.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_ 1

#include "Primitive.h"
#include "Point.h"


class Triangle : public Primitive
{
public:
	Triangle() { }
	Triangle(Material* m, Point a, Point b, Point c);
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
private:		
	Point mPointA;
	Point mPointB;
	Point mPointC;
	Vector mNormal;
	//Caching because they will be used for all intersect calls.
	float A; float B; float C; float D; float E; float F;

	
};

#endif