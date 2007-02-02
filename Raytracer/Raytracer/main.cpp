#include <iostream>

#include "Raytracer.h"




int main (int argc, char * const argv[]) 
{

	Raytracer rt;
	/*Scene* scene = rt.make_scene();
	scene->preprocess(512,512);
	scene->render();
	scene->image->writePPM();*/
	rt.run();
	/*
	Raytracer* rt = new Raytracer();
	rt->run();*/  
    return 0;
}

