/*
 *  Raytracer.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */


#include "Raytracer.h"
#include <iostream>
#include "Image.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Disk.h"
#include "Ring.h"
#include "Box.h"
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


Raytracer::Raytracer()
{
	the_scene = make_scene();
	the_scene->preprocess(512,512);
}
Raytracer::~Raytracer()
{
	delete the_scene;
}
void Raytracer::run()
{
	the_scene->render();
	the_scene->image->writePPM();
}


Scene* Raytracer::make_scene()
{

  Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(.3, .6, .5)));
  Material* box1matl = new LambertianMaterial(Color(.1, .6, .8), .6, .4);
  scene->addObject(new Box(box1matl,
                           Point(-4.5, -4.5, 0), Point(4.5, 4.5, 2)));
  Material* disk1matl = new LambertianMaterial(Color(1, .2, .2), .6, .4);
  scene->addObject(new Disk(disk1matl,
                            Point(3., -3.3, 2.5), Vector(-1, -1, 1), .5));
  Material* disk2matl = new LambertianMaterial(Color(.2, 1, .2), .6, .4);
  scene->addObject(new Disk(disk2matl,
                            Point(2.5, -3.3, 2.5), Vector(-1, -1, 1), .5));
  scene->addObject(new Disk(disk1matl,
                            Point(2., -3.3, 2.5), Vector(-1, -1, 1), .5));
  scene->addObject(new Disk(disk2matl,
                            Point(1.5, -3.3, 2.5), Vector(-1, -1, 1), .5));
  scene->addObject(new Disk(disk1matl,
                            Point(1., -3.3, 2.5), Vector(-1, -1, 1), .5));
  Material* spherematl = new LambertianMaterial(Color(1, 0, 0), .6, .4);
  scene->addObject(new Sphere(spherematl,
                              Point(-2, 2, 5), .8));
  Material* ringmatl = new LambertianMaterial(Color(.25, .25, 1), .6, .4);
  scene->addObject(new Ring(ringmatl,
                            Point(-2, 2, 5), Vector(1, -1, 1), 1.2, 1.8));
  scene->addObject(new Ring(ringmatl,
                            Point(-2, 2, 5), Vector(1, -1, 1), 2.2, 2.8));
  Material* trimatl = new LambertianMaterial(Color(1, 1, 0), .6, .4);
  scene->addObject(new Triangle(trimatl,Point(1,1,4), Point(3,-.5,2), Point(3, 1.5, 6)));
  Material* box2matl = new LambertianMaterial(Color(1, .4, .1), .6, .4);
  scene->addObject(new Box(box2matl,
                           Point(-3.5, -3.5, 2), Point(0, 0, 2.35)));


  scene->setAmbient(Color(.4, .4, .4));
  scene->addLight(new PointLight(Point(-40, -40, 100), Color(.9,.9,.9)));
  scene->addLight(new PointLight(Point(20, -40, 100), Color(.3,.1,.1)));

  scene->setCamera(new PinholeCamera(Point(-2.5, -20, 10),
                                     Point(0.5, 0, 2.5),
                                     Vector(0, 0, 1),
                                     26));

  return scene;
}
	
