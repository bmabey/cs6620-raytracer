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
#include <algorithm>
using std::max;
using std::min;

class Triangle : public Primitive
{
public:
	Triangle() { }
	Triangle(Material* m, Point a, Point b, Point c);
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
	Point min(){ return Point( min( mPointA.x(),mPointB.x(),mPointC.x() ), min( mPointA.y(),mPointB.y(),mPointC.y() ), min( mPointA.z(),mPointB.z(),mPointC.z() ) );}
	Point max(){ return Point( max( mPointA.x(),mPointB.x(),mPointC.x() ), max( mPointA.y(),mPointB.y(),mPointC.y() ), max( mPointA.z(),mPointB.z(),mPointC.z() ) );}
private:
	float min(float a, float b, float c) { return ( (a < b) && (a < c)) ? a : std::min(b, c);}
	float max(float a, float b, float c) { return ( (a > b) && (a > c)) ? a : std::max(b, c);}		
	Point mPointA;
	Point mPointB;
	Point mPointC;
	Vector mNormal;
	//Caching because they will be used for all intersect calls.
	float A; float B; float C; float D; float E; float F;

	
};

#endif