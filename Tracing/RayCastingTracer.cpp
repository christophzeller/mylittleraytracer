/*
 * RayCastingTracer.cpp
 *
 *  Created on: 19.02.2015
 *      Author: Christoph
 */

#include "RayCastingTracer.h"
#include "World.h"


RGBColor RayCastingTracer::traceRay(const Ray& ray) const
{
	ShadeRec sr (world->hitObjects(ray));

	if (sr.isObjectHit)
	{
		sr.r = ray; // specular reflection
		return (sr.material->shadeRayCast(sr));
		return world->backgroundColor;
	}
	else
	{
		return world->backgroundColor;
	}
}

RayCastingTracer::RayCastingTracer(World* w) : Tracer(w)
{

}

RayCastingTracer::RayCastingTracer() {
	// TODO Auto-generated constructor stub

}

RayCastingTracer::~RayCastingTracer() {
	// TODO Auto-generated destructor stub
}

