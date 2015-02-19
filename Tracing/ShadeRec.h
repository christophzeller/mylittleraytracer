#ifndef __SHADEREC
#define __SHADEREC

#include "../Utility/RGBColor.h"
#include "../Utility/Normal.h"
#include "../Utility/Point3D.h"
#include "../Tracing/Ray.h"
//#include "World.h"

class World;

class ShadeRec
{
public:
  bool isObjectHit;
  Point3D hitPoint;
  Point3D localHitPoint;
  Normal normal;
  RGBColor color;
  World& w;

  Ray r;
  int recursionDepth;
  Vector3D direction;

  double t; // ?

  //Material* material;

  ShadeRec(World& wr);
//  ShadeRec(const ShadeRec& other);
  ~ShadeRec(void);

  ShadeRec& operator=(const ShadeRec& rhs);
};

#endif
