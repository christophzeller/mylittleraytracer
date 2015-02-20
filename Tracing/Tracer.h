/*
 * Tracer.h
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#ifndef __TRACER
#define __TRACER

#include "../Utility/RGBColor.h"
//#include "World.h"
class World;

class Ray;

class Tracer
{
public:
	Tracer();
	Tracer(World* world);
	virtual RGBColor traceRay(const Ray& ray) const;
	virtual RGBColor traceRay(const Ray& ray, const int recursionDepth) const;
	virtual RGBColor traceRay(const Ray& ray, const int recursionDepth, float& tMin) const;
	virtual ~Tracer();

protected:
	World* world;
};

#endif
