/*
 *  PointLight.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#include "PointLight.h"
#include "Vector.h"
#include "HitRecord.h"

void PointLight::getLight(Color& light_color, Vector& light_direction,
											const RenderContext& context, const Point& pos, HitRecord& record) const
{
	light_color = color;
	light_direction = position - pos;
	light_direction.normalize();
	float x = position.x() - pos.x();
	float y = position.y() - pos.y();
	float z = position.z() - pos.z();
	record.t = sqrt(x*x + y*y + z*z);
}


