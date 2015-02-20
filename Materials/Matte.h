/*
 * Matte.h
 *
 *  Created on: 19.02.2015
 *      Author: Christoph
 */

#ifndef MATTE_H_
#define MATTE_H_

#include "Material.h"
#include "BRDF/LambertBRDF.h"
#include "../Utility/RGBColor.h"

class ShadeRec;

class Matte: public Material {
public:
	inline void setK_a(const float k) { ambient->k_diffuse = k; }
	inline void setK_d(const float k) { diffuse->k_diffuse = k; }
	inline void setC_d(const RGBColor& c) { ambient->c_diffuse = c; diffuse->c_diffuse = c; }

	virtual RGBColor shadeRayCast(ShadeRec& sr);

	Matte();
	virtual ~Matte();

private:
	LambertBRDF* ambient;
	LambertBRDF* diffuse;
};

#endif /* MATTE_H_ */
