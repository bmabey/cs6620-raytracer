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
	Vector(float x, float y, float z);
	
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
	float length() const;
	float length2() const;  //The squared length
	void normalize();
	float dot(const Vector &v);
	Vector cross(const Vector &v);
	friend Vector cross(const Vector& lhs, const Vector& rhs); 
	friend float dot(const Vector& lhs, const Vector& rhs);
	friend Vector normalize(const Vector& v);  
	void inverse();
	Vector operator-();
	
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
	
	
	//Modifing opers
	Vector& operator=(const Vector& rhs);
	Vector& operator+=(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
	Vector& operator*=(float scalar);
	Vector& operator/=(float scalar);


	static const double PI;
	
//private:
	float mCoord[3];
	
};

#endif
