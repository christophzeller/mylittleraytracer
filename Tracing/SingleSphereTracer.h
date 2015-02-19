/*
 * SingleSphereTracer.h
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#ifndef SINGLESPHERETRACER_H_
#define SINGLESPHERETRACER_H_

#include "../Utility/RGBColor.h"
#include "../Tracing/Tracer.h"
#include "../Tracing/ShadeRec.h"
#include "../Tracing/World.h"

class Ray;

class SingleSphereTracer: public Tracer
{
public:
	virtual RGBColor traceRay(const Ray& ray) const;
	SingleSphereTracer(World* world);
	SingleSphereTracer();
	virtual ~SingleSphereTracer();

};

#endif /* SINGLESPHERETRACER_H_ */
