#ifndef __RAY
#define __RAY

#include "../Utility/Vector3D.h"
#include "../Utility/Point3D.h"
#include <iostream>

class Ray
{
public:
  Point3D origin;
  Vector3D direction;


  friend std::ostream& operator<<(std::ostream& os, const Ray& r);

  Ray(const Point3D& origin, const Vector3D& direction);
  Ray(const Ray& ray);
  Ray& operator=(const Ray& rhs);
  Ray(void);
  ~Ray(void);
};

#endif
