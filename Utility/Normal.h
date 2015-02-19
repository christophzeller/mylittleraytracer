#ifndef __NORMAL
#define __NORMAL

#include "Vector3D.h"

class Normal
{
public:

  Normal operator+(const Normal& other);
  Normal operator-(const Normal& other);

  Normal operator/(const double other);

  Normal& operator=(const Normal& other);
  Normal& operator=(const Vector3D& other);

  Normal& operator+=(const Normal& other);

  Normal(double x, double y, double z);
  Normal(void);
  ~Normal(void);

  friend Normal operator*(const Normal& lhs, const double rhs);
  friend Normal operator*(const double lhs, const Normal& rhs);

  friend double operator*(const Normal& lhs, const Vector3D& rhs);
  friend double operator*(const Vector3D& lhs, const Normal& rhs);

  friend Vector3D operator+(const Normal& lhs, const Vector3D& rhs);
  friend Vector3D operator+(const Vector3D& lhs, const Normal& rhs);

public:
  double x, y, z;
};

#endif
