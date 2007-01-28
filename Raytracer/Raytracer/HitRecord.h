/*
 *  HitRecord.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _HITRECORD_H_
#define _HITRECORD_H_ 1

#include "Ray.h"
#include "Primitive.h"
#include "Material.h"

class HitRecord
{

public:
	
	HitRecord() {}
	bool hit(float hit_t, const Primitive* hit_prim, const Material* hit_matl);
	
	float t;
	Primitive* primitive;
	Material* material;
	
};


#endif

