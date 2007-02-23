/*
 *  Heightfield.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 2/13/07.
 *
 */

#include "Heightfield.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"
#include <algorithm>
using std::min;
using std::max;



Heightfield::Heightfield(Material* m, string filename, Point min, Point max)
: mMin(min), mMax(max)
{
	
	material = m;
		
	//Read in the file using the code provided.... 
	ifstream in(filename.c_str());
	if(!in)
	{
		cerr << "Error opening " << filename << "\n";
		exit(1);
	}

 in >> mNx >> mNy >> mMinz >> mMaxz;
 
 mMin.setZ(mMinz);
 mMax.setZ(mMaxz);
 mD = mMax - mMin;
 mBoundingBox = new Box(m, mMin,mMax);
 
 if(!in)
 {
	 cerr << "Error reading hader from " << filename << "\n";
	 exit(1);
 }
 in.get();
 mData = new float*[mNx+1];
 mP = new float[(mNx+1)*(mNy+1)];
 for(int i=0;i<=mNx;i++)
	 mData[i] = mP+i*(mNy+1);
 in.read((char*)mData[0], sizeof(float)*(mNx+1)*(mNy+1));
 if(!in)
 {
	 cerr << "Error reading data from " << filename << "\n";
	 exit(1);
 }

	mCellsize = Vector(mD.x()/mNx, mD.y()/mNy, mD.z());
}

Heightfield::~Heightfield()
{
	delete mBoundingBox;
	delete[] mData;
	delete[] mP;
}



bool Heightfield::intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const
{
	float tnear, tfar;
	//Should I set tnear to 0 for rays that start inside?
	tnear =0.0f;
	//Step 2: Compute tnear
	if(mBoundingBox->intersect(tnear, tfar, ray))
	{
	
		//Step 3: Compute lattice coords of near point
		//Find the point in world space where intersection happens...
		Point P = ray.pointAtParam(tnear);
		
		//Now get into lattice space.
		int Lx = (int)( (P.x()-mMin.x() ) / mCellsize.x());
		int Ly = (int)( (P.y()-mMin.y() ) / mCellsize.y());
		//Clamp them
		if (Lx < 0) Lx = 0;
		else if(Lx >= mNx) Lx = mNx - 1;
		if (Ly < 0) Ly = 0;
		else if(Ly >= mNy) Ly = mNy - 1;

		//Step 4, determine march
		float diy = (mD.y() * ray.d.y() > 0) ? 1 : -1; 
		float stopy = (diy==1) ? mNy : -1;
		float dix = (mD.x() * ray.d.x() > 0) ? 1 : -1; 
		float stopx = (dix==1) ? mNx : -1;

		//Step 5, how t changes with ray march
		float dtdx = fabs( mCellsize.x() / ray.d.x() );
		float dtdy = fabs( mCellsize.y() / ray.d.y() );
		
		
		//Step 6, determine the far edges of the cell
		float farx = (dix == 1) ? (Lx + 1) : Lx;
		farx = farx * mCellsize.x() + mMin.x();
		float fary = (diy == 1) ? (Ly + 1) : Ly;
		fary = fary * mCellsize.x() + mMin.y();		
			  
		//Step 7, determine t value of far slabs
		float tnext_x = ( farx - ray.o.x() ) / ray.d.x();
		float tnext_y = ( fary - ray.o.y() ) / ray.d.y();
		
		//Step 8, beginning of loop- compute range of Z values

		float zenter = ray.o.z() + tnear * ray.d.z();
		tfar = min(tfar, (float) hit.t);
		
		while(tnear < tfar)
		{
			float texit = min(tnext_x, tnext_y);
			float zexit = ray.o.z() + texit * ray.d.z();
			
			//Step 9, determine overlap of z range
			/*float lxy = data[Lx][Ly];      
			float lxy1 = data[Lx][Ly+1];    
			float lx1y = data[Lx+1][Ly];   
			float lx1y1 = data[Lx+1][Ly+1];
		Changing names to match slides...
				*/
			float z00 = mData[Lx][Ly];      
			float z01 = mData[Lx][Ly+1];    
			float z10 = mData[Lx+1][Ly];    
			float z11 = mData[Lx+1][Ly+1];
			
			float datamin = min( min(z00, z01), min(z10, z11) );			
			float zmin = min(zenter, zexit);
			float datamax = max( max(z00, z01), max(z10, z11) );
			float zmax = max(zenter, zexit);
			

			if((zmin < datamax) && (zmax > datamin))
			{
				//Step 10
				//Ray-patch intersection v3
				Point E = ray.o + tnear * ray.d;
				Point C;
				C.mCoord[0] = mMin.x() + Lx * mCellsize.x();
				C.mCoord[1] = mMin.y() + Ly * mCellsize.y();
				C.mCoord[2] = 0;
				Vector EC = E - C;
				
				float Sx = EC.x() / mCellsize.x();
				float Sy = EC.y() / mCellsize.y();
				float Dx = ray.d.x() / mCellsize.x();
				float Dy = ray.d.y() / mCellsize.y();
				//Using variables from slide...
				float Zc = z00;
				float Zu = z10 - z00;
				float Zv = z01 - z00;
				float Zuv = z11 - z10 - z01 + z00;
							
				float sxdysydx = Sx*Dy + Sy*Dx;
				float zudxzvdy = Zu*Dx + Zv*Dy;
				
				float a = Dx*Dy*Zuv;
				float b = zudxzvdy + Zuv * sxdysydx - ray.d.z();
				float c = Zc - E.z() + Zu*Sx + Zv*Sy + Zuv*Sx*Sy;
			
					{
					float discriminant = (b * b) - (4.0f * a * c);

					if(discriminant > 0.)
					{
						discriminant = sqrt(discriminant);
						float t1 = (-b + discriminant) / (2.0*a);
						float t2 = (-b - discriminant) / (2.0*a);
						
						if(t1 >= 0 && tnear+t1 <= texit)
							if(hit.hit(tnear+t1, this, material))
							   {
								   if(t2 >= 0)
									   hit.hit(tnear+t2, this, material);
									/*
									mZu=Zu;
									mZv=Zv;
									mZuv=Zuv;
									mSx=Sx;
									mSy=Sy;
									mDx=Dx;
									mDy=Dy;*/
									HeightfieldData* data = hit.getScratchpad<HeightfieldData>();
									data->Zu = Zu;
									data->Zv = Zv;
									data->Zuv = Zuv;
									data->Sx = Sx;
									data->Sy = Sy;
									data->Dx = Dx;
									data->Dy = Dy;
									return true;
							   }
					}
				}
				
			}
			
			zenter = zexit;
			
			//Step 11, march to next cell
			if(tnext_x < tnext_y)
			{
				tnear = tnext_x;
				tnext_x += dtdx;
				Lx += dix;
				if(Lx == stopx)
					break;
			}
			else
			{
				tnear = tnext_y;
				tnext_y += dtdy;
				Ly += diy;
				if(Ly == stopy)
					break;
			}
			
		}
	}
	return false;
}

void Heightfield::getNormal(Vector& N, const HitRecord& hit, const Point& pos) const
{
	//Patch normals...
	//Vector n( -( (mZu + mSy)/mCellsize.x() ), -( (mZv + (mZuv*mSx)) / mCellsize.x() ), 1.0f );
	HeightfieldData* data = hit.getScratchpad<HeightfieldData>();
	Vector n( -( (data->Zu + data->Zuv*data->Sy)/mCellsize.x() ), -( (data->Zv + (data->Zuv*data->Sx)) / mCellsize.x() ), 1.0f );
	
	
	n.normalize();
	N = n;
	
}

