/*
 * Light.h
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "../Utility/RGBColor.h"
#include "../Utility/Vector3D.h"

class ShadeRec;

class Light
{
public:
  virtual Vector3D getDirection(ShadeRec& sr) = 0;
  virtual RGBColor L(ShadeRec& sr) = 0;

  Light ();
  virtual
  ~Light ();

protected:

  bool shadows;
};

#endif /* LIGHT_H_ */
