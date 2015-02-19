#ifndef __POINT3D
#define __POINT3D

#include "Vector3D.h"
#include <iostream>

class Point3D
{
public:
  Point3D operator+(const Vector3D& rhs) const;
  Point3D operator-(const Vector3D& rhs) const;
  Vector3D operator-(const Point3D& rhs) const;

  //friend operator*
  friend std::ostream& operator<<(std::ostream& os, const Point3D& p);

  Point3D(void);
  Point3D(double x, double y, double z);
  ~Point3D(void);

private:
  double x, y, z;
};

#endif
