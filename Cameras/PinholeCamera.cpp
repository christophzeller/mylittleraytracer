/*
 * PinholeCamera.cpp
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#include "PinholeCamera.h"

void PinholeCamera::renderScene(World& w)
{

}

Vector3D PinholeCamera::getRayDirection(const Point3D& p) const
{
  return Vector3D(0,0,0);
}

PinholeCamera::PinholeCamera(Point3D eye, Point3D target, Vector3D up, float d, float zoom)
  : Camera(eye, target, up)//, d(d), zoom(zoom)
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

