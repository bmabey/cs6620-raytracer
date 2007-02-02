/*
 *  Raytracer.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_ 1

#include "Image.h"
#include "Sphere.h"
#include "Ray.h"
#include "Color.h"

class Raytracer
{

public:
	Raytracer() { };

	void run();
	
	Image image;

	
};

#endif
