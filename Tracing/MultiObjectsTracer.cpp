/*
 * MultiObjectsTracer.cpp
 *
 *  Created on: 15.02.2015
 *      Author: Christoph
 */

#include "MultiObjectsTracer.h"

RGBColor MultiObjectsTracer::traceRay(const Ray& ray) const
{
	ShadeRec sr (world->hitObjects(ray));
	if (sr.isObjectHit)
		return sr.color;
	else
		return world->backgroundColor;
}

MultiObjectsTracer::MultiObjectsTracer(World* w) : Tracer(w)
{
}

MultiObjectsTracer::MultiObjectsTracer()
{
}

MultiObjectsTracer::~MultiObjectsTracer()
{
}

