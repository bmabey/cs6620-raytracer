/*
 *  Group.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#include "Group.h"
#include "Ray.h"
#include "HitRecord.h"
#include "RenderContext.h"

Group::~Group()
{
	for (int i = 0; i < num_objects; i++)
		delete objects[i];
}
//virtual void preprocess(); 
bool Group::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	bool intersected = false;
	for (int i = 0; i < num_objects; i++)
		intersected = objects[i]->intersect(hit, context, ray) || intersected;
		
	return intersected;
}

void Group::addObject(Object* object) 
{ 
	objects.push_back(object);
	num_objects++;
}