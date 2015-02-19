#ifndef __VECTOR3D
#define __VECTOR3D

#include <iostream>
#include <math.h>

class Vector3D
{
public:
  Vector3D(void);
  Vector3D(double x, double y, double z);
  ~Vector3D(void);

  double abs() const;
  double abs2() const;

  void normalize();
  Vector3D& hat();

  Vector3D operator-() const;

  Vector3D operator+(const Vector3D& other) const;
  Vector3D operator-(const Vector3D& other) const;
  Vector3D operator/(const double other) const;
  Vector3D operator|(const Vector3D& rhs) const;

  double operator*(const Vector3D& other) const;

  Vector3D& operator=(const double other);
  Vector3D& operator=(const Vector3D& other);
  Vector3D& operator+=(const Vector3D& other);

  friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);
  friend Vector3D operator*(const double lhs, const Vector3D& rhs);
  friend Vector3D operator*(const Vector3D& lhs, const double rhs);

public:
  double x, y, z;

};

#endif
