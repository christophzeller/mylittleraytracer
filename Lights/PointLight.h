/*
 * PointLight.h
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.h"
#include "../Utility/Point3D.h"
#include "../Utility/RGBColor.h"
#include "../Tracing/ShadeRec.h"
#include "../Utility/Vector3D.h"

class PointLight : public Light
{
public:
  virtual Vector3D getDirection(ShadeRec& sr);
  virtual RGBColor L(ShadeRec& sr);

  PointLight(const Point3D& location, const RGBColor& color);
  PointLight(const Point3D& location);
  PointLight ();
  virtual
  ~PointLight ();

  RGBColor color;
  float l_scale;
  Point3D location;
};

#endif /* POINTLIGHT_H_ */
