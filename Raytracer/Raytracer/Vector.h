/*
 *  Vector.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */

#ifndef _VECTOR_H_
#define _VECTOR_H_ 1

#include <math.h>

class Point;

class Vector
{

public:
	Vector() { };
	Vector(float x, float y, float z)
	{
		mCoord[0] = x;
		mCoord[1] = y;
		mCoord[2] = z;
	}
	
	//Setters
	void setX(float x) { mCoord[0] = x; }
	void setY(float y) { mCoord[1] = y; }
	void setZ(float z) { mCoord[2] = z; }
	//Getters
	float x() const {return mCoord[0];}
	float getX() const {return mCoord[0];} 
	float y() const {return mCoord[1];}
	float getY() const {return mCoord[1];}
	float z() const {return mCoord[2];}
	float getZ() const {return mCoord[2];}
	float operator[](int index) const { return mCoord[index]; }
	
	
	//Useful math methods
	
	float length() const { return sqrt(mCoord[0]*mCoord[0] + mCoord[1]*mCoord[1] + mCoord[2]*mCoord[2]); }
	float length2() const { return (mCoord[0]*mCoord[0] + mCoord[1]*mCoord[1] + mCoord[2]*mCoord[2]);}
	//void normalize();
	void normalize() 
	{
		float l = 1.0f / length();
		mCoord[0] = mCoord[0] * l; 
		mCoord[1] = mCoord[1] * l; 
		mCoord[2] = mCoord[2] * l; 
	}
	
	
	float dot(const Vector &v) { return (mCoord[0]*v[0] + mCoord[1]*v[1] +	mCoord[2]*v[2]); }
	void inverse() { 	mCoord[0] = -mCoord[0];	mCoord[1] = -mCoord[1];	mCoord[2] = -mCoord[2];	}
	Vector operator-() { 	return Vector(-mCoord[0], -mCoord[1], -mCoord[2]);	}

	Vector cross(const Vector &v)	
	{
	Vector product;
	product.mCoord[0] = mCoord[1] * v.mCoord[2] - mCoord[2] * v.mCoord[1];
	product.mCoord[1] = mCoord[2] * v.mCoord[0] - mCoord[0] * v.mCoord[2];
	product.mCoord[2] = mCoord[0] * v.mCoord[1] - mCoord[1] * v.mCoord[0];
	return product;
	}
	

	friend Vector cross(const Vector& lhs, const Vector& rhs); 
	friend float dot(const Vector& lhs, const Vector& rhs);
	friend Vector normalize(const Vector& v);  
	

	
	//Operations with other vectors, points
	friend Vector operator+(const Vector& lhs, const Vector& rhs);
	friend Vector operator-(const Vector& lhs, const Vector& rhs);
	friend Vector operator-(const Point& lhs, const Point& rhs);
	
	
	//With scalars...
	friend Vector operator+(float scalar, const Vector& vector);
	friend Vector operator+(const Vector& vector, float scalar);
	friend Vector operator*(const Vector& vector, float scalar);
	friend Vector operator*(float scalar, const Vector& vector);
	friend Vector operator/(const Vector& vector, float scalar);
	
	
	friend Point operator+(const Point& p, const Vector& v);
	friend Point operator-(const Point& p, const Vector& v);
	
	//Modifing opers
	//Modifing opers
	Vector& operator=(const Vector& rhs)
	{
		mCoord[0] = rhs.mCoord[0]; mCoord[1] = rhs.mCoord[1]; mCoord[2] = rhs.mCoord[2];
		return *this;
	}
	Vector& operator+=(const Vector& rhs)
	{
		*this = *this + rhs;
		return *this;
	}
	Vector& operator-=(const Vector& rhs)
	{
		*this = *this - rhs;
		return *this;
	}
	Vector& operator*=(float scalar)
	{
		*this = *this * scalar;
		return *this;
	}
	Vector& operator/=(float scalar)
	{
		*this = *this / scalar;
		return *this;
	}

	static const double PI;
	
private:
	float mCoord[3];
	
};



#endif
