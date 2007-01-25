/*
 *  Image.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */


#ifndef _IMAGE_H_
#define _IMAGE_H_ 1

#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include "Color.h"
using namespace std;

class Image
{
public:
	Image() : mWidth(512), mHeight(512) { }
	Image(int width, int height);
	
	bool set(int x, int y, const Color& color);
	void setAll(Color color);
	void writePPM(ostream& out);
	void writePPM();
	
private:
	Color** mCanvas;
	int mWidth;
	int mHeight;
	
};

#endif