/*
 * ViewPlane.h
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#ifndef __VIEWPLANE
#define __VIEWPLANE

#include "RGBColor.h"
#include <vector>

class ViewPlane
{
public:
	int hRes;
	int vRes;
	float pixelSize;
	float gamma;
	float invGamma;
	int numSamples;

	inline void setHRes(int value) { hRes = value; }
	inline void setVRes(int value) { vRes = value; }
	inline void setGamma(float value) { gamma = value; invGamma = (1.0 / value); }
	inline void setPixelSize(float value) { pixelSize = value; }
	inline void setSamples(int value) { numSamples = value; }

	inline int getSamples() { return numSamples; }

	ViewPlane();
	virtual ~ViewPlane();
};

#endif
