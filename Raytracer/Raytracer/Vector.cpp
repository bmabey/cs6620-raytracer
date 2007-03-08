/*
 *  Vector.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.ß
 *
 */

#include "Vector.h"

#include "Point.h"

const double Vector::PI = 3.14159265358979323846;






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

Vector normalize(const Vector &v)
{
	float l = v.length();
	return v / l;
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
Vector operator+(float scalar, const Vector& vector)
{
	return Vector(vector.mCoord[0]+scalar,vector.mCoord[1]+scalar,vector.mCoord[2]+scalar);
}
Vector operator+(const Vector& vector, float scalar)
{
	return Vector(vector.mCoord[0]+scalar,vector.mCoord[1]+scalar,vector.mCoord[2]+scalar);
}
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





