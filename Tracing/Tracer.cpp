/*
 * Tracer.cpp
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#include "Tracer.h"

RGBColor Tracer::traceRay(const Ray& ray) const
{
	return RGBColor(0, 0, 0);
}

Tracer::Tracer(World* world) : world(world)
{
}

Tracer::Tracer() : world(0)
{
}

Tracer::~Tracer()
{
	// TODO Auto-generated destructor stub
}

