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
void Group::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	for (int i = 0; i < num_objects; i++)
		objects[i]->intersect(hit, context, ray);
}

void Group::addObject(Object* object) 
{ 
	objects.push_back(object);
	num_objects++;
}