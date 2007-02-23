/*
 *  MetalMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/21/07.
 *
 */

#ifndef _METALMATERIAL_H_
#define _METALMATERIAL_H_

#include "Material.h"
#include "Color.h"

class MetalMaterial : public Material
{
public:
	MetalMaterial() { }
	MetalMaterial(const Color& c, float n)	: mR0(c), mN(n) { }
	~MetalMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const;
private:
	Color mR0;
	float mN;
	
};

#endif