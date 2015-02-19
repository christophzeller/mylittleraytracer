#include "Ray.h"

Ray::Ray(const Point3D& origin, const Vector3D& direction)
	: origin(origin), direction(direction)
{
}

Ray::Ray(void)
{
}

Ray::~Ray(void)
{
}

Ray::Ray(const Ray& ray)
{
  origin = ray.origin;
  direction = ray.direction;
}

Ray& Ray::operator=(const Ray& rhs)
{
  this->origin = rhs.origin;
  this->direction = rhs.direction;
  return *this;
  //return Ray(rhs.origin, rhs.direction);
}


std::ostream& operator<<(std::ostream& os, const Ray& r)
{
  os << "Ray direction: " << r.direction << "; Ray Origin: " << r.origin;
  return os;
}
