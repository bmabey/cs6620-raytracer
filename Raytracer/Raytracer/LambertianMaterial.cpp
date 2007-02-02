/*
 *  LambertianMaterial.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#include "LambertianMaterial.h"
#include "Color.h"
#include "RPoint.h"
#include "Vector.h"
#include "HitRecord.h"
#include "Primitive.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Scene.h"
#include "Light.h"
#include "Group.h"

void LambertianMaterial::shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, int depth) const
{
	//Compute hit position
	RPoint hit_position = ray.pointAtParam(hit.t);
	//Get normal from primitive
	Vector N;
	hit.primitive->getNormal(N, hit, hit_position);
	//Calc costheta
	float costheta = dot(N, ray.direction());
	//Flip N if need to
	if (costheta > 0) N.inverse();

	result = context.getScene()->ambient*mKa;  //Still don't understand the purpose of having rendercontext yet...
	
	HitRecord shadow_record;
	Ray shadow_ray;
	int num_lights = context.getScene()->lights.size();
	for(int i = 0; i < num_lights; i++)
	{
		Vector light_direction;
		Color light_color;
		context.getScene()->lights[i]->getLight(light_color, light_direction, context, hit_position);
		float cosphi = dot(N, light_direction);
		
		//Check for shadow...
		shadow_ray.o = hit_position; shadow_ray.d = light_direction;
		if(cosphi > 0)
		{
			shadow_record.setTinf();
			if(!context.getScene()->world->intersect(shadow_record, context, shadow_ray))
			{
				//If it doesn't hit then we go ahead and add the diffuse... else keep only the ambient.
				result += light_color*(mKd * cosphi);
			}
		}
	}

	result *= mSurfaceColor;
	
}