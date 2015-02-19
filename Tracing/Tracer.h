/*
 * Tracer.h
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#ifndef __TRACER
#define __TRACER

#include "../Utility/RGBColor.h"

class Ray;
class World;

class Tracer
{
public:
	Tracer();
	Tracer(World* world);
	virtual RGBColor traceRay(const Ray& ray) const;
	virtual ~Tracer();

protected:
	World* world;
};

#endif
