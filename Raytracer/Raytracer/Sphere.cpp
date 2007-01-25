/*
 *  Sphere.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#include "Sphere.h"

bool Sphere::intersects(const Ray& ray)
{
	
	Vector o_minus_c = ray.o - center;
	float a = dot(ray.d, ray.d);
	float b = 2 * dot(ray.d, o_minus_c);
	float c = dot(o_minus_c, o_minus_c) - (radius*radius);
	
	float disc = b*b - 4*a*c;
	
	return (disc > 0);
	/*
	Vector o_minus_c = ray.o - center;
	Vector d = ray.d;
	float d_dot_d = d.dot(ray.d);
	Vector temp = o_minus_c;
	float o_minus_c_dot = temp.dot(o_minus_c); 
	float r2 = radius * radius;
	float d_dot_o_minus_c = d.dot(o_minus_c);
	float disc = (d_dot_o_minus_c * d_dot_o_minus_c) - (d_dot_d*( o_minus_c_dot * r2));
	return (disc > 0.0f); 
	*/
	return false;
}
