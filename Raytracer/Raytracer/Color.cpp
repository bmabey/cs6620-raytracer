/*
 *  Color.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *  Copyright 2007. All rights reserved.
 *
 */

#include "Color.h"

Color::Color(float r, float g, float b) : mR(r), mG(g), mB(b) {}

//Operations with other Color objects
Color operator+ (const Color &lhs_color, const Color &rhs_color)
{
	return Color(	lhs_color.mR + rhs_color.mR,
								lhs_color.mG + rhs_color.mG,
								lhs_color.mB + rhs_color.mB); 
}
Color operator* (const Color &lhs_color, const Color &rhs_color)
{
	return Color(	lhs_color.mR * rhs_color.mR,
								lhs_color.mG * rhs_color.mG,
								lhs_color.mB * rhs_color.mB); 
}

Color operator/ (const Color &lhs_color,const Color &rhs_color)
{
	return Color(	lhs_color.mR / rhs_color.mR,
								lhs_color.mG / rhs_color.mG,
								lhs_color.mB / rhs_color.mB); 
}

Color& Color::operator= (const Color &rhs_color)
{
	mR = rhs_color.getR();
	mG = rhs_color.getG();
	mB = rhs_color.getB();
	return *this;
}

Color& Color::operator+= (const Color &rhs_color)
{
	*this = *this + rhs_color;
	return *this;
}

Color& Color::operator*= (const Color &rhs_color)
{
	*this = *this * rhs_color;
	return *this;
}

Color& Color::operator/= (const Color &rhs_color)
{
	*this = *this / rhs_color;
	return *this;
}

//Operations with scalars	

Color operator*(const Color &color, float scalar)
{
	return Color(	color.mR * scalar,
								color.mG * scalar,
								color.mB * scalar);
}

Color operator*(float scalar, const Color &color)
{
	return Color(	color.mR * scalar,
								color.mG * scalar,
								color.mB * scalar);
}


Color operator/ (const Color &color, float scalar)
{
	return Color(	color.mR / scalar,
								color.mG / scalar,
								color.mB / scalar);
}

Color& Color::operator*= (float scalar)
{
	*this = *this * scalar;
	return *this;
}

Color& Color::operator/= (float scalar)
{
	*this = *this / scalar;
	return *this;
}

//Clamp to 0-1
void Color::clamp()
{
	if (mR > 1.0f) mR = 1.0f;
	if (mG > 1.0f) mG = 1.0f;
	if (mB > 1.0f) mB = 1.0f;
	if (mR < 0.0f) mR = 0.0f;
	if (mG < 0.0f) mG = 0.0f;
	if (mB < 0.0f) mB = 0.0f;
}