/*
 * PerfectSpecularBRDF.cpp
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#include "PerfectSpecularBRDF.h"

RGBColor PerfectSpecularBRDF::f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o)
{
	return RGBColor(0, 0, 0);
}

RGBColor PerfectSpecularBRDF::sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o)
{
	return RGBColor(0, 0, 0);
}

RGBColor PerfectSpecularBRDF::rho(const ShadeRec& sr, const Vector3D& w_o)
{
	return RGBColor(0, 0, 0);
}

PerfectSpecularBRDF::PerfectSpecularBRDF()
{
	// TODO Auto-generated constructor stub

}

PerfectSpecularBRDF::~PerfectSpecularBRDF()
{
	// TODO Auto-generated destructor stub
}

