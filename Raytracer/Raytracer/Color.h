/*
 *  Color.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *  Copyright 2007. All rights reserved.
 *
 */

class Color
{
public:
	Color() { mR = mG = mB = 0.0f; }
	Color(float r, float g, float b);
	
	//setters...
	void setR(float r) { mR = r; }
	void setG(float g) { mR = g; }
	void setB(float b) { mR = b; }
	
	//Getters
	float getR() const { return mR; }
	float getG() const { return mG; }
	float getB() const { return mB; }
	
	//Operations with other Color objects
	//Make them friends so they share!
	friend Color operator+ (const Color &lhs_color, const Color &rhs_color);
	friend Color operator* (const Color &lhs_color, const Color &rhs_color);
	friend Color operator/ (const Color &lhs_color,const Color &rhs_color);
	Color& operator= (const Color &rhs_color);
	Color& operator+= (const Color &rhs_color);
	Color& operator*= (const Color &rhs_color);
	Color& operator/= (const Color &rhs_color);
	
	//Operations with scalars	
	
	friend Color operator*(const Color &color, float scalar);
	friend Color operator*(float scalar, const Color &color);
	friend Color operator/ (const Color &color, float scalar);
	Color& operator*= (float scalar);
	Color& operator/= (float scalar);
	void clamp();
	
private:
	float mR;
	float mG;
	float mB;

};