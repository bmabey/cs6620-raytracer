/*
 *  Primitive.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */


#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_ 1

#include "Object.h"
#include "Material.h"
//class Material;
class Vector;
class HitRecord;
class RenderContext;
class Ray;
class Point;

class Primitive : public Object
{

public:
	
	Primitive() {  }
	virtual ~Primitive() { delete material; }
	virtual void preprocess() { }; 
	virtual void intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const = 0;
	virtual void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const = 0;
	
	Material* material;
	
};


#endif
