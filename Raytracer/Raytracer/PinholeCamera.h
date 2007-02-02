/*
 *  PinholeCamera.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#ifndef _PINHOLECAMERA_H_
#define _PINHOLECAMERA_H_

#include "Camera.h"
#include "RPoint.h"
#include "Vector.h"

class Ray;
class RenderContext;

class PinholeCamera : public Camera
{
public:
	PinholeCamera() {}
	PinholeCamera(const RPoint& pos, const RPoint& lookAt, const Vector& up,  float angle, float aspect = 1.0f);
	~PinholeCamera() {}
	void makeRay(Ray& ray, const RenderContext& context, double x, double y) const ;

	
	RPoint position;
	Vector g, u, v;
};

#endif 