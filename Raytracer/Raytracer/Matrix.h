/*
 *  Matrix.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/10/07.
 *  Based from code in Realistic Raytracing 2nd Ed by Peter Shirley and R. keith Morley
 */


#ifndef _MATRIX_H_
#define _MATRIX_H_

class Vector;
class Point;
#include <iostream.h>
#include <iomanip.h>



class Matrix
{
public:
	Matrix() {}
	Matrix(const Matrix& right);
	~Matrix() {};
	
	void invert();
	void transpose();
	Matrix getInverse() const;
	Matrix getTranspose() const;

	Matrix& operator+=(const Matrix& right);
	Matrix& operator-=(const Matrix& right);
	Matrix& operator*=(const Matrix& right);
	Matrix& operator*=(float right);
	
	
	
	friend Matrix operator-(const Matrix& left, const Matrix& right);
	friend Matrix operator+(const Matrix& left, const Matrix& right);
	friend Matrix operator*(const Matrix& left, const Matrix& right);
	friend Vector operator*(const Matrix& left, const Vector& right);
	//Need to be able to return both point and vector
	friend Point  operator*(const Matrix& left, const Point& right);
	friend Matrix operator*(const Matrix& left, float right);
	
	friend Vector transformLoc(const Matrix& left, const Vector& right);
	friend Point  transformLoc(const Matrix& left, const Point& right);
	friend Vector transformVec(const Matrix& left, const Vector& right);


	friend Matrix zeroMatrix();
	friend Matrix identityMatrix();
	friend Matrix translate(float x, float y, float z);
	friend Matrix scale(float x, float y, float z);
	friend Matrix rotate(const Vector& axis, float angle);
	friend Matrix rotateX(float angle);
	friend Matrix rotateY(float angle);
	friend Matrix rotateZ(float angle);
	friend ostream& operator<<(ostream& out, const Matrix& right);
	
	float determinant();
	float x[4][4];
};

inline float det3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	return a*e*i + d*h*c + g*b*f - g*e*c - d*b*i - a*h*f;
}

#endif 