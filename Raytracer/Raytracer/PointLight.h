/*
 *  PointLight.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_ 1

#include "Light.h"
#include "RPoint.h"
#include "Color.h"

class PointLight : public Light
{
public:
	PointLight() {}
	PointLight(const RPoint& p, const Color& c) : position(p), color(c) { }
	~PointLight() {}
	
	void getLight(Color& light_color, Vector& light_direction,
												const RenderContext& context, const RPoint& pos) const;

	RPoint position;
	Color color;
};


#endif