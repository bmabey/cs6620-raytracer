/*
 *  Group.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#include "Group.h"


	Group::~Group()
	{
		for (int i = 0; i < num_objects; i++)
			delete objects[i];
	}
	//virtual void preprocess(); 
	void Group::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray)
	{
		for (int i = 0; i < num_objects; i++)
			objects[i]->intersect(hit, context, ray);
	}