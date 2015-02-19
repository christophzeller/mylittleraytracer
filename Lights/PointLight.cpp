/*
 * PointLight.cpp
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#include "PointLight.h"

Vector3D PointLight::getDirection(ShadeRec& sr)
{
  return (location - sr.hitPoint).hat();
}

RGBColor PointLight::L(ShadeRec& sr)
{
  return (color * l_scale);
}

PointLight::PointLight ()
  : Light(), color(1, 1, 1), l_scale(1.0)
{
  // TODO Auto-generated constructor stub

}

PointLight::~PointLight ()
{
  // TODO Auto-generated destructor stub
}

