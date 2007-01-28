/*
 *  Scene.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _SCENE_H_
#define _SCENE_H_

#include "Background.h"
#include "Group.h"
#include "Color.h"
#include "Light.h"
#include "Camera.h"
#include <vector>

class Scene
{
public:
	Scene() {world = new Group();}

	~Scene();
	void renderScene(int xres, int yres);
	
	//Setters
	void setBackground(Background* color) { background = color; }
	void setAmbient(const Color& color) { ambient = color; }
	void setCamera(Camera* cam) { camera = cam; } 
	
	void addLight(Light* light) { lights.push_back(light); }
	void addObject(Object* object) { world->addObject(object); }
	
	
	vector<Light*> lights;
	Camera* camera;
	Background* background;
	Color ambient;
	Group* world;
	
};

#endif 