/*
 *  ThinLensCamera.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/15/07.
 *
 */

#ifndef _THINLENSCAMERA_H_
#define _THINLENSCAMERA_H_

#include "Camera.h"
#include "Point.h"
#include "Vector.h"

class Ray;
class RenderContext;

class ThinLensCamera : public Camera
{
public:
	ThinLensCamera() {}
	ThinLensCamera(const Point& pos, const Point& lookAt, const Vector& up,  float angle, float aspect, float distance, float aperture);
	~ThinLensCamera() {}
	void makeRay(Ray& ray, const RenderContext& context, double x, double y, double a, double b) const ;

	private:
	Point position;
	Vector g, u, v;
	float mAperture;
	float mDistance;
};

#endif 