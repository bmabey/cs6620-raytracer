/*
 *  PinholeCamera.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/28/07.
 *
 */

#include "PinholeCamera.h"
#include "Ray.h"
#include "Vector.h"
#include "RPoint.h"
#include "RenderContext.h"
#include <math.h>

PinholeCamera::PinholeCamera(const RPoint& pos, const RPoint& lookAt, const Vector& up, float angle, float aspect)
: position(pos), g((lookAt - pos))
{
	g.normalize();
	
	u = cross(g, up);
	v = cross(u, g);
	
	u.normalize();
	v.normalize();
	u = u*tan( (angle / 2.0) * Vector::PI / 180.0);
	v = v*tan( (angle / 2.0) * Vector::PI / 180.0) / aspect;
}

void PinholeCamera::makeRay(Ray& ray, const RenderContext& context, double x, double y) const
{
	ray.o = position;
	ray.d = g + x*u + y*v;
	ray.normalize();
}