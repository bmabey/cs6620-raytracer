/*
 *  Light.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _LIGHT_H_
#define _LIGHT_H_ 1

class Vector;
class Point;
class Color;
class RenderContext;
class HitRecord;

class Light
{

public:
	
	Light() {};
	virtual ~Light() {};
	virtual void preprocess() {};  
	virtual void getLight(Color& light_color, Vector& light_direction,
												const RenderContext& context, const Point& pos, HitRecord& record) const = 0;

	
};


#endif
