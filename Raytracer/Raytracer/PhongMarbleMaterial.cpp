/*
 *  PhongMarbleMaterial.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/13/07.
 *
 */

#include "PhongMarbleMaterial.h"
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
#include "PerlinNoise.h"


PhongMarbleMaterial::PhongMarbleMaterial(const Color& color1, const Color& color2, float scale, int octaves, float t_scale, float f_scale, float lacunarity, float gain, float kd, float ka, const Color& spec_color, float n) 
		: mColor1(color1), mColor2(color2), mScale(scale), mOctaves(octaves), mTurbScale(t_scale), mFreqScale(f_scale), mLacunarity(lacunarity), mGain(gain), mKd(kd), mKa(ka), mSpecularColor(spec_color), mN(n) 
		{
		
		}
void PhongMarbleMaterial::shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, float attenuation, int depth) const
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
	

	Vector T(hit_position.x(),hit_position.y(),hit_position.z());
	T *= mScale*mFreqScale;
	double value = cos(hit.uvw.x()*mScale + mTurbScale*turbulenceAbs(mOctaves, Point(T.x(), T.y(), T.z()), mLacunarity, mGain));
	value = value*0.5 + 0.5;
	Color c = mColor1*(1 - value) + mColor2*value;
	
	result *= c;
	result += specular_light * mSpecularColor;
	
}
