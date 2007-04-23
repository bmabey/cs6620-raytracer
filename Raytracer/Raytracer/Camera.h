/*
 *  Camera.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _CAMERA_H_
#define _CAMERA_H_ 1



class Ray;
class RenderContext;
class Sample;

class Camera
{

public:
	
	Camera() {}
	virtual ~Camera() {}
	//virtual void preprocess(float  aspect_ratio) = 0;   Don't know how he wants us to use this yet...
	virtual void makeRay(Ray& ray, const RenderContext& context, double x, double y, double a, double b) const = 0;
	Sample* samples; 

	
};


#endif
