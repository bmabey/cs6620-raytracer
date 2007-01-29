#include <iostream>
#include "Image.h"
#include "Sphere.h"
#include "Ray.h"
#include "Color.h"
#include "Scene.h"
#include "Plane.h"
#include "SolidBackground.h"
#include "PinholeCamera.h"
#include "LambertianMaterial.h"
#include "Vector.h"
#include "Point.h"
#include "PointLight.h"


Scene* make_scene()
{
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

  return scene;
}


int main (int argc, char * const argv[]) 
{

	Scene* scene = make_scene();
	scene->render(512,512);
	scene->image->writePPM();
	  
    return 0;
}

