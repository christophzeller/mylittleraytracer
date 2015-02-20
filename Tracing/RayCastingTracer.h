/*
 * RayCastingTracer.h
 *
 *  Created on: 19.02.2015
 *      Author: Christoph
 */

#ifndef RAYCASTINGTRACER_H_
#define RAYCASTINGTRACER_H_

#include "Tracer.h"
#include "ShadeRec.h"
#include "../Utility/RGBColor.h"

class RayCastingTracer: public Tracer {
public:
	virtual RGBColor traceRay(const Ray& ray) const;
	RayCastingTracer(World* w);
	RayCastingTracer();
	virtual ~RayCastingTracer();
};

#endif /* RAYCASTINGTRACER_H_ */
