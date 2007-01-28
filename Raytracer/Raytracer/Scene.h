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
#include "Object.h"
#include <vector>


class Group;
using namespace std;

class Camera;
class Light;
class Object;
class Color;

class Scene
{
public:
	Scene();
	~Scene();
	void renderScene(int xres, int yres);
	
	//Setters
	void setBackground(Background* color) { background = color; }
	void setAmbient(const Color& color) { ambient = color; }
	void setCamera(Camera* cam) { camera = cam; } 
	void addObject(Object* object);
	void addLight(Light* light) { lights.push_back(light); }
	
	
	
	vector<Light*> lights;
	Camera* camera;
	Background* background;
	Color ambient;
	Group* world;
	
};

#endif 