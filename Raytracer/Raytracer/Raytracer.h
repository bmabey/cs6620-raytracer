/*
 *  Raytracer.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_ 1

class Scene;

class Raytracer
{

public:
	Raytracer();
	~Raytracer();
	Scene* make_scene();
	void addSnowman(float x, float y, float z, Scene* scene, bool faceless);
	void run();
	
	Scene* the_scene;

	
};

#endif
