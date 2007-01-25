/*
 *  Point.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */

#ifndef _POINT_H_
#define _POINT_H_ 1

#include <math.h>

class Vector;

class Point
{

public:
	Point() { };
	Point(float x, float y, float z);
	
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
	
	//Operations with other vectors, points
	friend Point operator+(const Point& p, const Vector& v);
	friend Point operator-(const Point& p, const Vector& v);
	
	//Modifing opers
	Point& operator=(const Point& rhs);
	
	Point& operator+=(const Vector& v);
	Point& operator-=(const Vector& v);
	
//private:
	float mCoord[3];
	
};

#endif
