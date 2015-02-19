/*
 * AmbientLight.h
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#ifndef AMBIENTLIGHT_H_
#define AMBIENTLIGHT_H_

#include "Light.h"
#include "../Utility/RGBColor.h"
#include "../Utility/Vector3D.h"
#include "../Tracing/ShadeRec.h"

class AmbientLight : public Light
{
public:
  virtual Vector3D getDirection(ShadeRec& sr);
  virtual RGBColor L(ShadeRec& sr);

  AmbientLight ();
  virtual
  ~AmbientLight ();

  RGBColor color;
  float l_scale;
};

#endif /* AMBIENTLIGHT_H_ */
