/*
 *  Matrix.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/10/07.
 *  Based from code in Realistic Raytracing 2nd Ed by Peter Shirley and R. keith Morley
 */

#include "Matrix.h"
#include "Vector.h"
#include "Point.h"
#include <math.h>



Matrix::Matrix(const Matrix& right)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] = right.x[i][j];
}
	
void Matrix::invert()
{
	float det = determinant();
	Matrix inverse;
	
	inverse.x[0][0] =  det3(x[1][1], x[1][2], x[1][3],
					x[2][1], x[2][2], x[2][3],
					x[3][1], x[3][2], x[3][3]) / det;
	inverse.x[0][1] = -det3(x[0][1], x[0][2], x[0][3],
					x[2][1], x[2][2], x[2][3],
					x[3][1], x[3][2], x[3][3]) / det;
	inverse.x[0][2] =  det3(x[0][1], x[0][2], x[0][3],
					x[1][1], x[1][2], x[1][3],
					x[3][1], x[3][2], x[3][3]) / det;
	inverse.x[0][3] = -det3(x[0][1], x[0][2], x[0][3],
					x[1][1], x[1][2], x[1][3],
					x[2][1], x[2][2], x[2][3]) / det;

	inverse.x[1][0] = -det3(x[1][0], x[1][2], x[1][3],
					x[2][0], x[2][2], x[2][3],
					x[3][0], x[3][2], x[3][3]) / det;
	inverse.x[1][1] =  det3(x[0][0], x[0][2], x[0][3],
					x[2][0], x[2][2], x[2][3],
					x[3][0], x[3][2], x[3][3]) / det;
	inverse.x[1][2] = -det3(x[0][0], x[0][2], x[0][3],
					x[1][0], x[1][2], x[1][3],
					x[3][0], x[3][2], x[3][3]) / det;
	inverse.x[1][3] =  det3(x[0][0], x[0][2], x[0][3],
					x[1][0], x[1][2], x[1][3],
					x[2][0], x[2][2], x[2][3]) / det;

	inverse.x[2][0] =  det3(x[1][0], x[1][1], x[1][3],
					x[2][0], x[2][1], x[2][3],
					x[3][0], x[3][1], x[3][3]) / det;
	inverse.x[2][1] = -det3(x[0][0], x[0][1], x[0][3],
					x[2][0], x[2][1], x[2][3],
					x[3][0], x[3][1], x[3][3]) / det;
	inverse.x[2][2] =  det3(x[0][0], x[0][1], x[0][3],
					x[1][0], x[1][1], x[1][3],
					x[3][0], x[3][1], x[3][3]) / det;
	inverse.x[2][3] = -det3(x[0][0], x[0][1], x[0][3],
					x[1][0], x[1][1], x[1][3],
					x[2][0], x[2][1], x[2][3]) / det;

	inverse.x[3][0] = -det3(x[1][0], x[1][1], x[1][2],
					x[2][0], x[2][1], x[2][2],
					x[3][0], x[3][1], x[3][2]) / det;
	inverse.x[3][1] =  det3(x[0][0], x[0][1], x[0][2],
					x[2][0], x[2][1], x[2][2],
					x[3][0], x[3][1], x[3][2]) / det;
	inverse.x[3][2] = -det3(x[0][0], x[0][1], x[0][2],
					x[1][0], x[1][1], x[1][2],
					x[3][0], x[3][1], x[3][2]) / det;
	inverse.x[3][3] =  det3(x[0][0], x[0][1], x[0][2],
					x[1][0], x[1][1], x[1][2],
					x[2][0], x[2][1], x[2][2]) / det;

	*this = inverse;
}

void Matrix::transpose()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			float temp = x[i][j];
			x[i][j] = x[j][i];
			x[j][i] = temp;
		}
	}
}

Matrix Matrix::getInverse() const
{
	Matrix ret = *this;
	ret.invert();
	return ret;
}

