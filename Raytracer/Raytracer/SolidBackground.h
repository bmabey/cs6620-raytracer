/*
 *  SolidBackground.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _SOLIDBACKGROUND_H_
#define _SOLIDBACKGROUND_H_ 1


#include "Color.h"
#include "Background.h"
class Ray;
class RenderContext;

class SolidBackground : public Background
{

public:
	
	SolidBackground() {}; 
	SolidBackground(const Color& bg) : mColor(bg) { };
	void getBackgroundColor(Color& result, const RenderContext& context, const Ray& ray) { result = mColor; };//Syntax probably wrong...
private:
	Color mColor;

	
};


#endif