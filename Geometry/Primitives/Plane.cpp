#include "Plane.h"

const double Plane::kEpsilon = 0.0001;

bool Plane::hit(const Ray& ray, double& tMin, ShadeRec& sr) const
{
    double t = (point - ray.origin) * normal / (ray.direction * normal);

    if (t > kEpsilon)
    {
    	tMin = t;
    	sr.normal = normal;
    	sr.localHitPoint = ray.origin + t * ray.direction;
    	return true;
    }
    else
    {
    	return false;
    }
}

Plane::Plane(const Point3D& point, const Normal& normal)
	: point(point), normal(normal)
{
}

Plane::Plane(void) : point(), normal()
{
}


Plane::~Plane(void)
{
}
