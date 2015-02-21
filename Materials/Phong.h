/*
 * Phong.h
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#ifndef PHONG_H_
#define PHONG_H_

#include "Material.h"
#include "BRDF/LambertBRDF.h"
#include "BRDF/GlossySpecularBRDF.h"
#include "../Utility/RGBColor.h"

class Phong: public Material
{
public:
	inline void setK_a(const float k) { ambient->k_diffuse = k; }
	inline void setK_d(const float k) { diffuse->k_diffuse = k; }
	inline void setC_d(const RGBColor& c) { ambient->c_diffuse = c; diffuse->c_diffuse = c; }

	inline void setK_s(const float k) { specular->k_specular = k; }
	inline void setC_s(const RGBColor& c) { specular->c_specular = c; }
	inline void setSpecularExponent(const float e) { specular->exponent = e; }

	virtual RGBColor shadeRayCast(ShadeRec& sr);
	Phong();
	virtual ~Phong();

private:
	LambertBRDF* ambient;
	LambertBRDF* diffuse;
	GlossySpecularBRDF* specular;
};

#endif /* PHONG_H_ */
