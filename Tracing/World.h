#ifndef __WORLD
#define __WORLD

#include "../Cameras/Camera.h"
#include "../Cameras/OrthographicCamera.h"
#include "../Utility/RGBColor.h"
#include "../Utility/ViewPlane.h"
#include "../Geometry/GeometricObject.h"
#include "../Geometry/Primitives/Sphere.h"
//#include "../Tracing/SingleSphereTracer.h"
//#include "../Tracing/MultiObjectsTracer.h"
#include "../Lights/Light.h"
#include "../Lights/AmbientLight.h"
#include "../Lights/PointLight.h"
#include "ShadeRec.h"

#include <iostream>
#include <vector>

//class Camera;
class Tracer;

class World
{
public:
  Camera* camera;
  Tracer* tracer;
  Light* ambientLight;

  void build();
  void render(); //const;
  void paintPixel(const int row, const int column, const RGBColor& color) const;
  ShadeRec hitObjects(const Ray& ray); //const;

  World(void);
  ~World(void);

//private:
  RGBColor backgroundColor;
  Sphere sphere;
  ViewPlane vp;
  std::vector<GeometricObject*> objects;
  std::vector<Light*> lights;

  const static double kHugeValue;
};

#endif
