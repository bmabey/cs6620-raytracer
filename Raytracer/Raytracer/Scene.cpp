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

void Scene::addObject(Object* object) 
{ 
	world->addObject(object); 
}
