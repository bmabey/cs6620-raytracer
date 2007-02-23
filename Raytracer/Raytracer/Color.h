/*
 *  Color.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */

#ifndef _COLOR_H_
#define _COLOR_H_ 1

#include <algorithm>
using std::max;

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
	unsigned char getCharR() const { return charify(mR); }
	unsigned char getCharG() const { return charify(mG); }
	unsigned char getCharB() const { return charify(mB); }
	int getIntR()  { return intify(mR); }
	int getIntG()  { return intify(mG); }
	int getIntB()  { return intify(mB); }
	//Returns the max of the three RGB values.
	float getMax() {  return ( (mR > mG) && (mR > mB)) ? mR : max(mG, mB); }
	
	//Operations with other Color objects
	//Make them friends so they share!
	friend Color operator+ (const Color &lhs_color, const Color &rhs_color);
	friend Color operator* (const Color &lhs_color, const Color &rhs_color);
	friend Color operator/ (const Color &lhs_color,const Color &rhs_color);
	
	Color& operator= (const Color &rhs_color);
	Color& operator+= (const Color &rhs_color);
	Color& operator*= (const Color &rhs_color);
	Color& operator/= (const Color &rhs_color);
	
	//Pixel toPixel() const;
	
	//Operations with scalars	
	friend Color operator-(float scalar, const Color& color);
	friend Color operator-(const Color& color, float scalar);
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
	unsigned char const charify(float value) const;
	int const intify(float value);

};

#endif