/*
 *  Instance.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 4/10/07.
 *
 */

#include "Instance.h"
#include "Material.h"
#include "HitRecord.h"
#include "Point.h"
#include "BoundingBox.h"
#include "RenderContext.h"
#include <algorithm>
using std::max;
using std::min;

Instance::Instance(Matrix trans, Primitive* p)
: primitive(p), M(trans), Minv(trans)
{
	Minv.invert();	
	boundingBox = primitive->boundingBox;
	computeBoundingBox();
}

bool Instance::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	Point no = transformLoc(Minv, ray.o);
	Vector nd = transformVec(Minv, ray.d);
	
	Ray transformed_ray(no, nd);
	
	if(primitive->intersect(hit, context, transformed_ray))
	{
		
		hit.p = transformLoc(M, hit.p);
		Vector normal;
		hit.primitive->getNormal(normal, hit, hit.p);
		normal.normalize();
		hit.n = transformVec(Minv.getTranspose(), normal);
		hit.n.normalize();
		hit.primitive = this;
		return true;
	}
	else
	{
		return false;
	}
}

void Instance::getNormal(Vector& N, const HitRecord& hit, const Point& pos) const
{
	N = hit.n;
}

void Instance::computeBoundingBox()
{
	Point p1, p2, p3, p4, p5, p6, p7, p8;

	p1 = Point(boundingBox.Min.x(), boundingBox.Min.y(), boundingBox.Min.z());
	p2 = Point(boundingBox.Max.x(), boundingBox.Min.y(), boundingBox.Min.z());
	p3 = Point(boundingBox.Max.x(), boundingBox.Max.y(), boundingBox.Min.z());
	p4 = Point(boundingBox.Min.x(), boundingBox.Max.y(), boundingBox.Min.z());
	p5 = Point(boundingBox.Min.x(), boundingBox.Min.y(), boundingBox.Max.z());
	p6 = Point(boundingBox.Max.x(), boundingBox.Min.y(), boundingBox.Max.z());
	p7 = Point(boundingBox.Max.x(), boundingBox.Max.y(), boundingBox.Max.z());
	p8 = Point(boundingBox.Min.x(), boundingBox.Max.y(), boundingBox.Max.z());

	p1 = transformLoc(M, p1);
	p2 = transformLoc(M, p2);
	p3 = transformLoc(M, p3);
	p4 = transformLoc(M, p4);
	p5 = transformLoc(M, p5);
	p6 = transformLoc(M, p6);
	p7 = transformLoc(M, p7);
	p8 = transformLoc(M, p8);

	float minX, minY, minZ, maxX, maxY, maxZ;
	
	minX = min(min(min(p1.x(), p2.x()), min(p3.x(), p4.x())), min(min(p5.x(), p6.x()), min(p7.x(), p8.x())));
	minY = min(min(min(p1.y(), p2.y()), min(p3.y(), p4.y())), min(min(p5.y(), p6.y()), min(p7.y(), p8.y())));
	minZ = min(min(min(p1.z(), p2.z()), min(p3.z(), p4.z())), min(min(p5.z(), p6.z()), min(p7.z(), p8.z())));

	maxX = max(max(max(p1.x(), p2.x()), max(p3.x(), p4.x())), max(max(p5.x(), p6.x()), max(p7.x(), p8.x())));
	maxY = max(max(max(p1.y(), p2.y()), max(p3.y(), p4.y())), max(max(p5.y(), p6.y()), max(p7.y(), p8.y())));
	maxZ = max(max(max(p1.z(), p2.z()), max(p3.z(), p4.z())), max(max(p5.z(), p6.z()), max(p7.z(), p8.z())));

	boundingBox = BoundingBox(Point(minX, minY, minZ), Point(maxX, maxY, maxZ));
}
