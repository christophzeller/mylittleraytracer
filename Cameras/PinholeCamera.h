/*
 * PinholeCamera.h
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#ifndef PINHOLECAMERA_H_
#define PINHOLECAMERA_H_

#include "Camera.h"
#include "../Utility/Point3D.h"
#include "../Utility/Vector3D.h"

class World;

class PinholeCamera : public Camera
{
public:
  virtual void renderScene(World& w);
  Vector3D getRayDirection(const Point3D& p) const;

  PinholeCamera(Point3D eye, Point3D target, Vector3D up, float d, float zoom);
  PinholeCamera(Point3D eye, Point3D target, Vector3D up, float fov);
  PinholeCamera();
  virtual ~PinholeCamera ();

private:
  float d;
  float zoom;
  float fov;
};

#endif /* PINHOLECAMERA_H_ */
