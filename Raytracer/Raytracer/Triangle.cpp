/*
 *  Triangle.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/5/07.
 *
 */

#include "Triangle.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"

Triangle::Triangle(Material* m, Point a, Point b, Point c) : 
	mPointA(a), mPointB(b), mPointC(c),
	A(a[0]-b[0]), B(a[1]-b[1]), C(a[2]-b[2]),
	D(a[0]-c[0]), E(a[1]-c[1]), F(a[2]-c[2])
{ 
	material = m;
	Vector t1 = mPointB - mPointA;
	Vector t2 = mPointC - mPointA;
	mNormal = normalize( t1.cross(t2) );
}

bool Triangle::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	float G = ray.d[0];
	float H = ray.d[1];
	float I = ray.d[2];
	
	float J = mPointA[0] - ray.o[0];
	float K = mPointA[1] - ray.o[1];
	float L = mPointA[2] - ray.o[2];
	
	float EImHF = E*I - H*F;
	float GFmDI = G*F - D*I;
	float DHmEG = D*H - E*G;
	
	float denom = ( (A * EImHF) + (B * GFmDI) + (C * DHmEG) );
	float beta = ( (J * EImHF) + (K * GFmDI) + (L * DHmEG) ) / denom;
	
	//Early terminiation
	if (beta <= 0.0f || beta >= 1.0f)
		return false;
		
	float AKmJB = A*K - J*B;
	float JCmAL = J*C - A*L;
	float BLmKC = B*L - K*C;
	
	float gamma = ( (I * AKmJB) + (H * JCmAL) + (G * BLmKC) ) / denom;
	if (gamma <= 0.0f || (beta + gamma) >= 1.0f)
		return false;
	
	double t = -( (F * AKmJB) + (H * JCmAL) + (D * BLmKC)) / denom; 
	return hit.hit(t, this, material);
	
	
}

void Triangle::getNormal(Vector& N, const HitRecord& record, const Point& pos) const
{
	N = mNormal;
}

