/*
 * Camera.cpp
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#include "Camera.h"
#include "math.h"

const double Camera::kPi = 3.14159265;
const double Camera::kPiInv = 1.0 / 3.14159265;

Camera::Camera(Point3D eye, Point3D target, Vector3D up)
  : eye(eye), target(target), up(up)
{
}

void Camera::computeOrthoNormalBasis()
{
  Vector3D d = eye - target;
    w = d / d.abs();
    u = (up | d) / (up | d).abs();
    v = w | u;
}

Camera::Camera()
  : eye(0, 0, -1), target(0, 0, 0), up(0, 1, 0)
{
}

Camera::~Camera()
{
}

