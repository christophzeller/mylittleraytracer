/*
 * Sphere.h
 *
 *  Created on: 13.02.2015
 *      Author: Christoph
 */
#ifndef __SPHERE
#define __SPHERE

#include "../GeometricObject.h"
#include "../../Utility/Point3D.h"
#include "../../Utility/RGBColor.h"

class ShadeRec;
class Ray;

class Sphere : public GeometricObject
{
public:
	virtual bool hit(const Ray& ray, double& tMin, ShadeRec& sr) const;
	Sphere(const Point3D& center, const double radius);
	Sphere();
	virtual ~Sphere();

	inline void setRadius(double r) { radius = r; }
	inline void setCenter(const Point3D& p) { center = p; }

//	inline void setColor(const RGBColor& newColor) { color = newColor; }
//	inline RGBColor& getColor() { return color; }


private:
//	RGBColor color;
	Point3D center;
	double radius;
	static const double kEpsilon;
};

#endif
