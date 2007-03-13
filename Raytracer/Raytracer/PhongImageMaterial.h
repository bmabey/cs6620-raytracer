/*
 *  PhongImageMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/12/07.
 */

#ifndef _PHONGIMAGEMATERIAL_H_
#define _PHONGIMAGEMATERIAL_H_

#include "Material.h"
#include "Color.h"
#include "Image.h"
#include <iostream>



using namespace std;


class PhongImageMaterial : public Material
{
public:
	PhongImageMaterial() { }
	PhongImageMaterial(string filename, float kd, float ka, const Color& spec_color, float n) 
		: mKd(kd), mKa(ka), mSpecularColor(spec_color), mN(n)  {mImage = new Image(filename);}
	~PhongImageMaterial() { }
 	void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const;
private:
	Color mSpecularColor;
	float mN;
	float mKd;
	float mKa;
	Image* mImage;
	
};

#endif