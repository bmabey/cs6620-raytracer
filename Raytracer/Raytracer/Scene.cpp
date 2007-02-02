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
/*  I don't really unsersatnd the rendercontext purpose for now...
void Scene::render(int xres, int yres, const RenderContext* context)
{
		Color result;
		Ray ray;
		HitRecord record;
    double x = 0.0;
		double y = 0.0;
		
		//Modified loop from HW1
		for(int i=0;i<yres;i++)
		{ 
			for(int j=0;j<xres;j++)
			{ 
				 
				x = 2 * (j - xres/2. + 0.5)/xres; 
				y = 2 * (i - yres/2. + 0.5)/yres; 
				camera->makeRay(ray, scontext, (2 * (j - xres/2. + 0.5)/xres) , (2 * (i - yres/2. + 0.5)/yres));
				record.setTinf();
				//bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
				if(world->intersect(record, context, ray))
				{
					//record.obj->mat->shade(result, context, ray, record, 0);
				}
				else
				{
					background->getBackgroundColor(result, context, ray);
				}
				image->set(i, j, result);
			} 
		}
}
*/

void Scene::preprocess(int xres, int yres)
{
	mXRes = xres;
	mYRes = yres;
	image = new Image(xres, yres);
	image->setAll(Color(1.0,1.0,1.0));
}

void Scene::render()
{
		
		
		RenderContext context(this);
		Color result;
		Ray ray;
		HitRecord record;
    double x = 0.0;
		double y = 0.0;
		
		//Modified loop from HW1
		for(int i=0;i<mYRes;i++)
		{ 
			for(int j=0;j<mXRes;j++)
			{ 
				x = 2 * (j - mXRes/2. + 0.5)/mXRes; 
				y = 2 * (i - mYRes/2. + 0.5)/mYRes; 
				camera->makeRay(ray, context, x , y);
				record.setTinf();
				//bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
				if(world->intersect(record, context, ray))
				{
					record.material->shade(result, context, ray, record, 0);
				}
				else
				{
					background->getBackgroundColor(result, context, ray);
				}
				image->set(j, i, result);
			} 
		}
}


void Scene::addObject(Object* object) 
{ 
	world->addObject(object); 
}
