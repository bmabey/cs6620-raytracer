/*
 *  BlankMaterial.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/31/07.
 *
 */

#ifndef _BLANKMATERIAL_H_
#define _BLANKMATERIAL_H_


#include "Material.h"
#include "Color.h"

class HitRecord;
class Ray;
class RenderContext;
class BlankMaterial : public Material
{
public:
	BlankMaterial() { }
	BlankMaterial(const Color& c) : mSurfaceColor(c) { }
	~BlankMaterial() { }
  void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const { result = mSurfaceColor;}
private:
	Color mSurfaceColor;
	
};

#endif