/*
 * RenderTarget.h
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#ifndef RENDERTARGET_H_
#define RENDERTARGET_H_

class RGBColor;
#include "../../Utility/ViewPlane.h"

class RenderTarget
{
public:
	virtual void setUp() = 0;
	virtual void tearDown() = 0;
	virtual void setPixel(int row, int column, const RGBColor& color) = 0;
	RenderTarget(const ViewPlane& vp);
	virtual ~RenderTarget();

protected:
	int rows, columns;
	RGBColor* pixels;
};

#endif /* RENDERTARGET_H_ */
