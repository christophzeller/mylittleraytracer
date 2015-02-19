/*
 * SingleSphereTracer.cpp
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#include "SingleSphereTracer.h"
#include <iostream>

RGBColor SingleSphereTracer::traceRay(const Ray& ray) const
{
    ShadeRec sr = ShadeRec(*world); // unused
    double t; // unused

    if (world->sphere.hit(ray, t, sr))
    {
	//std::cout << "hit" << std::endl;
	return world->sphere.getColor(); // hit -> farbe
    }
    else // no hit -> black
    {
	return RGBColor(0, 0, 0);
    }
}

SingleSphereTracer::SingleSphereTracer(World* w)
	: Tracer(w)
{
}

SingleSphereTracer::SingleSphereTracer()
{
}

SingleSphereTracer::~SingleSphereTracer()
{
}

