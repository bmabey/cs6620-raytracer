/*
 *  PointLight.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#include "PointLight.h"
#include "Vector.h"

void PointLight::getLight(Color& light_color, Vector& light_direction,
											const RenderContext& context, const Point& pos) const
{
	light_color = color;
	light_direction = position - pos;
	light_direction.normalize();
}


