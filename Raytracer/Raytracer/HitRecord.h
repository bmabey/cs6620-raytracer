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
#include "Vector.h"
#include "Point.h"
#include <assert.h>

#define MAXSIZE 400
using std::numeric_limits;

class Primitive;


class HitRecord
{

public:
	
	HitRecord() : t(numeric_limits<double>::infinity()) {}
	bool hit(double hit_t, const Primitive* hit_prim, const Material* hit_matl);
	void setTinf() { t = numeric_limits<double>::infinity(); }
	template<typename T> T* getScratchpad() const { assert(sizeof(T) <= MAXSIZE); return (T*)(data); }
	
	double t;
	const Primitive* primitive;
	const Material* material;
	char data[MAXSIZE];
	Vector uvw;
	Vector n; //The normal.. stored here for instancing
	Point p;
	
};




#endif

