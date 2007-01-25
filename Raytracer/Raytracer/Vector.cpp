/*
 *  Vector.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.ß
 *
 */

#include "Vector.h"

#include "Point.h"

Vector::Vector(float x, float y, float z)
{
	mCoord[0] = x;
	mCoord[1] = y;
	mCoord[2] = z;
}


//Useful math methods
float Vector::length() const
{
	return sqrt(mCoord[0]*mCoord[0] + mCoord[1]*mCoord[1] + mCoord[2]*mCoord[2]);
}
float Vector::length2() const
{
	return (mCoord[0]*mCoord[0] + mCoord[1]*mCoord[1] + mCoord[2]*mCoord[2]);
}
float Vector::dot(const Vector &v)
{
	return (mCoord[0]*v[0] + mCoord[1]*v[1] +	mCoord[2]*v[2]); 
}
Vector Vector::cross(const Vector &v)
{
	Vector product;
	
	product.mCoord[0] = mCoord[1] * v.mCoord[2] - mCoord[2] * v.mCoord[1];
	product.mCoord[1] = mCoord[2] * v.mCoord[0] - mCoord[0] * v.mCoord[2];
	product.mCoord[2] = mCoord[0] * v.mCoord[1] - mCoord[1] * v.mCoord[0];
	
	return product;
}

Vector cross(const Vector &lhs, const Vector &rhs)
{
	Vector product;
	
	product.mCoord[0] = lhs.mCoord[1] * rhs.mCoord[2] - lhs.mCoord[2] * rhs.mCoord[1];
	product.mCoord[1] = lhs.mCoord[2] * rhs.mCoord[0] - lhs.mCoord[0] * rhs.mCoord[2];
	product.mCoord[2] = lhs.mCoord[0] * rhs.mCoord[1] - lhs.mCoord[1] * rhs.mCoord[0];
	
	return product;
}

float dot(const Vector &lhs, const Vector &rhs)
{
	return (lhs.mCoord[0]* rhs.mCoord[0] + lhs.mCoord[1]*rhs.mCoord[1] +	lhs.mCoord[2]*rhs.mCoord[2]); 
}


//Operations with other vectors, points
Vector operator+(const Vector& lhs, const Vector& rhs)
{
	return Vector(lhs.mCoord[0]+rhs.mCoord[0], lhs.mCoord[1]+rhs.mCoord[1], lhs.mCoord[2]+rhs.mCoord[2]);
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
	return Vector(lhs.mCoord[0]-rhs.mCoord[0], lhs.mCoord[1]-rhs.mCoord[1], lhs.mCoord[2]-rhs.mCoord[2]);
}

Vector operator-(const Point& lhs, const Point& rhs)
{
	return Vector(lhs.mCoord[0]-rhs.mCoord[0], lhs.mCoord[1]-rhs.mCoord[1], lhs.mCoord[2]-rhs.mCoord[2]);
}


//With scalars...
Vector operator*(const Vector& vector, float scalar)
{
	return Vector(vector.mCoord[0]*scalar,vector.mCoord[1]*scalar,vector.mCoord[2]*scalar);
}
Vector operator*(float scalar, const Vector& vector)
{
	return Vector(vector.mCoord[0]*scalar,vector.mCoord[1]*scalar,vector.mCoord[2]*scalar);
}
Vector operator/(const Vector& vector, float scalar)
{
	return Vector(vector.mCoord[0]/scalar,vector.mCoord[1]/scalar,vector.mCoord[2]/scalar);
}


//Modifing opers
Vector& Vector::operator=(const Vector& rhs)
{
	mCoord[0] = rhs.mCoord[0]; mCoord[1] = rhs.mCoord[1]; mCoord[2] = rhs.mCoord[2];
	return *this;
}
Vector& Vector::operator+=(const Vector& rhs)
{
	*this = *this + rhs;
	return *this;
}
Vector& Vector::operator-=(const Vector& rhs)
{
	*this = *this - rhs;
	return *this;
}
Vector& Vector::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}
Vector& Vector::operator/=(float scalar)
{
	*this = *this / scalar;
	return *this;
}


