#include "Point3D.h"

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z)
{
}

Point3D::Point3D(void) : x(0), y(0), z(0)
{
}

Point3D::~Point3D(void)
{
}

Point3D Point3D::operator+(const Vector3D& rhs) const
{
	return Point3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

Point3D Point3D::operator-(const Vector3D& rhs) const
{
	return Point3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3D Point3D::operator-(const Point3D& rhs) const
{
  return Vector3D(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

std::ostream& operator<<(std::ostream& os, const Point3D& p)
  {
    os << "(" << p.x << ";" << p.y << ";" << p.z << ")";
    return os;
  }
