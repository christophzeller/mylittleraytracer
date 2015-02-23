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

void OrthographicCamera::renderScene(World& wr)
{
  ViewPlane vp(wr.vp);
  RGBColor pixelColor;
  Ray ray;
  double zw = 100.0; // hard-coded camera position along the z-axis
  //double x, y;

  computeOrthoNormalBasis();

  int n = (int)sqrt((float)vp.getSamples());
  Point3D samplePoint = Point3D(0, 0, 0);

  //ray.direction = Vector3D(0,0,-1);
  ray.direction = -w;

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
				  Point3D o = eye
						  + ((vp.pixelSize * (j - 0.5 * vp.hRes + (pixelX + 0.5) / n)) * (u))
						  + ((vp.pixelSize * (i - 0.5 * vp.vRes + (pixelY + 0.5) / n)) * (v))
						  ;
				  ray.origin = o;
				  pixelColor += wr.tracer->traceRay(ray);
			  }
		  }

		  pixelColor /= vp.getSamples();
		  renderTarget->setPixel(i, j, pixelColor);
	  }
  }

  renderTarget->tearDown();

  std::cout << "finished" << std::endl;
}

OrthographicCamera::OrthographicCamera (Point3D eye, Point3D target, Vector3D up)
  : Camera(eye, target, up)
{

}

OrthographicCamera::OrthographicCamera ()
  : Camera(Point3D(0,0,100), Point3D(0,0,0), Vector3D(0,1,0))
{
}

OrthographicCamera::~OrthographicCamera ()
{
}