Matrix Matrix::getTranspose() const
{
	Matrix ret = *this;
	ret.transpose();
	return ret;
}

Matrix& Matrix::operator+=(const Matrix& right)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] += right.x[i][j];
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& right)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] -= right.x[i][j];
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& right)
{
	Matrix ret = *this;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			float sum = 0;
			for(int k = 0; k < 4; k++)
				sum += ret.x[i][k] * right.x[k][j];
			x[i][j] = sum;
		}
	}
	
	return *this;
}

Matrix& Matrix::operator*=(float right)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] *= right;
	return *this;
}
	


Matrix operator+(const Matrix& left, const Matrix& right)
{
	Matrix ret;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = left.x[i][j] + right.x[i][j];
	return ret;
}

Matrix operator-(const Matrix& left, const Matrix& right)
{
	Matrix ret;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = left.x[i][j] - right.x[i][j];
	return ret;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
	Matrix ret;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			float subt = 0;
			for(int k = 0; k < 4; k++)
				subt += left.x[i][k] * right.x[k][j];
			ret.x[i][j] = subt;
		}
	
	return ret;
}

Vector operator*(const Matrix& left, const Vector& right)
{
	Vector ret;
	float temp;

	ret.setX(right.getX() * left.x[0][0] + right.getY() * left.x[0][1] + right.getZ() * left.x[0][2] + left.x[0][3]);
	ret.setY(right.getX() * left.x[1][0] + right.getY() * left.x[1][1] + right.getZ() * left.x[1][2] + left.x[1][3]);
	ret.setZ(right.getX() * left.x[2][0] + right.getY() * left.x[2][1] + right.getZ() * left.x[2][2] + left.x[2][3]);
	temp   = right.getX() * left.x[3][0] + right.getY() * left.x[3][1] + right.getZ() * left.x[3][2] + left.x[3][3];

	ret /= temp;
	return ret;
}

Point operator*(const Matrix& left, const Point& right)
{
	Point ret;
	float temp;

	ret.setX(right.getX() * left.x[0][0] + right.getY() * left.x[0][1] + right.getZ() * left.x[0][2] + left.x[0][3]);
	ret.setY(right.getX() * left.x[1][0] + right.getY() * left.x[1][1] + right.getZ() * left.x[1][2] + left.x[1][3]);
	ret.setZ(right.getX() * left.x[2][0] + right.getY() * left.x[2][1] + right.getZ() * left.x[2][2] + left.x[2][3]);
	temp   = right.getX() * left.x[3][0] + right.getY() * left.x[3][1] + right.getZ() * left.x[3][2] + left.x[3][3];

	ret = ret/temp;
	return ret;
}

Matrix operator*(const Matrix& left, float right)
{
	Matrix ret;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = left.x[i][j] * right;
	return ret;
}
	
Vector transformLoc(const Matrix& left, const Vector& right)
{
	return left * right;
}

Point transformLoc(const Matrix& left, const Point& right)
{
	return left * right;
}

Vector transformVec(const Matrix& left, const Vector& right)
{
	Vector ret;
	
	ret.setX(right.getX() * left.x[0][0] + right.getY() * left.x[0][1] + right.getZ() * left.x[0][2]);
	ret.setY(right.getX() * left.x[1][0] + right.getY() * left.x[1][1] + right.getZ() * left.x[1][2]);
	ret.setZ(right.getX() * left.x[2][0] + right.getY() * left.x[2][1] + right.getZ() * left.x[2][2]);

	return ret;
}


Matrix zeroMatrix()
{
	Matrix ret;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = 0;
	return ret;
}

Matrix identityMatrix()
{
	Matrix ret;
	ret.x[0][0] = 1.0; ret.x[0][1] = 0.0; ret.x[0][2] = 0.0; ret.x[0][3] = 0.0;
	ret.x[1][0] = 0.0; ret.x[1][1] = 1.0; ret.x[1][2] = 0.0; ret.x[1][3] = 0.0;
	ret.x[2][0] = 0.0; ret.x[2][1] = 0.0;	ret.x[2][2] = 1.0; ret.x[2][3] = 0.0;
	ret.x[3][0] = 0.0; ret.x[3][1] = 0.0;	ret.x[3][2] = 0.0; ret.x[3][3] = 1.0;
	return ret;
}

