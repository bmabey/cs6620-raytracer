/*
 *  CheckerMaterial.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/13/07.
 *
 */

#include "CheckerMaterial.h"
#include "Color.h"
#include "Point.h"
#include "Vector.h"
#include "HitRecord.h"
#include "Primitive.h"
#include "Ray.h"
#include "RenderContext.h"
#include "HitRecord.h"
#include "Scene.h"
#include "Light.h"
#include "Group.h"

void CheckerMaterial::shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const
{
	//Compute hit position
	Point hit_position = ray.pointAtParam(hit.t);
	
	Vector temp = hit_position - mOrigin;
	
	int i1 = floor(dot(mU, temp));
	int i2 = floor(dot(mV, temp));

	int cell = (i1 + i2)%2;
	
	if(cell == 0)
		mMaterial1->shade(result, context, ray, hit, attenuation, depth);
	else
		mMaterial2->shade(result, context, ray, hit, attenuation, depth);
	
}