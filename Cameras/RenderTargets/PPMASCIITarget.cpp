/*
 * PPMASCIITarget.cpp
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#include "PPMASCIITarget.h"


void PPMASCIITarget::setUp()
{
	outputFile.open(filePath, std::ios_base::out | std::ios_base::trunc );
	outputFile << "P3\n" << columns << " " << rows << "\n" << colorSteps << "\n";
	pixels = new RGBColor[rows * columns];
}

void PPMASCIITarget::tearDown()
{
	// TODO: output may need its own method...
	for (int i = 0; i < rows * columns; i++)
	{
		if (i % (columns) == 0)
			outputFile << "\n";

		outputFile << (int)(pixels[i].getR() * colorSteps) << " "
				<< (int)(pixels[i].getG() * colorSteps) << " "
				<< (int)(pixels[i].getB() * colorSteps) << " ";
	}
	delete[] pixels;
	outputFile.flush();
	outputFile.close();
}

void PPMASCIITarget::setPixel(int row, int column, const RGBColor& color)
{
	// origin in .ppm is top left, but bottom left in the ray tracer.
	// hence the rows need to be reversed in order to display a non-
	// flipped (vertically) image.

	pixels[((rows - row - 1) * columns) + column] = color;

//	outputFile << (int)(color.getR() * colorSteps) << " "
//			<< (int)(color.getG() * colorSteps) << " "
//			<< (int)(color.getB() * colorSteps) << " ";
//	if (column == (columns - 1))
//	{
//		outputFile << "\n";
//	}
}

PPMASCIITarget::PPMASCIITarget(const ViewPlane& vp, const char* filePath)
  : RenderTarget(vp), filePath(filePath), colorSteps(255)
{
}

PPMASCIITarget::PPMASCIITarget(const ViewPlane& vp)
  : RenderTarget(vp), filePath("output.ppm"), colorSteps(255)
{
}

PPMASCIITarget::~PPMASCIITarget() {
	// TODO Auto-generated destructor stub
}

