/*
 *  CheckerMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/13/07.
 *
 */

#ifndef _CHECKERMATERIAL_H_
#define _CHECKERMATERIAL_H_

#include "Material.h"
#include "Color.h"
#include "Point.h"
#include "Vector.h"

class CheckerMaterial : public Material
{
public:
	CheckerMaterial() { }
	CheckerMaterial(const Point& p, const Vector& u, const Vector& v, Material* mat1, Material* mat2) : mOrigin(p), mU(u), mV(v), mMaterial1(mat1), mMaterial2(mat2)
	{ mU /= mU.length2(); mV /= mV.length2();}
	~CheckerMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const;
private:
	Vector mU, mV;
	Point mOrigin;
	Material* mMaterial1;
	Material* mMaterial2;
	
};

#endif