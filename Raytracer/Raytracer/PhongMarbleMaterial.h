/*
 *  PhongMarbleMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/13/07.
 *
 */


#ifndef _PHONGMARBLEMATERIAL_H_
#define _PHONGMARBLEMATERIAL_H_

#include "Material.h"
#include "Color.h"

class PhongMarbleMaterial : public Material
{
public:
	PhongMarbleMaterial() { }
	/*
	  Material* marble = new PhongMarbleMaterial(Color(0.1, 0.2, 0.5), // Color 1
                                             Color(0.7, 0.8, 1.0), // Color 2
                                             0.5, // scale
                                             8, // octaves
                                             20, // turbulence scale
                                             1, // frequency scale
                                             2, // lacunarity
                                             0.6, // gain
                                             0.6, 0.4, Color(1,1,1), 120);
	*/
	PhongMarbleMaterial(const Color& color1, const Color& color2, float scale, int octaves, float t_scale, float f_scale, float lacunarity, float gain, float kd, float ka, const Color& spec_color, float n);
	~PhongMarbleMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const;
private:
	Color mColor1;
	Color mColor2;
	Color mSpecularColor;
	int mOctaves;
	float mN, mKd, mKa, mTurbScale, mFreqScale, mLacunarity, mGain, mScale;
	
};

#endif