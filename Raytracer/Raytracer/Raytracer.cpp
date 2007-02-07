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


int rv()
{
	return (rand() % 100) > 50 ? 1 : -1;
}

void addPyramid(Point b1, Point b2, float sphere_size, Scene* scene)
{
  Material* box1matl = new LambertianMaterial(Color(1.0f, 1.0f, 0.0f), .6, .4);
  scene->addObject(new Box(box1matl,
                           b1, b2));
	Material* trimatl = new LambertianMaterial(Color(1, 1, 0), .6, .4);
	float x = (b1[0] < 0) ? (b1[0]+b2[0])/2 : b1[0]+(b2[0]-b1[0])/2; 
	if (b1[0] < 0 && b2[0] < 0) x = b1[0]-(abs(b2[0])-abs(b1[0]))/2;
	Point top = Point(x,(b2[2]-b1[2])/2,(b1[2]+b2[2])/2);
	
  scene->addObject(new Triangle(trimatl,Point(b1.x(),b2.y(),b1.z()), top, Point(b2.x(), b2.y(), b1.z())));	
	scene->addObject(new Triangle(trimatl,Point(b1.x(),b2.y(),b2.z()), top, Point(b2.x(), b2.y(), b2.z())));	
	scene->addObject(new Triangle(trimatl,Point(b1.x(),b2.y(),b1.z()), top, Point(b1.x(), b2.y(), b2.z())));											 											 
	scene->addObject(new Triangle(trimatl,Point(b2.x(),b2.y(),b1.z()), top, Point(b2.x(), b2.y(), b2.z())));	


	Material* spherematl = new LambertianMaterial(Color(1, 0, 0), .6, .4);
  top.setY( top.y()+ 1.0);
	scene->addObject(new Sphere(spherematl,
                              top, sphere_size));
  Material* ringmatl = new LambertianMaterial(Color(.25, .25, 1), .6, .4);
  
	scene->addObject(new Ring(ringmatl,
                            top, Vector(rv(), rv(), rv()), sphere_size+0.4, sphere_size+1.0));
  scene->addObject(new Ring(ringmatl,
                            top, Vector(rv(), rv(), rv()), sphere_size+1.4, sphere_size+2.0));

}



Scene* Raytracer::make_scene()
{

  Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(.5, .8, .9)));

	scene->addObject(new Plane(new LambertianMaterial(Color(139.0/255.0, 69.0/255.0, 19.0/255.0), .4, .6),
														 Vector(0,1,0), Point(0,-4,0.0)));
	addPyramid(Point(-4.5, -4.5, 0),Point(4.5, -3.0, 7.0), 0.3, scene);
	addPyramid(Point(4.5, -4.5, 0),Point(13.5, -3.0, 7.0), 0.3, scene);
	addPyramid(Point(13.5, -4.5, 0),Point(22.5, -3.0, 7.0), 0.3, scene);

	
	addPyramid(Point(-4.5, -4.5, 25),Point(35.5, -3.0, 65.0), 0.5, scene);
	
	addPyramid(Point(35.0, -4.5, 70),Point(-25.0, -3.0, 160), 0.8, scene);
	
	addPyramid(Point(0.0, -4.5, 170),Point(-55.0, -3.0, 240), 0.5,  scene);
	
	
	//addPyramid(Point(15.5, -4.5, 47),Point(20.0, -3.0, 57.0),  scene);
 // Material* disk1matl = new LambertianMaterial(Color(1, .2, .2), .6, .4);
//  scene->addObject(new Disk(disk1matl,
//                            Point(3., -3.3, 2.5), Vector(-1, -1, 1), .5));
//  Material* disk2matl = new LambertianMaterial(Color(.2, 1, .2), .6, .4);
//  scene->addObject(new Disk(disk2matl,
//                            Point(2.5, -3.3, 2.5), Vector(-1, -1, 1), .5));
//  scene->addObject(new Disk(disk1matl,
//                            Point(2., -3.3, 2.5), Vector(-1, -1, 1), .5));
//  scene->addObject(new Disk(disk2matl,
//                            Point(1.5, -3.3, 2.5), Vector(-1, -1, 1), .5));
//  scene->addObject(new Disk(disk1matl,
//                            Point(1., -3.3, 2.5), Vector(-1, -1, 1), .5));

//  Material* trimatl = new LambertianMaterial(Color(1, 1, 0), .6, .4);
//  scene->addObject(new Triangle(trimatl,Point(1,1,4), Point(3,-.5,2), Point(3, 1.5, 6)));
//  Material* box2matl = new LambertianMaterial(Color(1, .4, .1), .6, .4);
//  scene->addObject(new Box(box2matl,
//                           Point(-3.5, -3.5, 2), Point(0, 0, 2.35)));
//

  scene->setAmbient(Color(1.0, 1.0, 1.0));
  scene->addLight(new PointLight(Point(-200, 50, -10), Color(.9,.9,.9)));
  //scene->addLight(new PointLight(Point(20, -40, 100), Color(.3,.1,.1)));

  scene->setCamera(new PinholeCamera(Point(-10.0, 2.0f, -50.0f),
                                     Point(0.0, 2, 0.0),
                                     Vector(0, 1, 0),
                                     45));

  return scene;
}
	
