/*
 *  Image.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/17/07.
 *
 */

#include "Image.h"


Image::Image(int width, int height) : mWidth(width), mHeight(height) 
{
	mCanvas = new Color*[mWidth];
	for (int i = 0; i < mWidth; i++)
	{
		mCanvas[i] = new Color[mHeight];
	}
	
}

bool Image::set(int x, int y, const Color& color)
{
	if ((x < 0) || (y < 0) || (x > mWidth) || (y > mHeight)) return false;
	
	mCanvas[x][y] = color;
	return true;
}

void Image::setAll(Color color)
{
	for (int i = 0; i < mWidth; i++)
		for (int j = 0; j < mHeight; j++)
			mCanvas[i][j] = color;
}

void Image::writePPM(ostream& out)
{
cout << "Hello!";
	out << "P3\n" << mWidth << " " << mHeight << "\n" << "255\n";
	Color temp;
	for (int i = mHeight-1; i >= 0; i--)
	{
		for (int j = 0; j < mWidth; j++)
		{
			temp = mCanvas[j][i];
			out << temp.getIntR() << " " << temp.getIntG() << " " << temp.getIntB() << " ";
			/*
			out.put(mCanvas[j][i].getCharR());
			out.put(mCanvas[j][i].getCharG());
			out.put(mCanvas[j][i].getCharB());*/
		}
		out << "\n";
	}
}

void Image::writePPM()
{
	ofstream ppm_file("image.ppm");
	writePPM(ppm_file);
}