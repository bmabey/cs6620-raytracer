/*
 *  Group.h
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/27/07.
 *
 */

#ifndef _GROUP_H_
#define _GROUP_H_ 1


#include <vector>
#include "Object.h"

using namespace std;

class Group : public Object
{

public:
	
	Group() : num_objects(0) { }
	~Group();
	
	bool intersect(HitRecord& hit, const RenderContext& context, const Ray& ray) const;
	void addObject(Object* object);
	
	vector<Object*> objects;
	
private:
	int num_objects;
};


#endif