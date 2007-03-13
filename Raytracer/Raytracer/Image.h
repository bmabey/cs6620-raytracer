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
#include "Color.h"
#include <iostream>
#include <stdlib.h>



using namespace std;
typedef struct {
	unsigned char r, g, b;
} Pixel;

class Image
{
public:
	Image() : mWidth(512), mHeight(512) { }
	Image(int width, int height);
	Image(string filename) { readPPM(filename); }
	
	bool set(int x, int y, const Color& color);
	void setAll(Color color);
	void writePPM(ostream& out);
	void writePPM();
	void readPPM(string filename);
	int getXRes() {return mWidth; }
	int getYRes() {return mHeight; }

	Pixel* RGBcanvas;
	
//private:
	Color** mCanvas;
	int mWidth;
	int mHeight;
	
};

#endif