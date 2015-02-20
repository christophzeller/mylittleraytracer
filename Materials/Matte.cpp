/*
 * Matte.cpp
 *
 *  Created on: 19.02.2015
 *      Author: Christoph
 */

#include "Matte.h"
#include "../Tracing/ShadeRec.h"
#include "../Tracing/World.h"
#include "../Utility/Vector3D.h"

#include <iostream>

RGBColor Matte::shadeRayCast(ShadeRec& sr)
{
	Vector3D w_o = - sr.r.direction;
	RGBColor L = ambient->rho(sr, w_o) * sr.w.ambientLight->L(sr);
	unsigned int numLights = sr.w.lights.size();

	for (unsigned int i = 0; i < numLights; i++)
	{
		Vector3D w_i = sr.w.lights[i]->getDirection(sr);
		float nDotw_i = sr.normal * w_i;

		if (nDotw_i > 0.0)
		{
//			std::cout << "shading stuff" << std::endl;
			L += diffuse->rho(sr, w_o) * sr.w.lights[i]->L(sr) * nDotw_i;
		}
	}

	return L;
}

Matte::Matte()
	: Material()//, ambient(new LambertBRDF), diffuse(new LambertBRDF)
{
	ambient = new LambertBRDF();
	diffuse = new LambertBRDF();

}

Matte::~Matte()
{
	if (ambient)
		delete ambient;

	if (diffuse)
		delete diffuse;
}

