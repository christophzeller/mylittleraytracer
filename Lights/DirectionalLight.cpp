/*
 * DirectionalLight.cpp
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#include "DirectionalLight.h"

Vector3D DirectionalLight::getDirection(ShadeRec& sr)
{
	return direction;
}

RGBColor DirectionalLight::L(ShadeRec& sr)
{
	return color * l_scale;
}

DirectionalLight::DirectionalLight(const Vector3D& direction, const RGBColor& color)
  : Light(), direction(direction), color(color), l_scale(1.0)
{

}

DirectionalLight::DirectionalLight(const Vector3D& direction)
  : Light(), direction(direction), color(1, 1, 1), l_scale(1.0)
{

}

DirectionalLight::DirectionalLight()
  : Light(), direction(0, -1, 0), l_scale(1.0)
{
	// TODO Auto-generated constructor stub

}

DirectionalLight::~DirectionalLight()
{
	// TODO Auto-generated destructor stub
}

