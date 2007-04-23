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
#include "Point.h"
#include "Vector.h"

class Ray;
class RenderContext;

class PinholeCamera : public Camera
{
public:
	PinholeCamera() {}
	PinholeCamera(const Point& pos, const Point& lookAt, const Vector& up,  float angle, float aspect = 1.0f);
	~PinholeCamera() {}
	void makeRay(Ray& ray, const RenderContext& context, double x, double y,double a, double b) const ;

private:
	Point position;
	Vector g, u, v;
};

#endif 