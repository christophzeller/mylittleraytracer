#ifndef __GEOMETRICOBJECT
#define __GEOMETRICOBJECT

#include "../Utility/RGBColor.h"
#include "../Tracing/Ray.h"
#include "../Tracing/ShadeRec.h"

//class Ray;
//class ShadeRec;

class GeometricObject
{
public:
  virtual bool hit(const Ray& ray, double& tMin, ShadeRec& sr) const = 0;

  GeometricObject(void);
  virtual ~GeometricObject(void);

  inline const RGBColor& getColor() { return color; };
  inline void setColor(const RGBColor& newColor) { color = newColor; }

protected:
  RGBColor color;
};

#endif
