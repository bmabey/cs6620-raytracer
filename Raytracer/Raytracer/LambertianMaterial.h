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

class LambertianMaterial : public Material
{
public:
	LambertianMaterial() { }
	~LambertianMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, int depth) const; 
	
};

#endif