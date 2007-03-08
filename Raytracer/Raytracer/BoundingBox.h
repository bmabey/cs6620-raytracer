/*
 *  BoundingBox.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/6/07.
 *
 */


#ifndef _BOUNDINGBOX_H_
#define _BOUNDINGBOX_H_ 1

#include "Object.h"
#include "Point.h"
#include "Vector.h"
#include <algorithm>
using std::max;
using std::min;


class BoundingBox : public Object
{
public:
	BoundingBox() { }
	BoundingBox(Point min, Point max) : Min(min), Max(max) { }
	~BoundingBox() { }
	virtual bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const { return true;}
	bool intersect(float& tnear, float& tfar, const Ray& ray) const;

	Point Min;
	Point Max;
	
//private:		
//	Point mMin;
//	Point mMax;
	
};



#endif