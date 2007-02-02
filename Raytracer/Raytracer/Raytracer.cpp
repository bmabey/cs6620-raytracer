/*
 *  Raytracer.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "Raytracer.h"


void Raytracer::run()
{
	int xres = 512;
	int yres = 512;
	
	//Image image(xres,yres);
	image.setAll(Color(1.0f,1.0f,1.0f));
	
	//Our spheres
	Sphere sphere1(Point(0.0f, 0.2f, 1.1f), 1.0f);
	Sphere sphere2(Point(1.4f, 1.5f, 1.2f), 1.3f);
	Sphere sphere3(Point(-1.5f,-0.5f, 1.0f), 1.9f);

	for(int i=0;i<yres;i++){ 
	for(int j=0;j<xres;j++){ 
		Color result; 
		float x = 2 * (j - xres/2. + 0.5)/xres; 
		float y = 2 * (i - yres/2. + 0.5)/yres; 
		Ray ray(Point(0.0f,0.0f,-3.0f), Vector(x, y, 1.0f)); 
		if(sphere1.intersects(ray)) 
			result = Color(1, .4, 1); 
		else if(sphere2.intersects(ray)) 
			result = Color(.2, .3, 1); 
		else if(sphere3.intersects(ray)) 
			result = Color(1, .3, .2); 
		else 
			result = Color(.2, .1, .5); 
		image.set(j, i, result); 
		} 
	}

	image.writePPM();
}