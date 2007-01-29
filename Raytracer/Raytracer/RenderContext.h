/*
 *  RenderContext.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _RENDERCONTEXT_H_
#define _RENDERCONTEXT_H_ 1



class Scene;

class RenderContext
{

public:
	RenderContext() {}
	RenderContext(Scene* s) : scene(s) {}
	const Scene* getScene() const { return scene; }; 
	void setScene(Scene* s) {	scene = s;}
	//void renderScene(int xres, int yres); 
private:
	Scene* scene;
	
};


#endif
