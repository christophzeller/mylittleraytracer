/*
 * Sphere.cpp
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */

#include "Sphere.h"

const double Sphere::kEpsilon = 0.0001;

bool Sphere::hit(const Ray& ray, double& tMin, ShadeRec& sr) const
{
	double t;
	Vector3D temp = ray.origin - center;
	double a = ray.direction * ray.direction;
	double b = 2.0 * temp * ray.direction;
	double c = temp * temp - radius * radius;
	double disc = b * b - 4.0 * a * c;

	if (disc < 0.0)
	{
		return false;
	}
	else
	{
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;

		if (t > kEpsilon)
		{
			tMin = t;
			sr.normal = (temp + t * ray.direction) / radius;
			sr.localHitPoint = ray.origin + t * ray.direction;
			return true;
		}

		t = (-b + e) / denom;

		if (t > kEpsilon)
		{
			tMin = t;
			sr.normal = (temp + t * ray.direction) / radius;
			sr.localHitPoint = ray.origin + t * ray.direction;
			return true;
		}
	}
	return false;
}

Sphere::Sphere(const Point3D& center, const double radius)
	:  center(center), radius(radius)
{
	setColor(RGBColor(0.0, 0.2, 0.8));
}

Sphere::Sphere() : center(0, 0, 0), radius(1)
{
	setColor(RGBColor(0.0, 0.2, 0.8));
}

Sphere::~Sphere()
{
	// TODO Auto-generated destructor stub
}

