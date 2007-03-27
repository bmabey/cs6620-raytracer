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
class Filter;
class Sample;

class Scene
{
public:
	Scene();
	~Scene();
	//void render(int xres, int yres, const RenderContext* context);
	void preprocess(int xres, int yres);
	void setLinesToRender(int start_line, int num_of_lines);
	void render();
	void renderThread();
	//Setters
	void setBackground(Background* color) { background = color; }
	void setAmbient(const Color& color) { ambient = color; }
	void setCamera(Camera* cam) { camera = cam; }
	void setImage(Image* i) { image = i;} 
	void setFilter(Filter* f) { filter = f;} 
	void setSample(Sample* s, int num_samples)  { mNumSamples = num_samples; sampler = s;} 
	void addObject(Object* object);
	void addLight(Light* light) { lights.push_back(light); }
	void setMaxRayDepth(int depth) {maxRayDepth = depth; }
	void setMinAttenuation(float atten) {minAttenuation = atten; }

	void output_lines();
	
	
	vector<Light*> lights;
	Camera* camera;
	Background* background;
	Color ambient;
	Group* world;
	Image* image;
	Filter* filter;
	Sample* sampler;
	int maxRayDepth;
  float minAttenuation;
private:
	int getCurrentLine();
	int mXRes;
	int mYRes;
	int mMaxLine;
	int mCurrentLine;
	int mStartLine;
	int mThreadStatus;
	int mNumSamples;
	RenderContext mContext;

};

#endif