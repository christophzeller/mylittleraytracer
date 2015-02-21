/*
 * PerfectSpecularBRDF.h
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#ifndef PERFECTSPECULARBRDF_H_
#define PERFECTSPECULARBRDF_H_

#include "BRDF.h"

class PerfectSpecularBRDF: public BRDF
{
public:
	virtual RGBColor f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o) ;
	virtual RGBColor sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o) ;
	virtual RGBColor rho(const ShadeRec& sr, const Vector3D& w_o) ;
	PerfectSpecularBRDF();
	virtual ~PerfectSpecularBRDF();

private:
	float k_reflection;
	float exponent;
};

#endif /* PERFECTSPECULARBRDF_H_ */
