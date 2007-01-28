/*
 *  Material.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */


#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "RenderContext.h"
#include "Ray.h"
#include "HitRecord.h"
#include "Color.h"

class HitRecord;
class Material
{
public:
 virtual void preprocess(); 
 virtual void shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, int depth) const = 0; 
	
};

#endif 
