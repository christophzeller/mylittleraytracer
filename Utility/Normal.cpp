#include "Normal.h"


Normal::Normal(double x, double y, double z) : x(x), y(y), z(z)
{
}

Normal::Normal(void) : x(0.0), y(0.0), z(1.0)
{
}

Normal Normal::operator+(const Normal& other)
{
  return Normal(this->x + other.x, this->y + other.y, this->z + other.z);
}

Normal Normal::operator-(const Normal& other)
{
  return Normal(this->x - other.x, this->y - other.y, this->z - other.z);
}

Normal operator*(const Normal& lhs, const double rhs)
{
  return Normal((lhs.x * rhs), (lhs.y * rhs),  (lhs.z * rhs));
}

Normal operator*(const double lhs, const Normal& rhs)
{
  return Normal((rhs.x * lhs), (rhs.y * lhs), (rhs.z * lhs));
}

Normal Normal::operator/(const double other)
{
  return Normal(this->x / other, this->y / other, this->z / other);
}

double operator*(const Normal& lhs, const Vector3D& rhs)
{
  return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

double operator*(const Vector3D& lhs, const Normal& rhs)
{
  return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3D operator+(const Normal& lhs, const Vector3D& rhs)
{
	return Vector3D((lhs.x + rhs.x), (lhs.y + rhs.y), (lhs.z + rhs.z));
}

Vector3D operator+(const Vector3D& lhs, const Normal& rhs)
{
  return Vector3D((lhs.x + rhs.x), (lhs.y + rhs.y), (lhs.z + rhs.z));
}

Normal& Normal::operator=(const Normal& other)
{
  x = other.x;
  y = other.y;
  z = other.z;

  return *this;
}

Normal& Normal::operator= (const Vector3D& other)
{
	x = other.x; y = other.y; z = other.z;
	return (*this);
}

Normal& Normal::operator+=(const Normal& other)
{
  x += other.x;
  y += other.y;
  z += other.z;

  return *this;
}


Normal::~Normal(void)
{
}
