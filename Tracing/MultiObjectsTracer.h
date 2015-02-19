/*
 * MultiObjectsTracer.h
 *
 *  Created on: 15.02.2015
 *      Author: Christoph
 */

#ifndef MULTIOBJECTSTRACER_H_
#define MULTIOBJECTSTRACER_H_

#include "Tracer.h"
#include "../Utility/RGBColor.h"
#include "ShadeRec.h"
#include "World.h"

class MultiObjectsTracer: public Tracer
{
public:
	RGBColor traceRay(const Ray& ray) const;
	MultiObjectsTracer(World* world);
	MultiObjectsTracer();
	virtual ~MultiObjectsTracer();
};

#endif /* MULTIOBJECTSTRACER_H_ */
