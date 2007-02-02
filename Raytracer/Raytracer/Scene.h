/*
 *  Scene.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _SCENE_H_
#define _SCENE_H_


#include "Object.h"
#include "Color.h"
#include <vector>


class Group;
using namespace std;

class Background;
class Camera;
class Light;
class Object;
class RenderContext;
class Image;

class Scene
{
public:
	Scene();
	~Scene();
	//void render(int xres, int yres, const RenderContext* context);
	void render(int xres, int yres);
	//Setters
	void setBackground(Background* color) { background = color; }
	void setAmbient(const Color& color) { ambient = color; }
	void setCamera(Camera* cam) { camera = cam; }
	void setImage(Image* i) { image = i;} 
	void addObject(Object* object);
	void addLight(Light* light) { lights.push_back(light); }
	
	
	
	vector<Light*> lights;
	Camera* camera;
	Background* background;
	Color ambient;
	Group* world;
	Image* image;
	
};

#endif 