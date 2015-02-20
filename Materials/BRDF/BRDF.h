/*
 * BRDF.h
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#ifndef BRDF_H_
#define BRDF_H_

#include "../../Utility/Normal.h"
#include "../../Utility/RGBColor.h"

class ShadeRec;
class Vector3D;


class BRDF
{
public:
  virtual RGBColor f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o)  = 0;
  virtual RGBColor sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o)  = 0;
  virtual RGBColor rho(const ShadeRec& sr, const Vector3D& w_o)  = 0;

  BRDF ();
  virtual ~BRDF ();

protected:
  static const double kPiInv;

private:
  Normal n;
};

#endif /* BRDF_H_ */
