/*
 * LambertBRDF.cpp
 *
 *  Created on: 17.02.2015
 *      Author: Christoph
 */

#include "LambertBRDF.h"

RGBColor LambertBRDF::f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o)
{
  //return RGBColor(0, 0, 0);
  return (c_diffuse * (k_diffuse * BRDF::kPiInv));
}

RGBColor LambertBRDF::sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o)
{
  return RGBColor(0, 0, 0);
}

RGBColor LambertBRDF::rho(const ShadeRec& sr, const Vector3D& w_o)
{
  return (c_diffuse * k_diffuse);
}

LambertBRDF::LambertBRDF ()
{
  // TODO Auto-generated constructor stub

}

LambertBRDF::~LambertBRDF ()
{
  // TODO Auto-generated destructor stub
}

