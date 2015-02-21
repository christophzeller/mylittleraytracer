/*
 * GlossySpecularBRDF.h
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#ifndef GLOSSYSPECULARBRDF_H_
#define GLOSSYSPECULARBRDF_H_

#include "BRDF.h"
#include "../../Utility/RGBColor.h"
#include "../../Utility/Normal.h"
#include "../../Utility/Vector3D.h"
#include "../../Tracing/ShadeRec.h"

class GlossySpecularBRDF: public BRDF
{
public:
	virtual RGBColor f(const ShadeRec& sr, const Vector3D& w_i, const Vector3D& w_o) ;
	virtual RGBColor sampleF(const ShadeRec& sr, Vector3D& w_i, const Vector3D& w_o) ;
	virtual RGBColor rho(const ShadeRec& sr, const Vector3D& w_o) ;
	GlossySpecularBRDF();
	virtual ~GlossySpecularBRDF();

//private:
	float k_specular;
	float exponent;
	RGBColor c_specular;
};

#endif /* GLOSSYSPECULARBRDF_H_ */
