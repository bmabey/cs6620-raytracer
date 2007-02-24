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
#include "Heightfield.h"
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
#include "PhongMaterial.h"
#include "MetalMaterial.h"
#include "DielectricMaterial.h"
#include "Vector.h"
#include "Point.h"
#include "PointLight.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using std::cout;

Raytracer::Raytracer()
{
	the_scene = make_scene();
	the_scene->preprocess(1024,1024);
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

//generates a psuedo-random integer between 0 and max
int randint(int max)
{	
		float r = rand();
		r *= max;
		r /= (RAND_MAX+1.0);
    return (int)r;
} 

 bool dominos[7][3][3] =
 {//0
  {{0, 0, 0}, 
	 {0, 0, 0},
	 {0, 0, 0}},									
	 //1
	{{0, 0, 0}, 
	 {0, 1, 0},
	 {0, 0, 0}},
	//2
	{{0, 0, 1}, 
	 {0, 0, 0},
	 {1, 0, 0}},
 //3
   {{0, 0, 1}, 
	 {0, 1, 0},
	 {1, 0, 0}},
//4
  {{1, 0, 1}, 
	 {0, 0, 0},
	 {1, 0, 1}},
//5
	{{1, 0, 1}, 
	 {0, 1, 0},
	 {1, 0, 1}},
//6
  {{1, 0, 1}, 
	 {1, 0, 1},
	 {1, 0, 1}}
		 };

void makeDomino(Scene* scene, Material* body_material, Material* paint_material, Point corner)
{ 
	Vector size(1.0, 1.75, 0.2);
	scene->addObject(new Box(body_material,corner, corner+size));
	Point mid_corner(corner.x(), corner.y()+0.825, corner.z()-0.001);
	Vector mid_size(1.0, 0.1, 0.1);
	scene->addObject(new Box(paint_material, mid_corner, mid_corner+mid_size  ));
	
	Point center = Point(corner.x()+0.07+0.12, corner.y()+0.026+0.12, -0.001);											 
	
	float x_space = 0.07;
	float y_space = 0.026;
	float disc_radius = 0.12;
	float disc_diameter = disc_radius*2;
	
	Point base = Point(corner.x()+x_space+disc_radius, corner.y()+y_space+disc_radius, corner.z()-0.001);
	int bottom_number = randint(6);
	int top_number = randint(6);
	
	
	for (int row = 0; row < 3; row++)
	{		
		for (int col = 0; col < 3; col++)
		{

			if (dominos[bottom_number][row][col]) scene->addObject(new Disk(paint_material, base,Vector(0,0,-1), 0.12));
			base.setX(base.x()+x_space+disc_diameter);
		}
		base.setX(corner.x()+x_space+disc_radius);
		base.setY(base.y()+y_space+disc_diameter); 
	}
	
	base = Point(corner.x()+x_space+disc_radius, corner.y()+y_space+disc_radius+0.925, corner.z()-0.001);
	for (int row = 0; row < 3; row++)
	{		
		for (int col = 0; col < 3; col++)
		{
			if (dominos[top_number][row][col]) scene->addObject(new Disk(paint_material, base,Vector(0,0,-1), 0.12));
			base.setX(base.x()+x_space+disc_diameter); 
		}
		base.setX(corner.x()+x_space+disc_radius);
		base.setY(base.y()+y_space+disc_diameter); 
	}
}

float randfloat()
{
    return rand()/(float(RAND_MAX)+1);
} 
Color random_color()
{
	return Color(randfloat(),randfloat(),randfloat());
}
//HW5 Creative
Scene* Raytracer::make_scene()
{
	srand((unsigned)(time(0))); 
  Scene* scene = new Scene();
    scene->setBackground(new SolidBackground(Color(.5, .8, .9)));

  scene->addObject(new Plane(new MetalMaterial(Color(139.0/255.0, 69.0/255.0, 19.0/255.0), 60),
                             Vector(0,1,0), Point(0,-0.001,0.0)));
  Material* groundmatl = new LambertianMaterial(Color(0.65, 0.75, 0.85), .6, .4);
	Material* whiteLambert = new LambertianMaterial(Color(1.0, 1.0, 1.0), .6, .4);
//  scene->addObject(new Plane(groundmatl,
//                             Vector(0,0,1), Point(0,0,1.5)));


	
	scene->addObject(new Sphere(new PhongMaterial(Color(1.0, 0.0, 0.0), 0.6, 0.4, Color(1,1,1), 70), Point(35, 20, 20), 20));
	scene->addObject(new Sphere(new PhongMaterial(Color(1.0, 1.0, 0.0), 0.6, 0.4, Color(1,1,1), 70), Point(-10, 20, 40), 20));
	scene->addObject(new Sphere(new PhongMaterial(Color(0.0, 0.0, 1.0), 0.6, 0.4, Color(1,1,1), 70), Point(-60, 20, 40), 20));
	Material* ball_matl = new MetalMaterial(Color(0.8, 0.8, 0.8), 100);
	double eta = 2.5;
	Material* transp_matl = new DielectricMaterial(eta, 200);
	
	
	
	Material* red_phong = new PhongMaterial(Color(1.0, 0.0, 0.0), 0.6, 0.4, Color(1,1,1), 30);
	Material* blue_phong = new PhongMaterial(Color(0.0, 0.0, 1.0), 0.6, 0.4, Color(1,1,1), 30);
	Material* yellow_phong = new PhongMaterial(Color(1.0, 1.0, 0.0), 0.6, 0.4, Color(1,1,1), 30);
	Material* black_phong = new PhongMaterial(Color(0.0, 0.0, 0.0), 0.6, 0.4, Color(1,1,1), 30);
	Material* white_phong = new PhongMaterial(Color(0.0, 0.0, 0.0), 0.6, 0.4, Color(1,1,1), 30);

	
	int num_in_line = 40;
	
  
	
		Material* mats[6][4];
		
		mats[0][0] = transp_matl;	mats[0][1] = red_phong;
		mats[0][2] = red_phong; mats[0][3] = whiteLambert;
		
		mats[1][0] = black_phong;	mats[1][1] = red_phong;
		mats[1][2] = red_phong; mats[1][3] = black_phong;
		
		mats[2][0] = transp_matl;	mats[2][1] = whiteLambert;
		mats[2][2] = black_phong; mats[2][3] = whiteLambert;
		
		mats[3][0] = whiteLambert;	mats[3][1] = black_phong;
		mats[3][2] = transp_matl; mats[3][3] = black_phong;
		
		mats[4][0] = transp_matl;	mats[4][1] = blue_phong;
		mats[4][2] = blue_phong; mats[4][3] = whiteLambert;
		
		mats[5][0] = whiteLambert;	mats[5][1] = blue_phong;
		mats[5][2] = blue_phong; mats[5][3] = whiteLambert;
		
		
	float start_x = 0.0;
	Point corner(start_x, 0, -50);
	for (int i = 0; i < 6; i++)
	{	
		for( int j = 0; j < num_in_line; j++ )
		{
			if (j % 2 == 0)
				makeDomino(scene, mats[i][0], mats[i][1], corner);
			else
				makeDomino(scene,  mats[i][2],  mats[i][3], corner);
	
			corner.setZ(corner.z()+0.75);
			corner.setX(corner.x()-0.25);
		}
		start_x -= 2;
		corner = Point(start_x, 0, -50);
	}	

//  Material* ringmatl = new LambertianMaterial(Color(.9, .9, .1), .2, .8);
//  for(int i=0;i<15;i++){
//    double r = .30;
//    Point center(-9, 0, 1.6+r);
//    Vector offset(2.35*r, 0, 0);
//    scene->addObject(new Ring(ringmatl,
//                              center+offset*i, Vector(0.2, -1, -0.2), r*0.5, r));
//  }
//  
//	Material* ball_matl = new MetalMaterial(Color(0.8, 0.8, 0.8), 100);
//  scene->addObject(new Sphere(ball_matl, Point(-7, 3.5, 2.4), 1.2));
//	
//	
//  Material* hfmatl = new PhongMaterial(Color(0.7, 0.1, .3), 0.6, 0.4, Color(1,1,1), 30);
//
//
//	scene->addObject(new Heightfield(hfmatl,
//                                   "mount_200_200.hf",
//                                   Point(-4.5, 2.0, 2), Point(-1.5, 5.0 , 4)));

  scene->setAmbient(Color(.4, .4, .4));
  scene->addLight(new PointLight(Point(0, 100, -100), Color(1.0,1.0,1.0)));
	scene->addLight(new PointLight(Point(-10, 100, -75), Color(1.0,1.0,1.0)));


	Point p( -3, 5, -55.5 );
	Point lookat = Point(0, 0, 0);
	scene->setCamera( new PinholeCamera( p,
		lookat,
		Vector( 0, 1, 0 ),
		90 ) );

  scene->setMaxRayDepth(40);
  scene->setMinAttenuation(.01);

  return scene;
}
/*
//HW5 Required

Scene* Raytracer::make_scene()
{
  Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(0.5, 0.8, 0.9)));
  Material* groundmatl = new LambertianMaterial(Color(0.65, 0.75, 0.85), .6, .4);
  scene->addObject(new Plane(groundmatl,
                             Vector(0,0,1), Point(0,0,1.5)));


  for(int i=0;i<4;i++){
    double eta = 1 + i*0.5 + .05;
    Material* transp_matl = new DielectricMaterial(eta, 100);
    Point corner(i*1.3 - 4, -3, 1.51);
    Vector size(0.20, 2.5, 1.4);
    scene->addObject(new Box(transp_matl,
                             corner, corner+size));
  }


  Material* ringmatl = new LambertianMaterial(Color(.9, .9, .1), .2, .8);
  for(int i=0;i<15;i++){
    double r = .30;
    Point center(-9, 0, 1.6+r);
    Vector offset(2.35*r, 0, 0);
    scene->addObject(new Ring(ringmatl,
                              center+offset*i, Vector(0.2, -1, -0.2), r*0.5, r));
  }
  
	Material* ball_matl = new MetalMaterial(Color(0.8, 0.8, 0.8), 100);
  scene->addObject(new Sphere(ball_matl, Point(-7, 3.5, 2.4), 1.2));
	
	
  Material* hfmatl = new PhongMaterial(Color(0.7, 0.1, .3), 0.6, 0.4, Color(1,1,1), 30);


	scene->addObject(new Heightfield(hfmatl,
                                   "mount_200_200.hf",
                                   Point(-4.5, 2.0, 2), Point(-1.5, 5.0 , 4)));

  scene->setAmbient(Color(.4, .4, .4));
  scene->addLight(new PointLight(Point(20, -20, 100), Color(.9,.9,.9)));
  scene->addLight(new PointLight(Point(-40, -30, 50), Color(.3,.1,.1)));

  scene->setCamera(new PinholeCamera(Point(8, -18, 7.5),
                                     Point(-4.7, 2.5, 1.5),
                                     Vector(0, 0, 1),
                                     15));

/*
	Point p( 8, -18, 7.5 );
	Point lookat( -4.7, 2.5, 1.5 );
	lookat = Point(-3, 3.5, 2);
	Vector direction = lookat - p;
	scene->setCamera( new PinholeCamera( p + ( 0.9 * direction ),
		lookat,
		Vector( 0, 0, 1 ),
		15 ) );

  scene->setMaxRayDepth(25);
  scene->setMinAttenuation(.01);

  return scene;
}



//Assignment 4
Scene* Raytracer::make_scene()
{
  Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(0.0, 0.0, 0.0)));

  Material* spherematl = new LambertianMaterial(Color(1, 1, 0), .6, .4);
  scene->addObject(new Sphere(spherematl,
                              Point(0, -2, 0), 3));
  
  Material* hfmatl = new LambertianMaterial(Color(.6, .6, .6), .8, .2);

	  scene->addObject(new Heightfield(hfmatl,
                                   "mount_200_200.hf",
                                   Point(-10.5, -10.5, -1), Point(10.5, 10.5, 3)));
																	 
		  scene->addObject(new Heightfield(hfmatl,
                                   "mount_200_200.hf",
                                   Point(10.5, 10.5, -1), Point(20.5, 20.5, 3)));

																		 
		  scene->addObject(new Heightfield(hfmatl,
                                   "mount_200_200.hf",
                                   Point(15.5, 15.5, -1), Point(35.5, 35.5, 3)));



  scene->setAmbient(Color(.4, .4, .4));
  scene->addLight(new PointLight(Point(-40, -40, 100), Color(.8,.8,.8)));
  scene->addLight(new PointLight(Point(-20, -20, 20), Color(.3,.3,.9)));
	scene->addLight(new PointLight(Point(80, 20, 60), Color(.5,.3,.3)));

  //scene->setCamera(new PinholeCamera(Point(-2.5, -20, 10),
  scene->setCamera(new PinholeCamera(Point(-10.5, -30, 20),
                                     Point(0.5, 0, 4.5),
                                     Vector(0, 1, 0),
                                     26));

  return scene;
}

//#4 creative

Scene* Raytracer::make_scene()
{
  Scene* scene = new Scene();
  scene->setBackground(new SolidBackground(Color(.3, .6, .5)));
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
  scene->addObject(new Triangle(trimatl,
                                Point(1,1,4), Point(3,-.5,2), Point(3, 1.5, 6)));
  Material* hfmatl = new LambertianMaterial(Color(.5, 1, 1), .8, .2);
  scene->addObject(new Heightfield(hfmatl,
                                   "mount_200_200.hf.original",
                                   Point(-4.5, -4.5, -1), Point(4.5, 4.5, 3)));


  scene->setAmbient(Color(.4, .4, .4));
  scene->addLight(new PointLight(Point(-40, -40, 100), Color(.8,.8,.8)));
  scene->addLight(new PointLight(Point(80, 20, 60), Color(.5,.3,.3)));

  //scene->setCamera(new PinholeCamera(Point(-2.5, -20, 10),
  scene->setCamera(new PinholeCamera(Point(-2.5, -20, 10),
                                     Point(0.5, 0, 4.5),
                                     Vector(0, 0, 1),
                                     26));

  return scene;
}

Assignment 3

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
*/
	
