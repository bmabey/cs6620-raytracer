/*
 *  Group.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _GROUP_H_
#define _GROUP_H_ 1

#include "Object.h"
#include <vector>
using namespace std;

class Group : public Object
{

public:
	
	Group() : num_objects(0) { }
	~Group();
	
	void preprocess(){}; 
	void intersect(HitRecord& hit, const RenderContext& context, const Ray& ray);
	void addObject(Object* object) { objects.push_back(object); num_objects++;}
	
	vector<Object*> objects;
	
private:
	int num_objects;
};


#endif