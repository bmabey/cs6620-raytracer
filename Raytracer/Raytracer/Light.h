/*
 *  Light.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _LIGHT_H_
#define _LIGHT_H_ 1

#include "Vector.h"
#include "Point.h"
#include "Color.h"
#include "RenderContext.h"

class Light
{

public:
	
	Light() {};
	virtual void preprocess();  
	virtual float getLight(Color& light_color, Vector& light_direction,
												const RenderContext& context, const Point& pos) const = 0;

	
};


#endif
