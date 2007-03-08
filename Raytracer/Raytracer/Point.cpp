/*
 *  Point.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */

#include "Point.h"

#include "Vector.h"



//Operations with other vectors, points


Point operator+(const Point& p, const Vector& v)
{
	return Point(p.mCoord[0]+v.mCoord[0], p.mCoord[1]+v.mCoord[1], p.mCoord[2]+v.mCoord[2]);
}
Point operator-(const Point& p, const Vector& v)
{
	return Point(p.mCoord[0]-v.mCoord[0], p.mCoord[1]-v.mCoord[1], p.mCoord[2]-v.mCoord[2]);
}

Point operator+(const Point& p1, const Point& p2)
{
	return Point(p1.x() + p2.x(), p1.y() + p2.y(), p1.z() + p2.z());
}

Point operator/(const Point&p, float s)
{
	return Point(p.x()/s, p.y()/s, p.z()/s);
}


//Modifing opers
Point& Point::operator=(const Point& rhs)
{
	mCoord[0] = rhs.mCoord[0]; mCoord[1] = rhs.mCoord[1]; mCoord[2] = rhs.mCoord[2];
	return *this;
}

Point& Point::operator+=(const Vector& v)
{
	*this = *this + v;
	return *this;
}
Point& Point::operator-=(const Vector& v)
{
	*this = *this - v;
	return *this;
}


