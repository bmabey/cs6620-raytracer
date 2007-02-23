/*
 *  DielectricMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/21/07.
 *
 */

#ifndef _DIELECTRICMATERIAL_H_
#define _DIELECTRICMATERIAL_H_

#include "Material.h"
#include "Color.h"

class DielectricMaterial : public Material
{
public:
	DielectricMaterial() : mSpecularLight( Color(1.0f,1.0f,1.0f) ) { }
	DielectricMaterial(float index_of_refraction, float n);
	~DielectricMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const;
private:
	float mIndex;
	Color mSpecularLight;
	Color mR0;
	float mN; //Exponent...
	
};

#endif