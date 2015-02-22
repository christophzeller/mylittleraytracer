/*
 * PinholeCamera.cpp
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#include "PinholeCamera.h"
#include "../Tracing/World.h"
#include "../Tracing/Ray.h"

#include <fstream>
#include <math.h>

void PinholeCamera::renderScene(World& wr)
{
	// pi / 180 * alpha = radian

	computeOrthoNormalBasis();

	ViewPlane vp(wr.vp);
	RGBColor pixelColor;
	Ray ray;

	// calculate distance to view plane.
	// view plane is 1 unit across, so 1/2 unit wide if split into
	// two triangles with gamma = 90°.
	double fovRadians = Camera::kPi / 180 * fov;
	double f = (1.0 / tan(fovRadians / 2.0)) * 0.5;

	//Point3D vpOrigin = (eye + (-w) * f); // center
	//vpOrigin += (0.5 * (-u)) + (0.5 * (-v)); // center to bottom left

	Point3D vpOrigin = (eye + (-w) * f) + (0.5 * (-u)) + (0.5 * (-v));
	std::cout << vpOrigin << std::endl;

	ray.origin = eye;

//	int n = (int)sqrt((float)vp.getSamples());
//	Point3D samplePoint = Point3D(0, 0, 0);

	renderTarget->setUp();

	for (int i = 0; i < vp.vRes; i++) // rows
	{
	  std::cout << "processing row " << i << " of " << vp.vRes << std::endl;
	  for (int j = 0; j < vp.hRes; j++) // columns
	  {
		  pixelColor = RGBColor(0, 0, 0); // initially black.


		  // TODO: set on pixel center.
		  Point3D pixelCenter = vpOrigin +
				  (u * (((double)j / (double)vp.hRes))) + // + (0.5 * vp.pixelSize))) +
				  (v * (((double)i / (double)vp.vRes))); // + (0.5 * vp.pixelSize)));
//				  (u * 0.5 * vp.pixelSize)
//				  (v * 0.5 * vp.pixelSize)


//				   (u * (j / vp.hRes) + (0.5 * vp.pixelSize)) +
//				   (v * (i / vp.vRes) + (0.5 * vp.pixelSize));

//		  pixelCenter = vpOrigin +


		  Vector3D d = (pixelCenter - eye);
		  d.normalize();
		  ray.direction = d;

//		  std::cout << ray.direction << std::endl;

		  pixelColor += wr.tracer->traceRay(ray);

//		  for (int pixelY = 0; pixelY < n; pixelY++)
//		  {
//			  for (int pixelX = 0; pixelX < n; pixelX++)
//			  {
//				  //samplePoint.x = vp.pixelSize * (j - 0.5 * vp.hRes + (pixelX + 0.5) / n);
//				  //samplePoint.y = vp.pixelSize * (i - 0.5 * vp.vRes + (pixelY + 0.5) / n);
//				  //ray.origin = Point3D(samplePoint.x, samplePoint.y, zw);
//
//				  double sampleX = vp.pixelSize * (j - 0.5 * vp.hRes + (pixelX + 0.5) / n);
//				  double sampleY = vp.pixelSize * (i - 0.5 * vp.vRes + (pixelY + 0.5) / n);
//
//				  ray.origin = Point3D(sampleX, sampleY, 10.0);
//				  pixelColor += wr.tracer->traceRay(ray);
//			  }
//		  }
		  //std::cout << pixelCenter << std::endl;
//		  std::cout << ray.direction << std::endl;
		  //pixelColor /= vp.getSamples();
		  renderTarget->setPixel(i, j, pixelColor);
	  }
	}

	renderTarget->tearDown();

	std::cout << "finished" << std::endl;
}

Vector3D PinholeCamera::getRayDirection(const Point3D& p) const
{
  return Vector3D(0,0,0);
}

PinholeCamera::PinholeCamera(Point3D eye, Point3D target, Vector3D up, float fov)
  : Camera(eye, target, up), d(0.0), zoom(0.0), fov(fov)
{

}

PinholeCamera::PinholeCamera(Point3D eye, Point3D target, Vector3D up, float d, float zoom)
  : Camera(eye, target, up), d(d), zoom(zoom), fov(70.0)
{

}

PinholeCamera::PinholeCamera ()
{
  // TODO Auto-generated constructor stub

}

PinholeCamera::~PinholeCamera ()
{
  // TODO Auto-generated destructor stub
}

