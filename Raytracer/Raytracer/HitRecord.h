/*
 *  HitRecord.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _HITRECORD_H_
#define _HITRECORD_H_ 1

class Primitive;
class Material;

class HitRecord
{

public:
	
	HitRecord() {}
	bool hit(double hit_t, const Primitive* hit_prim, const Material* hit_matl);
	
	double t;
	Primitive* primitive;
	Material* material;
	
};


#endif

