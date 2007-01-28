/*
 *  RenderContext.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _RENDERCONTEXT_H_
#define _RENDERCONTEXT_H_ 1

#include "Scene.h"
class Scene;

class RenderContext
{

public:
	RenderContext() {}
	const Scene* getScene() const { return scene; }; 
	
private:
	Scene* scene;
	
};


#endif
