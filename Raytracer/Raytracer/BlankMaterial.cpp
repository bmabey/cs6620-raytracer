/*
 *  BlankMaterial.cpp
 *  Raytracer
 *
 *  Created by Ben Mabey on 1/31/07.
 *
 */

#include "BlankMaterial.h"
#include "Color.h"
#include "RPoint.h"
#include "Vector.h"
#include "HitRecord.h"
#include "Primitive.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Scene.h"
#include "Light.h"
#include "Group.h"

// 
// void BlankMaterial::shade(Color& result, const RenderContext& context, const Ray& ray, const HitRecord& hit, int depth) const
// {
// 	
// 	result = mSurfaceColor;
// }
// 	
