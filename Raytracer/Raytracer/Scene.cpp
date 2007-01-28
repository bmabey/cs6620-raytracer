/*
 *  Scene.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#include "Scene.h"

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
