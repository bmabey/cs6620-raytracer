/*
 *  SpherePolar.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 3/12/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "SpherePolar.h"
#include "Material.h"
#include "HitRecord.h"
#include "Point.h"
#include "BoundingBox.h"
#include "RenderContext.h"




SpherePolar::SpherePolar(Material* m, Point c, float r, const Vector& z, const Vector& x) : mCenter(c), mRadius(r), mRadius2(r*r), mX(x), mZ(z) 
{ 
	material = m;
	boundingBox = BoundingBox(Point(mCenter.x() - mRadius, mCenter.y() - mRadius, mCenter.z() - mRadius),
														Point(mCenter.x() + mRadius, mCenter.y() + mRadius, mCenter.z() + mRadius));
	mY = cross(z, x);
	mZ.normalize();
	mX.normalize();
	mY.normalize();
}

bool SpherePolar::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	bool makes_hit = false;
	Vector o_minus_c = ray.o - mCenter;
	double a = dot(ray.d, ray.d);
	double b = 2.0 * dot(ray.d, o_minus_c);
	double c = dot(o_minus_c, o_minus_c) - (mRadius2);
	
	double disc = b*b - 4.0*a*c;
	
	//Does it intersect?
	if (disc > 0)
	{
		disc = sqrt(disc);
		double t = (-b - disc) / (2.0*a);
		//Early termination
		if (hit.hit(t, this, material))
		{
			makes_hit = true;
		}
		else
		{
			t = ( -b + disc) / (2.0*a);
			makes_hit = (hit.hit(t, this, material));	
		}
	}
	if (makes_hit)
	{	
		Point p = ray.pointAtParam(hit.t);
		double x = dot(p - mCenter, mX);
		double y = dot(p - mCenter, mY);
		double z = dot(p - mCenter, mZ);

		double R = sqrt(x*x + y*y + z*z);
		double theta = acos(z/R);
		double phi = atan2(y, x);
		
		double one_over_2pi = .159154943092;
		double one_over_pi = .318309886184;

		hit.uvw.setX( phi*one_over_2pi );
		if(hit.uvw.x() < 0.0)
			hit.uvw.setX(hit.uvw.x() + 1.0);
		hit.uvw.setY(1 - theta*one_over_pi);
		hit.uvw.setZ(R); 
	}
	
	return makes_hit;
	
	
}

void SpherePolar::getNormal(Vector& N, const HitRecord& record, const Point& pos) const
{
	N = pos - mCenter;
	N.normalize();
}
