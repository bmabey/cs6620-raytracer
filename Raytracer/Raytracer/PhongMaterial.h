/*
 *  PhongMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/21/07.
 *
 */

#ifndef _PHONGMATERIAL_H_
#define _PHONGMATERIAL_H_

#include "Material.h"
#include "Color.h"

class PhongMaterial : public Material
{
public:
	PhongMaterial() { }
	PhongMaterial(const Color& c, float kd, float ka, const Color& spec_color, float n) 
		: mSurfaceColor(c), mKd(kd), mKa(ka), mSpecularColor(spec_color), mN(n)  { }
	~PhongMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const;
private:
	Color mSurfaceColor;
	Color mSpecularColor;
	float mN;
	float mKd;
	float mKa;
	
};

#endif