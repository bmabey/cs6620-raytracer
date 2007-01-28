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

class Camera
{

public:
	
	Camera() {};
	virtual void preprocess(float  aspect_ratio) = 0; 
	virtual void makeRay(Ray& ray, const RenderContext& context, float x, float y) const = 0; 

	
};


#endif
