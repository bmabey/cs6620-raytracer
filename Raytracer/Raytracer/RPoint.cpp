/*
 *  RPoint.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */

#include "RPoint.h"

#include "Vector.h"

RPoint::RPoint(float x, float y, float z)
{
	mCoord[0] = x;
	mCoord[1] = y;
	mCoord[2] = z;
}

//Operations with other vectors, points


RPoint operator+(const RPoint& p, const Vector& v)
{
	return RPoint(p.mCoord[0]+v.mCoord[0], p.mCoord[1]+v.mCoord[1], p.mCoord[2]+v.mCoord[2]);
}
RPoint operator-(const RPoint& p, const Vector& v)
{
	return RPoint(p.mCoord[0]-v.mCoord[0], p.mCoord[1]-v.mCoord[1], p.mCoord[2]-v.mCoord[2]);
}


//Modifing opers
RPoint& RPoint::operator=(const RPoint& rhs)
{
	mCoord[0] = rhs.mCoord[0]; mCoord[1] = rhs.mCoord[1]; mCoord[2] = rhs.mCoord[2];
	return *this;
}

RPoint& RPoint::operator+=(const Vector& v)
{
	*this = *this + v;
	return *this;
}
RPoint& RPoint::operator-=(const Vector& v)
{
	*this = *this - v;
	return *this;
}


