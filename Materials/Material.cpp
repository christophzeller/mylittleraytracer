/*
 * Material.cpp
 *
 *  Created on: 19.02.2015
 *      Author: Christoph
 */

#include "Material.h"

RGBColor Material::shadeRayCast(ShadeRec& sr)
{
	return RGBColor(0, 0, 0);
}

RGBColor Material::shadeWhitted(ShadeRec& sr)
{
	return RGBColor(0, 0, 0);
}

Material::Material() {
	// TODO Auto-generated constructor stub

}

Material::~Material() {
	// TODO Auto-generated destructor stub
}

