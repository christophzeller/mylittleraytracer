/*
 * PPMASCIITarget.h
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#ifndef PPMASCIITARGET_H_
#define PPMASCIITARGET_H_

#include "RenderTarget.h"
#include "../../Utility/RGBColor.h"
#include <fstream>

class ViewPlane;

class PPMASCIITarget: public RenderTarget
{
public:
	virtual void setUp();
	virtual void tearDown();
	virtual void setPixel(int row, int column, const RGBColor& color);

	PPMASCIITarget(const ViewPlane& vp, const char* filePath);
	PPMASCIITarget(const ViewPlane& vp);
	virtual ~PPMASCIITarget();

	std::fstream outputFile;
	const char* filePath;
	int colorSteps;
};

#endif /* PPMASCIITARGET_H_ */
