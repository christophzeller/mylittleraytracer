/*
 * LambertBRDF.h
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#ifndef LAMBERTBRDF_H_
#define LAMBERTBRDF_H_

#include "BRDF.h"
#include "../../Utility/RGBColor.h"
#include "../../Utility/Normal.h"
#include "../../Utility/Vector3D.h"
#include "../../Tracing/ShadeRec.h"

class LambertBRDF : public BRDF
{
public:
  virtual RGBColor f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o) ;
  virtual RGBColor sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o) ;
  virtual RGBColor rho(const ShadeRec& sr, const Vector3D& w_o) ;

  LambertBRDF ();
  virtual
  ~LambertBRDF ();

//private:
  float k_diffuse;
  RGBColor c_diffuse;
};

#endif /* LAMBERTBRDF_H_ */
