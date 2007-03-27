#include <iostream>

#include "Raytracer.h"




int main (int argc, char * const argv[]) 
{
	int res = atoi(argv[1]);
	int start_line = atoi(argv[2]);
	int num_lines = atoi(argv[3]);
	cout << "Rendering scene at " << res << "x" << res << ".  Rendering lines: " << "\n" << start_line << "-" << start_line+num_lines << "\n";
	Raytracer rt(res, res, start_line, num_lines);
	
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

