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
#include "Camera.h"
#include "Image.h"
#include "Background.h"

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
	mCurrentLine = 0;
	mXRes = xres;
	mYRes = yres;
	image = new Image(xres, yres);
	image->setAll(Color(1.0,1.0,1.0));
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
		Ray ray;
		HitRecord record;
    double x = 0.0;
		double y = 0.0;
		
		
	  
		
		//Modified loop from HW1
		int i = 0;
		i = getCurrentLine();
		while( i < mYRes)
		{ 
			for(int j=0;j<mXRes;j++)
			{ 
				x = 2 * (j - mXRes/2. + 0.5)/mXRes; 
				y = 2 * (i - mYRes/2. + 0.5)/mYRes; 
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
				image->set(j, i, result);
			}
			i = getCurrentLine(); 
		}
		

}


void Scene::addObject(Object* object) 
{ 
	world->addObject(object); 
}
