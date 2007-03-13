/*
 *  PhongImageMaterial.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/12/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "PhongImageMaterial.h"
#include "Color.h"
#include "Point.h"
#include "Vector.h"
#include "HitRecord.h"
#include "Primitive.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Scene.h"
#include "Light.h"
#include "Group.h"


void PhongImageMaterial::shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const
{
	//Compute hit position
	Point hit_position = ray.pointAtParam(hit.t);
	//Get normal from primitive
	Vector N;
	hit.primitive->getNormal(N, hit, hit_position);
	//Calc costheta
	float costheta = dot(N, ray.direction());
	//Flip N if need to
	if (costheta > 0) N.inverse();

	result = context.getScene()->ambient*mKa;  //Still don't understand the purpose of having rendercontext yet...
	
	HitRecord shadow_record;
	Color specular_light = Color(0, 0, 0);
	Ray shadow_ray;
	int num_lights = context.getScene()->lights.size();
	for(int i = 0; i < num_lights; i++)
	{
		Vector light_direction;
		Color light_color;
		context.getScene()->lights[i]->getLight(light_color, light_direction, context, hit_position, shadow_record);
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
				Vector H = light_direction - ray.d;
				H.normalize();
				float cosalpha = dot(H, N);
				if(cosalpha > 0)
					specular_light += light_color * pow(cosalpha, mN);
			}
		}
	}


	float u = hit.uvw.x() - int(hit.uvw.x());
	float v = hit.uvw.y() - int(hit.uvw.y());
	u *= (mImage->mWidth - 3);
	v *= (mImage->mHeight - 3);

	int iu = (int)u;
	int iv = (int)v;
	
	float tu = u - iu;
	float tv = v - iv;
	
	Color c = mImage->mCanvas[iu][iv]*(1-tu)*(1-tv)+
			mImage->mCanvas[iu+1][iv]*tu*(1-tv)+
			mImage->mCanvas[iu][iv+1]*(1-tu)*tv+
			mImage->mCanvas[iu+1][iv+1]*tu*tv;
	
	result *= c;
	result += specular_light * mSpecularColor;
	
}
