/*
 * Material.h
 *
 *  Created on: 19.02.2015
 *      Author: Christoph
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../Utility/RGBColor.h"
//#include "../Tracing/Tracer.h"

class ShadeRec;

class Material
{
public:
	virtual RGBColor shadeRayCast(ShadeRec& sr);
	virtual RGBColor shadeWhitted(ShadeRec& sr);
//	virtual RGBColor shadeAreaLight(ShadeRec& sr);
//	virtual RGBColor shadePath(ShadeRec& sr);
	Material();
	virtual ~Material();

};

#endif /* MATERIAL_H_ */
