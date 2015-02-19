#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z)
{
}

Vector3D::Vector3D(void) : x(0.0), y(0.0), z(0.0)
{
}

double Vector3D::abs() const
{
	return sqrt(x*x + y*y + z*z);
}

double Vector3D::abs2() const
{
	return (x*x + y*y + z*z);
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
  return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
  return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

double Vector3D::operator*(const Vector3D& other) const
{
  return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

Vector3D Vector3D::operator/(const double other) const
{
  return Vector3D(this->x / other, this->y / other, this->z / other);
}

Vector3D Vector3D::operator-() const
{
	return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator|(const Vector3D& rhs) const
{
	return Vector3D(
				(y * rhs.z) - (z * rhs.y),
				(z * rhs.x) - (x * rhs.z),
				(x * rhs.y) - (y * rhs.x)
			);
}

Vector3D& Vector3D::operator=(const double other)
{
  x = other;
  y = other;
  z = other;

  return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& other)
{
  x = other.x;
  y = other.y;
  z = other.z;

  return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& other)
{
  x += other.x;
  y += other.y;
  z += other.z;

  return *this;
}

void Vector3D::normalize()
{
  double l = sqrt(x*x + y*y + z*z);
  x /= l;
  y /= l;
  z /= l;
}

Vector3D& Vector3D::hat()
{
  this->normalize();
  return (*this);
}

Vector3D::~Vector3D(void)
{
}


Vector3D operator*(const double lhs, const Vector3D& rhs)
{
  return Vector3D((rhs.x * lhs), (rhs.y * lhs), (rhs.z * lhs));
}

Vector3D operator*(const Vector3D& lhs, const double rhs)
{
  return Vector3D((lhs.x * rhs), (lhs.y * rhs), (lhs.z * rhs));

}


std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
  os << "(" << v.x << ";" << v.y << ";" << v.z << ")";
  return os;
}
