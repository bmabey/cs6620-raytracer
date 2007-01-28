/*
 *  SolidBackground.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _SOLIDBACKGROUND_H_
#define _SOLIDBACKGROUND_H_ 1

#include "Ray.h"
#include "Color.h"
#include "RenderContext.h"

class SolidBackground
{

public:
	
	SolidBackground() {}; 
	SolidBackground(const Color& bg) { color = bg; };
	void getBackgroundColor(Color& result, const RenderContext& context, const Ray& ray) { result = color};//Syntax probably wrong...
	
	Color* color;

	
};


#endif