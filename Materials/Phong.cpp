/*
 * Phong.cpp
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#include "Phong.h"
#include "../Tracing/ShadeRec.h"
#include "../Tracing/World.h"
#include "../Utility/Vector3D.h"


RGBColor Phong::shadeRayCast(ShadeRec& sr)
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
			L += (diffuse->f(sr, w_o, w_i) + specular->f(sr, w_o, w_i))
					* sr.w.lights[i]->L(sr) * nDotw_i;
		}
	}

	return L;
}

Phong::Phong()
  : Material()
{
	ambient = new LambertBRDF();
	diffuse = new LambertBRDF();
	specular = new GlossySpecularBRDF();
}

Phong::~Phong()
{
	if (ambient)
		delete ambient;

	if (diffuse)
		delete diffuse;

	if (specular)
		delete specular;
}

