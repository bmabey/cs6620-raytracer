/*
 *  HitRecord.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#include "HitRecord.h"

bool HitRecord::hit(double hit_t, const Primitive* hit_prim, const Material* hit_matl)
{
	if( (hit_t > .01) && (hit_t < t) )
		{
			t = hit_t;
			primitive = hit_prim;
			material = hit_matl;
			return true;
		}
	return false;
}