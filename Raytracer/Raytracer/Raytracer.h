/*
 *  Raytracer.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/24/07.
 *
 */

#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_ 1
#include <vector>
class Primitive;
class Material;
class Point;

using namespace std;
class Scene;

class Raytracer
{

public:
	Raytracer(int width, int height, int start_line, int num_lines);
	~Raytracer();
	Scene* make_scene();
	void addSnowman(float x, float y, float z, Scene* scene, bool faceless);
	void makeDomino(Scene* scene, Material* body_material, Material* paint_material, Point corner);
	void run();
	
	Scene* the_scene;

	private:
		vector<Primitive*> objects;
		int mHeight;
		int mWidth;
	
};

#endif