Matrix translate(float x, float y, float z)
{
	Matrix ret = identityMatrix();
	ret.x[0][3] = x;
	ret.x[1][3] = y;
	ret.x[2][3] = z;
	return ret;
}

Matrix scale(float x, float y, float z)
{
	Matrix ret = zeroMatrix();
	ret.x[0][0] = x;
	ret.x[1][1] = y;
	ret.x[2][2] = z;
	ret.x[3][3] = 1.0;
	return ret;
}

Matrix rotate(const Vector& axis, float angle)
{
	Vector axisC = axis;
	axisC.normalize();
	Matrix ret;
	float x = axisC.x();
	float y = axisC.y();
	float z = axisC.z();
	float cosine = cos(angle);
	float sine = sin(angle);
	float t = 1 - cosine;

	ret.x[0][0] = t * x * x + cosine;
	ret.x[0][1] = t * x * y - sine * y;
	ret.x[0][2] = t * x * z + sine * y;
	ret.x[0][3] = 0.0;

	ret.x[1][0] = t * x * y + sine * z;
	ret.x[1][1] = t * y * y + cosine;
	ret.x[1][2] = t * y * z - sine * x;
	ret.x[1][3] = 0.0;

	ret.x[2][0] = t * x * z - sine * y;
	ret.x[2][1] = t * y * z + sine * x;
	ret.x[2][2] = t * z * z + cosine;
	ret.x[2][3] = 0.0;

	ret.x[3][0] = 0.0;
	ret.x[3][1] = 0.0;
	ret.x[3][2] = 0.0;
	ret.x[3][3] = 1.0;

	return ret;
}

Matrix rotateX(float angle)
{
	Matrix ret = identityMatrix();
	float cosine = cos(angle);
	float sine = sin(angle);
	
	ret.x[1][1] = cosine;
	ret.x[1][2] = -sine;
	ret.x[2][1] = sine;
	ret.x[2][2] = cosine;

	return ret;
}

Matrix rotateY(float angle)
{
	Matrix ret = identityMatrix();
	float cosine = cos(angle);
	float sine = sin(angle);

	ret.x[0][0] = cosine;
	ret.x[0][2] = sine;
	ret.x[2][0] = -sine;
	ret.x[2][2] = cosine;

	return ret;
}

Matrix rotateZ(float angle)
{
	Matrix ret = identityMatrix();
	float cosine = cos(angle);
	float sine = sin(angle);

	ret.x[0][0] = cosine;
	ret.x[0][1] = -sine;
	ret.x[1][0] = sine;
	ret.x[1][1] = cosine;

	return ret;
}

ostream& operator<<(ostream& out, const Matrix& right)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			out << setprecision(3) << setw(10) << right.x[i][j];
		out << endl;
	}
	return out;
}
	
float Matrix::determinant()
{
	float det;
	det = x[0][0] * det3(x[1][1], x[1][2], x[1][3],
					x[2][1], x[2][2], x[2][3],
					x[3][1], x[3][2], x[3][3]);
	det -= x[0][1] * det3(x[1][0], x[1][2], x[1][3],
					x[2][0], x[2][2], x[2][3],
					x[3][0], x[3][2], x[3][3]);
	det += x[0][2] * det3(x[1][0], x[1][1], x[1][3],
					x[2][0], x[2][1], x[2][3],
					x[3][0], x[3][1], x[3][3]);
	det -= x[0][3] * det3(x[1][0], x[1][1], x[1][2],
					x[2][0], x[2][1], x[2][2],
					x[3][0], x[3][1], x[3][2]);

	return det;
}
