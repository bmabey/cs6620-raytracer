/*
 *  LambertianMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#ifndef _LAMBERTIANMATERIAL_H_
#define _LAMBERTIANMATERIAL_H_

#include "Material.h"
#include "Color.h"

class LambertianMaterial : public Material
{
public:
	LambertianMaterial() { }
	LambertianMaterial(const Color& c, float kd, float ka) : mSurfaceColor(c), mKd(kd), mKa(ka) { }
	~LambertianMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, int depth) const;
private:
	Color mSurfaceColor;
	float mKd;
	float mKa;
	
};

#endif