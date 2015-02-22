/*
 * Camera.h
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../Utility/Point3D.h"
#include "../Utility/Vector3D.h"
#include "../Utility/ViewPlane.h"
#include "../Tracing/Tracer.h"
#include "RenderTargets/RenderTarget.h"

class World;

class Camera
{
public:
  Camera(Point3D eye, Point3D target, Vector3D up);
  Camera();
  virtual ~Camera();

  inline void setRenderTarget(RenderTarget* t) { renderTarget = t; }

  virtual void renderScene(World& w) = 0;
  void computeOrthoNormalBasis();

protected:
  Point3D eye, target;
  Vector3D up;

  // right, up, forward
  Vector3D u, v, w;
  RenderTarget* renderTarget;

  static const double kPi;
  static const double kPiInv;
};

#endif /* CAMERA_H_ */
