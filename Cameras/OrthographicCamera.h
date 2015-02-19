/*
 * OrthographicCamera.h
 *
 *  Created on: 16.02.2015
 *      Author: Christoph
 */

#ifndef ORTHOGRAPHICCAMERA_H_
#define ORTHOGRAPHICCAMERA_H_

#include "Camera.h"
#include "../Tracing/World.h"

class OrthographicCamera : public Camera
{
public:
  virtual void renderScene(World& w);


  OrthographicCamera ();
  virtual ~OrthographicCamera ();
};

#endif /* ORTHOGRAPHICCAMERA_H_ */
