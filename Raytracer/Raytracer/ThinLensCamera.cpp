/*
 *  ThinLensCamera.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/15/07.
 *
 */

#include "ThinLensCamera.h"

#include <math.h>
#include "DiskSample.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Point.h"
#include "Vector.h"

ThinLensCamera::ThinLensCamera(const Point& pos, const Point& lookAt, const Vector& up,  float angle, float aspect, float distance, float aperture)
: position(pos), g((lookAt - pos)), mDistance(distance), mAperture(aperture/2.0f)
{
	g.normalize();
	
	u = cross(g, up);
	v = cross(u, g);
	
	u.normalize();
	v.normalize();
	u = u*tan( (angle / 2.0) * Vector::PI / 180.0);
	v = v*tan( (angle / 2.0) * Vector::PI / 180.0) / aspect;
	samples = new DiskSample();
}

void ThinLensCamera::makeRay(Ray& ray, const RenderContext& context, double x, double y,double a, double b) const
{
	ray.o = position;
	ray.d = g + x*u + y*v;
	ray.normalize();
	ray.d = ray.d * mDistance;

	Vector U = a*mAperture*u;
	Vector V = b*mAperture*v;
	Vector UV = U+V;
	ray.o = ray.o + UV;
	ray.d = ray.d - UV;
	ray.d.normalize();
}
