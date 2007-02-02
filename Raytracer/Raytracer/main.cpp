#include <iostream>
#include "Image.h"
#include "Sphere.h"
#include "Ray.h"
#include "Color.h"
#include "Scene.h"
#include "Plane.h"
#include "SolidBackground.h"
#include "PinholeCamera.h"
#include "BlankMaterial.h"
#include "LambertianMaterial.h"
#include "Vector.h"
#include "Point.h"
#include "PointLight.h"


void addSnowman(float x, float y, float z, Scene* scene, bool faceless)
{
	//Snowman base
	//float base_x = 9.0*x; float base_y = 5.0*y; float base_z = -1.5*z;
	
	scene->addObject(new Sphere(new LambertianMaterial(Color(1.0f, 1.0f, 1.0f), .7, .3),
                              Point(9.0*x, 5.0*y, -1.5*z), 3.0));
	//Middle
	scene->addObject(new Sphere(new LambertianMaterial(Color(1.0f, 1.0f, 1.0f), .7, .3),
                             Point(9.0*x, 5.0*y, 2.5*z), 2.2));
	//Head
	scene->addObject(new Sphere(new LambertianMaterial(Color(1.0f, 1.0f, 1.0f), .7, .3),
	                             Point(9.0*x, 5.0*y, 5.5*z), 1.6));
	if (!faceless)
	{
	//Left Eye
	scene->addObject(new Sphere(new LambertianMaterial(Color(0.0f, 0.0f, 0.0f), .7, .3),
                             Point(7.8*x, 5.20*y, 6.1*z), 0.3));
	//Right Eye
	scene->addObject(new Sphere(new LambertianMaterial(Color(0.0f, 0.0f, 0.0f), .7, .3),
                             Point(7.8*x, 4.30*y, 6.15*z), 0.2));
	//Nose
	scene->addObject(new Sphere(new LambertianMaterial(Color(1.0f, 0.3f, 0.3f), .7, .3),
                             Point(7.4*x, 4.9*y, 5.5*z), 0.2));
  }
	
}

Scene* make_scene()
{
	/*
  Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(.5, .8, .9)));
  scene->addObject(new Sphere(new LambertianMaterial(Color(.1, .3, .9), .7, .3),
                              Point(1.5, 3.5, 4), 2.4));
  scene->addObject(new Sphere(new LambertianMaterial(Color(1, .2, .2), .7, .3),
                              Point(-0.5, -1.5, 2), 1.8));
  scene->addObject(new Sphere(new LambertianMaterial(Color(1,.9,.1), .6, .4),
                              Point(0.5, 1.0, 1), 1));
  scene->addObject(new Sphere(new LambertianMaterial(Color(1,1,1), .5, .5),
                              Point(25,25,120), 10));
  scene->addObject(new Plane(new LambertianMaterial(Color(.4, .4, .7), .4, .6),
                             Vector(0,0,1), Point(0,0,-0.1)));

  scene->setAmbient(Color(.6, .6, .6));
  scene->addLight(new PointLight(Point(-30, -20, 80), Color(.7,.9,.9)));
  scene->addLight(new PointLight(Point(-20, -50, 40), Color(.6,.1,.1)));
  scene->setCamera(new PinholeCamera(Point(-24, -2, 5.2),
                                     Point(1,1, 2.4),
                                     Vector(0, 0, 1),
                                     22.0f));
*/


 Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(0.6627, 0.72549, 0.95686)));
  //Snowman base
	addSnowman(1.0,1.0,1.0,scene, false);
	// for( int i = 3; i < 100; i += 3 )
// 	{
// 		addSnowman(float(i),1.0,1.0,scene);
// 	}
	int snowmen = 0;
	for( int i = 3; i < 50; i += 3 )
	{
		for( int j = 3; j < 50; j += 3 )
		{
			snowmen++;
			addSnowman(float(i),float(j),1.0,scene, true);
		}
	}
	// }
// 	for( int i = 3; i < 100; i += 3 )
// 	{
// 		addSnowman(3.0,float(i),1.0,scene);
// 	}
	
	


  scene->addObject(new Plane(new LambertianMaterial(Color(1.0f, 1.0f, 1.0f), .4, .6),
                             Vector(0,0,1), Point(0,0.0,-2.0)));

  scene->setAmbient(Color(.9, .9, .9));
  scene->addLight(new PointLight(Point(-200.0, 100.0, 50.0), Color(.9,.9,.6)));
  //scene->addLight(new PointLight(Point(-20, -50, 40), Color(.6,.1,.1)));
  scene->setCamera(new PinholeCamera(Point(-30, -15.0, 10.0),
                                     Point(1,1, 2.4),
                                     Vector(0, 0, 1),
                                     45.0f));
  
  return scene;
}


int main (int argc, char * const argv[]) 
{

	Scene* scene = make_scene();
	scene->render(512,512);
	scene->image->writePPM();
	  
    return 0;
}

