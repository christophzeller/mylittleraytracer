/*
 * OrthographicCamera.cpp
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#include "OrthographicCamera.h"
#include "../Tracing/World.h"
#include "../Tracing/Ray.h"

#include <fstream>

void OrthographicCamera::renderScene(World& w)
{
  ViewPlane vp(w.vp);
  RGBColor pixelColor;
  Ray ray;
  double zw = 100.0;
  double x, y;

  ray.direction = Vector3D(0,0,-1);

  //std::ofstream outputFile;
  //outputFile.open("shaded.ppm", std::ios_base::out | std::ios_base::trunc );
  //outputFile << "P3\n" << vp.hRes << " " << vp.vRes << "\n255 \n";
  renderTarget->setUp();

  for (int i = 0; i < vp.vRes; i++) // rows
  {
	  for (int j = 0; j < vp.hRes; j++) // columns
	  {
		  x = vp.pixelSize * (j - 0.5 * (vp.hRes - 1.0));
		  y = vp.pixelSize * (i - 0.5 * (vp.vRes - 1.0));

		  ray.origin = Point3D(x, y, zw);
		  pixelColor = w.tracer->traceRay(ray);
		  //paintPixel(i, j, pixelColor);

		  renderTarget->setPixel(i, j, pixelColor);

		  //outputFile << pixelColor << " ";
	  }
	  //outputFile << "\n";
  }

  //std::cout << "hits: " << hitCount << std::endl << "pixels: " << vp.vRes * vp.hRes;

  //outputFile.flush();
  //outputFile.close();

  renderTarget->tearDown();

  std::cout << "finished" << std::endl;
}

OrthographicCamera::OrthographicCamera ()
{
  // TODO Auto-generated constructor stub

}

OrthographicCamera::~OrthographicCamera ()
{
  // TODO Auto-generated destructor stub
}

