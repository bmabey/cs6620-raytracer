/*
 *  DielectricMaterial.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/21/07.
 *
 */

#include "DielectricMaterial.h"
#include "Color.h"
#include "Point.h"
#include "Vector.h"
#include "HitRecord.h"
#include "Background.h"
#include "Primitive.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Scene.h"
#include "Light.h"
#include "Group.h"
#include <algorithm>
#include <iostream>
using std::cout;
using std::min;

DielectricMaterial::DielectricMaterial(float index_of_refraction, float n)	
: mIndex(index_of_refraction), mN(n), mSpecularLight( Color(1.0f,1.0f,1.0f) ) 
{ 
		float temp = (index_of_refraction - 1.0)/(index_of_refraction + 1.0);
		temp = temp * temp;
		mR0 = Color(temp, temp, temp);
}

void DielectricMaterial::shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const
{
	//Compute hit position
	Point hit_position = ray.pointAtParam(hit.t);
	//Get normal from primitive
	Vector N;
		hit.primitive->getNormal(N, hit, hit_position);
	//Vector Ntmp;
	float index_temp;

	Vector unflippedN = N;
	
	//Calc costheta
	float costheta = dot(N, ray.d);
	//Flip N if need to
	if(costheta > 0)
	{
		index_temp = 1.0 / mIndex;
		N.inverse();
	}
	else
	{
		costheta = -costheta;
		index_temp = mIndex;
	}
	
	
	HitRecord shadow_record;
	Color specular_light = Color(0, 0, 0);
	Ray shadow_ray;
	Vector light_direction;
	Color light_color;
	int num_lights = context.getScene()->lights.size();
	for(int i = 0; i < num_lights; i++)
	{
		context.getScene()->lights[i]->getLight(light_color, light_direction, context, hit_position, shadow_record);
		float cosphi = dot(unflippedN, light_direction);
		
		//Check for shadow...
		if(cosphi > 0)
		{
			shadow_ray.o = hit_position; shadow_ray.d = light_direction;
			shadow_record.setTinf();
			if(!context.getScene()->world->intersect(shadow_record, context, shadow_ray))
			{
				//If it doesn't hit then we go ahead and add the diffuse... else keep only the ambient.
				//result += light_color*(mKd * cosphi);
				Vector H = light_direction - ray.d;
				H.normalize();
				float cosalpha = dot(H, unflippedN);
				if(cosalpha > 0)
					specular_light += light_color * pow(cosalpha, mN);
			}
		}
	}

	
	result = specular_light * mSpecularLight; //White- as suggested by slides....
	
	HitRecord temp_record;
	if( (depth < context.getScene()->maxRayDepth) && (attenuation > context.getScene()->minAttenuation) )
	{
		//cout << "attenuation=" << attenuation << ",  minAttenuation=" << context.getScene()->minAttenuation << "\n";

		
		//cout << "depth of " << depth << " < maxRayDepth of " << context.getScene()->maxRayDepth << "\n";
		float costheta2 = 1 + ( (costheta*costheta) - 1) / ( index_temp * index_temp);
		Vector reflect_direction = ray.d +  (2 * costheta)*N;
		reflect_direction.normalize();
		Ray reflect_ray(hit_position, reflect_direction);
		Color reflect_color;
		if (costheta2 < 0)
		{
		
			context.getScene()->background->getBackgroundColor(reflect_color, context, reflect_ray);
			temp_record.setTinf();
			if(context.getScene()->world->intersect(temp_record, context, reflect_ray))
			{
				//cout << "Going to call depth + 1 (" << depth+1 << ")\n";
				temp_record.material->shade(reflect_color, context, reflect_ray, temp_record, attenuation, depth + 1);
			}
			result += reflect_color;
		}
		else
		{
			costheta2 = sqrt(costheta2);
			float cosm = min(costheta,costheta2);
			Color Fr = mR0 + (1 - mR0)*pow( (1 - cosm), 5);
			context.getScene()->background->getBackgroundColor(reflect_color, context, reflect_ray);
		
			temp_record.setTinf();
			
			if(context.getScene()->world->intersect(temp_record, context, reflect_ray))
			{
				//cout << "Going to call depth + 1 (" << depth+1 << ")\n";
				float new_attenuation = Fr.getMax();
				new_attenuation *= attenuation;
				temp_record.material->shade(reflect_color, context, reflect_ray, temp_record, new_attenuation, depth + 1);
			}
		
			result += Fr * reflect_color;
			Color Ft = 1 - Fr;
			
//			Vector trans_direction = (1/index_temp)
			Vector transp_direction = (ray.d / index_temp) +  N*( (costheta/index_temp) - costheta2);
			Ray transp_ray(hit_position, transp_direction);
			Color transp_color;
			context.getScene()->background->getBackgroundColor(transp_color, context, transp_ray);
			
			temp_record.setTinf();
			if(context.getScene()->world->intersect(temp_record, context, transp_ray))
			{
				temp_record.material->shade(transp_color, context, transp_ray, temp_record, Ft.getMax()*attenuation, depth + 1);
			}
			
			result += transp_color * Ft;
		}
	}
	
}
