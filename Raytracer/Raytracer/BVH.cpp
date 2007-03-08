/*
 *  BVH.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/6/07.
 *
 */

#include "BVH.h"
#include "BoundingBox.h"

BoundingBox bounds(const BoundingBox& b1, const BoundingBox& b2)
{

	Point minPoint = Point( min(b1.Min.x(), b2.Min.x()), min(b1.Min.y(), b2.Min.y()), min(b1.Min.z(), b2.Min.z()) );
	Point maxPoint = Point( max(b1.Max.x(), b2.Max.x()), max(b1.Max.y(), b2.Max.y()), max(b1.Max.z(), b2.Max.z()) );
	return BoundingBox(minPoint, maxPoint);
}
BVH::BVH(vector<Primitive*>& primitives)
{
	if(primitives.size() == 1)
	{
		left = primitives[0];
		right = primitives[0];
		boundingBox = primitives[0]->boundingBox;
	}
	else if(primitives.size() == 2)
	{
		left = primitives[0];
		right = primitives[1];
		boundingBox = bounds(primitives[0]->boundingBox, primitives[1]->boundingBox);
	}
	else
	{
		boundingBox = primitives[0]->boundingBox;
		for(int i = 1; i < primitives.size(); i++)
		{
			boundingBox = bounds(boundingBox, primitives[i]->boundingBox);
		}

		Point pivot = (boundingBox.Max + boundingBox.Min) / 2.0;
		
		vector<Primitive*> leftPrimitives;
		vector<Primitive*> rightPrimitives;
		
		split(primitives, pivot.x(), 0, leftPrimitives, rightPrimitives);

		left = buildBranch(leftPrimitives, 1);
		right = buildBranch(rightPrimitives, 1); 

	}
}
	
BVH::BVH(Primitive* o1, Primitive* o2)
{
	left = o1;
	right = o2;
	boundingBox = bounds(o1->boundingBox, o2->boundingBox);
}

BVH::~BVH()
{
	delete left;
	delete right;

}
	
bool BVH::intersect(HitRecord& record, const RenderContext& context,const Ray& ray) const
{
	float tnear, tfar;
	if(!(boundingBox.intersect(tnear, tfar, ray)))
		return false;

	bool hitPrimitive1 = false;
	bool hitPrimitive2 = false;

	hitPrimitive1 = left->intersect(record, context, ray);
	hitPrimitive2 = right->intersect(record, context, ray);

	return (hitPrimitive1 || hitPrimitive2);
}

Primitive* BVH::buildBranch(vector<Primitive*>& primitives, int axis)
{
	if(primitives.size() == 1)
		return primitives[0];
	if(primitives.size() == 2)
		return new BVH(primitives[0], primitives[1]);

	BoundingBox tempBoundingBox = primitives[0]->boundingBox;
	for(int i = 1; i < primitives.size(); i++)
		tempBoundingBox = bounds(tempBoundingBox, primitives[i]->boundingBox);

	Point pivot = (tempBoundingBox.Max + tempBoundingBox.Min) / 2.0;
		
	vector<Primitive*> leftPrimitives;
	vector<Primitive*> rightPrimitives;
		
	split(primitives, pivot.mCoord[axis], axis, leftPrimitives, rightPrimitives);
	
		
	Primitive* temp_left = buildBranch(leftPrimitives, (axis+1) % 3);
	Primitive* temp_right = buildBranch(rightPrimitives, (axis+1) % 3); 

	return new BVH(temp_left, temp_right);
}

void BVH::split(vector<Primitive*>& primitives, 
		float pivot, 
		int axis, 
		vector<Primitive*>& leftPrimitives, 
		vector<Primitive*>& rightPrimitives)
{
	BoundingBox tempBoundingBox;
	float centroid;
	
	for(int i = 0; i < primitives.size(); i++)
	{
		tempBoundingBox = primitives[i]->boundingBox;
		centroid = (tempBoundingBox.Min.mCoord[axis] + tempBoundingBox.Max.mCoord[axis]) / 2.0;
		if(centroid < pivot)
			leftPrimitives.push_back(primitives[i]);
		else
			rightPrimitives.push_back(primitives[i]);
	}

	if(leftPrimitives.size() == 0)
	{
		for(int j = 0; j < (rightPrimitives.size()/2); j++)
			leftPrimitives.push_back(rightPrimitives[j]);
		vector<Primitive*> temp;
		for(int k = (rightPrimitives.size()/2); k < rightPrimitives.size(); k++)
			temp.push_back(rightPrimitives[k]);
		rightPrimitives.clear();
		for(int l = 0; l < temp.size(); l++)
			rightPrimitives.push_back(temp[l]);
	}
	else if(rightPrimitives.size() == 0)
	{
		vector<Primitive*> temp;
		for(int j = 0; j < (leftPrimitives.size()/2); j++)
			temp.push_back(leftPrimitives[j]);
		for(int k = (leftPrimitives.size()/2); k < leftPrimitives.size(); k++)
			rightPrimitives.push_back(leftPrimitives[k]);
		leftPrimitives.clear();
		for(int l = 0; l < temp.size(); l++)
			leftPrimitives.push_back(temp[l]);

	}
}
