/*
 * AmbientLight.cpp
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#include "AmbientLight.h"

Vector3D AmbientLight::getDirection(ShadeRec& sr)
{
  return Vector3D(0, 0, 0);
}

RGBColor AmbientLight::L(ShadeRec& sr)
{
  return (color * l_scale);
}

AmbientLight::AmbientLight ()
  : Light(), color(1, 1, 1), l_scale(1.0)
{
  // TODO Auto-generated constructor stub

}

AmbientLight::~AmbientLight ()
{
  // TODO Auto-generated destructor stub
}

