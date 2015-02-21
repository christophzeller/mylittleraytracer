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
#include <math.h>

void OrthographicCamera::renderScene(World& w)
{
  ViewPlane vp(w.vp);
  RGBColor pixelColor;
  Ray ray;
  double zw = 100.0; // hard-coded camera position along the z-axis
  //double x, y;

  int n = (int)sqrt((float)vp.getSamples());
  Point3D samplePoint = Point3D(0, 0, 0);

  ray.direction = Vector3D(0,0,-1);

  renderTarget->setUp();

  for (int i = 0; i < vp.vRes; i++) // rows
  {
	  std::cout << "processing row " << i << " of " << vp.vRes << std::endl;
	  for (int j = 0; j < vp.hRes; j++) // columns
	  {
		  pixelColor = RGBColor(0, 0, 0); // initially black.

		  for (int pixelY = 0; pixelY < n; pixelY++)
		  {
			  for (int pixelX = 0; pixelX < n; pixelX++)
			  {
				  //samplePoint.x = vp.pixelSize * (j - 0.5 * vp.hRes + (pixelX + 0.5) / n);
				  //samplePoint.y = vp.pixelSize * (i - 0.5 * vp.vRes + (pixelY + 0.5) / n);
				  //ray.origin = Point3D(samplePoint.x, samplePoint.y, zw);

				  double sampleX = vp.pixelSize * (j - 0.5 * vp.hRes + (pixelX + 0.5) / n);
				  double sampleY = vp.pixelSize * (i - 0.5 * vp.vRes + (pixelY + 0.5) / n);

				  ray.origin = Point3D(sampleX, sampleY, zw);
				  pixelColor += w.tracer->traceRay(ray);
			  }
		  }

		  pixelColor /= vp.getSamples();
		  renderTarget->setPixel(i, j, pixelColor);
	  }
  }

  renderTarget->tearDown();

  std::cout << "finished" << std::endl;
}

OrthographicCamera::OrthographicCamera ()
{
}

OrthographicCamera::~OrthographicCamera ()
{
}

