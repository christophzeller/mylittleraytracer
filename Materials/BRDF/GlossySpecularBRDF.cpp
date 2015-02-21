/*
 * GlossySpecularBRDF.cpp
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#include "GlossySpecularBRDF.h"


RGBColor GlossySpecularBRDF::f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o)
{
	RGBColor L;
	float nDotw_i = sr.normal * w_i;

	Vector3D reflection(-w_i + 2.0 * sr.normal * nDotw_i);

	float rDotw_o = reflection * w_o;

	if (rDotw_o > 0.0)
	{
		L = c_specular * k_specular * pow (rDotw_o, exponent);
	}

	return L;
}

RGBColor GlossySpecularBRDF::sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o)
{
	return RGBColor(0, 0, 0);
}

RGBColor GlossySpecularBRDF::rho(const ShadeRec& sr, const Vector3D& w_o)
{
	return RGBColor(0, 0, 0);
}

GlossySpecularBRDF::GlossySpecularBRDF()
  : k_specular(1.0), exponent(1.0), c_specular(0, 0, 0)
{
}

GlossySpecularBRDF::~GlossySpecularBRDF() {
	// TODO Auto-generated destructor stub
}

