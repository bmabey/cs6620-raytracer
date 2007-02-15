/*
 *  Heightfield.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/13/07.
 *
 */

#ifndef _HEIGHTFIELD_H_
#define _HEIGHTFIELD_H_ 1

#include "Primitive.h"
#include "Point.h"
#include "Vector.h"
#include "Box.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Heightfield : public Primitive
{
public:
	Heightfield() { }
	Heightfield(Material* m, string filename, Point min, Point max);
	~Heightfield();
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void getNormal(Vector& N, const HitRecord& hit, const Point& pos) const;
private:		
	Box* mBoundingBox;
	Point mMin;
	Point mMax;
	Vector mD;
	Vector mCellsize;
	double mMinz, mMaxz;
	int mNx, mNy;
	float** mData;
	float* mP;
	//Save info for normal calculation...
	//float mZu, mZv, mZuv, mSx, mSy, mDx, mDy;
	
};

struct HeightfieldData
{
	//Save info for normal calculation...
	float Zu, Zv, Zuv, Sx, Sy, Dx, Dy;
};

#endif