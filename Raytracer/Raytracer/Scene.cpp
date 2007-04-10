/*
 *  Scene.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#include "Scene.h"
#include "Object.h"
#include "Group.h"
#include "Color.h"
#include "Light.h"
#include "Point.h"
#include "Camera.h"
#include "Image.h"
#include "Sample.h"
#include "Filter.h"
#include "Background.h"
#include "Vector.h"
#include <vector>
using namespace std;

Scene::Scene() 
{
	world = new Group();
	mContext = RenderContext(this);
}

Scene::~Scene()
{
	delete background;
	delete camera;
	delete world;
	//Get rid of lights...
	int num = lights.size();
	for(int i = 0; i < num; i++)
		delete lights[i];
}


void Scene::preprocess(int xres, int yres)
{
	mThreadStatus = 0;
	mStartLine = mCurrentLine = 0;
	mXRes = xres;
	mMaxLine = mYRes = yres;
	image = new Image(xres, yres);
	image->setAll(Color(1.0,1.0,1.0));
}

void Scene::setLinesToRender(int start_line, int num_of_lines)
{
	mStartLine = mCurrentLine = start_line;
	
	mMaxLine = start_line + num_of_lines;
	if (mMaxLine > mYRes) mMaxLine = mYRes;
	//cout << start_line << " + " << num_of_lines << " = " << mMaxLine << "\n";

}



int Scene::getCurrentLine()
{
 int c = mCurrentLine;
 mCurrentLine++;
 return c;
}



void* startRenderThread( void *p )
{
Scene *scene = static_cast<Scene*>(p);
scene->renderThread();
}

void Scene::render()
{
		int num_of_threads = 2;
		pthread_t threads[num_of_threads];
		
		for (int i = 0; i < num_of_threads; i++)
			pthread_create(&threads[i], NULL, startRenderThread, this);
		
		for (int i = 0; i < num_of_threads; i++)	
			pthread_join(threads[i], NULL);

		
}

void Scene::renderThread()
{
		
		
		//RenderContext context(this);
		Color result;
		Color final;
		Ray ray;
		HitRecord record;
    double x = 0.0;
		double y = 0.0;
		
		vector<Point> samples(mNumSamples, Point(0.5, 0.5, 0.0));
		
		
	  
		
		//Modified loop from HW1
		int i = 0;
		i = getCurrentLine();
		while( i < mMaxLine )
		{ 
		//cout << "Rendering line #: " << i << " (mMaxLine = " << mMaxLine  << ")\n";
			for(int j=0;j<mXRes;j++)
			{
			
			  final.reset();
				sampler->takeSamples(samples);
				if(filter != NULL) filter->filterSamples(samples);
				
				
				for(int s = 0; s < mNumSamples; s++)
				{
					x = 2 * (j - mXRes/2. + samples[s].x())/mXRes; 
					y = 2 * (i - mYRes/2. + samples[s].y())/mYRes; 
					
					
					camera->makeRay(ray, mContext, x , y);
					record.setTinf();
					//bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
					if(world->intersect(record, mContext, ray))
					{
						record.material->shade(result, mContext, ray, record, 1.0, 1);
					}
					else
					{
						background->getBackgroundColor(result, mContext, ray);
					}
					//result.reset( (cos(500*Vector::PI*(x*x + y*y)) + 1)/2.0 );
					
					final += result;
				}
				
				final /= mNumSamples;
				image->set(j, i, final);
			
			}
			i = getCurrentLine(); 
		}
		

}


void Scene::output()
{
	if (mMaxLine == mYRes) this->image->writePPM();
	else this->output_lines();
}

void Scene::output_lines()
{
	Color temp;
	for (int i = mMaxLine-1; i >= mStartLine; i--)
	{
		for (int j = 0; j < mXRes; j++)
		{
			temp = image->mCanvas[j][i];
			cout << temp.getIntR() << " " << temp.getIntG() << " " << temp.getIntB() << " ";
			/*
			out.put(mCanvas[j][i].getCharR());
			out.put(mCanvas[j][i].getCharG());
			out.put(mCanvas[j][i].getCharB());*/
		}
		cout << "\n";
	}
}

void Scene::addObject(Object* object) 
{ 
	world->addObject(object); 
}
