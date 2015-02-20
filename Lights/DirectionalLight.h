/*
 * DirectionalLight.h
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#ifndef DIRECTIONALLIGHT_H_
#define DIRECTIONALLIGHT_H_

#include "Light.h"
#include "../Utility/Vector3D.h"
#include "../Utility/RGBColor.h"
#include "../Tracing/ShadeRec.h"

class DirectionalLight: public Light
{
public:
	virtual Vector3D getDirection(ShadeRec& sr);
	virtual RGBColor L(ShadeRec& sr);

	DirectionalLight(const Vector3D& direction, const RGBColor& color);
	DirectionalLight(const Vector3D& direction);
	DirectionalLight();
	virtual ~DirectionalLight();

	Vector3D direction;
	RGBColor color;
	float l_scale;
};

#endif /* DIRECTIONALLIGHT_H_ */
