/*
 *  Instance.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/10/07.
 *
 */

#ifndef _INSTANCE_H_
#define _INSTANCE_H_ 1

#include "Primitive.h"
#include "Matrix.h"
class Point;

class Instance : public Primitive
{
public:
	Instance() {}
	Instance(Matrix trans, Primitive* p);
	~Instance(){};
	
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
	void computeBoundingBox();
	
	Primitive* primitive;
	Matrix M, Minv;
};

#endif 
