/*
 *  BVH.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/6/07.
 *
 */
 
#ifndef _BVH_H_
#define _BVH_H_

#include "Primitive.h"
#include <vector>


using namespace std;

class BVH : public Primitive
{
public:
	BVH() {}
	BVH(vector<Primitive*>& primitives);
	BVH(Primitive* o1, Primitive* o2);
	~BVH();
	
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	Primitive* buildBranch(vector<Primitive*>& primitives, int axis);
	void split(vector<Primitive*>& primitives, float pivot, int axis, vector<Primitive*>& leftPrimitives, vector<Primitive*>& rightPrimitives);
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const {}
	Primitive* left;
	Primitive* right;
};

#endif 

