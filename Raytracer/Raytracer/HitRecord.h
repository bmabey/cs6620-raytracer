/*
 *  HitRecord.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _HITRECORD_H_
#define _HITRECORD_H_ 1

#include <limits>
#include "Material.h"
using std::numeric_limits;

class Primitive;


class HitRecord
{

public:
	
	HitRecord() : t(numeric_limits<double>::infinity()) {}
	bool hit(double hit_t, const Primitive* hit_prim, const Material* hit_matl);
	void setTinf() { t = numeric_limits<double>::infinity(); }
	double t;
	const Primitive* primitive;
	const Material* material;
	
};


#endif

