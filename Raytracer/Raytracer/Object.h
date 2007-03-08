/*
 *  Object.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */


#ifndef _OBJECT_H_
#define _OBJECT_H_ 1

#include "Ray.h"
#include "HitRecord.h"
#include "RenderContext.h"
//#include "BoundingBox.h"

class Object
{

public:
	
	Object() { }
	virtual ~Object() { }
	virtual void preprocess() { } 
	virtual bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const = 0;
	
	//BoundingBox boundingBox;

	
};


#endif